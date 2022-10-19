#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <map>
#include <queue>
#include <cstring>

using namespace std;

const int INF = 1e8;
const int MAX_N = 100007, MAX_X = 200007;
int n, maxx = -1, curI;
int ax[MAX_N], ay[MAX_N], bx[MAX_N], by[MAX_N], prv[MAX_N];

vector< pair<int, int> > preRows[MAX_X];
vector<int> rows[MAX_X];
int nxtI[MAX_X];
queue<int> cards;

int add(int r)
{
    if (nxtI[r] >= (int)preRows[r].size()) {
        return INF;
    }
    cards.push(preRows[r][nxtI[r]].second);
    prv[preRows[r][nxtI[r]].second] = curI;
    //cerr << "add: " << curI << " -> " << preRows[r][nxtI[r]].second << endl;
    ++nxtI[r];
    return (nxtI[r] < (int)preRows[r].size()) ? preRows[r][nxtI[r]].first : INF;
}

void wrong()
{
    printf("-1");
    exit(0);
}

struct Tree
{
    int n; vector<int> a, mn;

    Tree() {}
    Tree(vector<int> tmp)
    {
        n = tmp.size() - 1;
        a.assign(4*n, INF);
        mn.assign(4*n, INF);
        build(1, 1, n, tmp);
//        cerr << "R" << mn[1] << endl;
    }

    void build(int root, int lo, int hi, vector<int>& tmp)
    {
        if (lo == hi) {
            a[root] = mn[root] = tmp[lo];
            return;
        }
		int m = (lo + hi) >> 1;
        build(root<<1, lo, m, tmp);
        build(root<<1|1, m+1, hi, tmp);
        mn[root] = min(mn[root<<1], mn[root<<1|1]);
    }

    void update(int root, int lo, int hi, int l, int r, int val)
    {
    	if (r < lo || hi < l) return;
        if (mn[root] > val) return;
        if (lo == hi) {
//            cerr << "S" << lo << ' ' << mn[root] << ": " << '(' << l << " -> " << r << "): " << endl;
            while ((a[root] = add(lo)) <= val);
			mn[root] = a[root];
			//cerr << "mn " << lo << ' ' << hi << ": " << mn[root] << endl;
			return;
        }
		int m = (lo + hi) >> 1;
        update(root<<1, lo, m, l, r, val);
        update(root<<1|1, m+1, hi, l, r, val);
        mn[root] = min(mn[root<<1], mn[root<<1|1]);
        //cerr << "mn " << lo << ' ' << hi << ": " << mn[root] << endl;
    }
};

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> ax[i] >> ay[i] >> bx[i] >> by[i];

	// compress
    vector<int> tmp(2*n);
    for (int i = 0; i < n; ++i) {
        tmp[i] = ax[i];
        tmp[i+n] = bx[i];
    }
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    map<int, int> conv;
    for (int i = 0; i < (int)tmp.size(); ++i) {
        conv[tmp[i]] = i+1;
    }
    for (int i = 0; i < n; ++i) {
        ax[i] = conv[ax[i]];
        bx[i] = conv[bx[i]];
    }
    if ((*conv.begin()).first != 0) wrong();

    tmp.resize(2*n);
    for (int i = 0; i < n; ++i) {
        tmp[i] = ay[i];
        tmp[i+n] = by[i];
    }
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    conv.clear();
    for (int i = 0; i < (int)tmp.size(); ++i) {
        conv[tmp[i]] = i+1;
    }
    for (int i = 0; i < n; ++i) {
        ay[i] = conv[ay[i]];
        by[i] = conv[by[i]];
    }
    if ((*conv.begin()).first != 0) wrong();

//    for (int i = 0; i < n; ++i) cerr << ax[i] << ' ' << ay[i] << ' ' << bx[i] << ' ' << by[i] << endl;
//	cerr << endl;

	// have fun :)
    for (int i = 0; i < n; ++i) {
        preRows[ ax[i] ].push_back(make_pair(ay[i], i));
    }
    int maxX = -1;
    for (int x = 1; x < MAX_X; ++x) {
        if (preRows[x].size() == 0) continue;
        sort(preRows[x].begin(), preRows[x].end());
        maxX = x;
    }

    tmp.assign(maxX + 1, INF);
    for (int x = 1; x <= maxX; ++x) {
        if (preRows[x].size()) tmp[x] = preRows[x][0].first;
        //cerr << x << ": ";
        //for (pair<int, int> p : preRows[x]) cerr << '(' << p.first << ", " << p.second << "); ";
        //cerr << endl;
    }
    //cerr << endl;

    memset(nxtI, 0, sizeof nxtI);
    for (int i = 0; i < MAX_N; ++i) prv[i] = -INF;
    Tree tree(tmp);
    int treeMax = tmp.size() - 1;

    curI = -1;
//    cerr << "___________________" << endl;
    tree.update(1, 1, treeMax, 1, 1, 1);
//    cerr << "___________________" << endl;
    while (!cards.empty()) {
        curI = cards.front(); cards.pop();
        //cerr << "curI : " << curI << endl;
        tree.update(1, 1, treeMax, 1, bx[curI], by[curI]);
        //cerr << endl;
    }

    if (prv[n-1] == -INF) wrong();

    vector<int> ans;
    ans.push_back(n-1);


    int nxt = prv[n-1];
    while (nxt >= 0) {
        ans.push_back(nxt);
        nxt = prv[nxt];
    }

    cout << ans.size() << '\n';
    for (int i = ans.size() - 1; i >= 0; --i) cout << ans[i] + 1 << ' ';
}
#include <iostream> 
#include <cstdio> 
#include <fstream>
#include <functional>
#include <set> 
#include <map> 
#include <vector> 
#include <queue> 
#include <stack> 
#include <cmath> 
#include <algorithm> 
#include <cstring> 
#include <bitset> 
#include <ctime> 
#include <sstream>
#include <stack> 
#include <cassert> 
#include <list> 
#include <deque>
//#include <unordered_set> 
using namespace std;
typedef long long li;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;

#define mp make_pair 
#define pb push_back
#define y1 botva
#define all(s) s.begin(), s.end() 
void solve();

#define NAME "changemeplease"
int main() {
#ifdef YA 
    //cerr << NAME << endl;
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout); 
    clock_t start = clock();
#else 
    //freopen("input.txt", "r", stdin); 
    //freopen("output.txt", "w", stdout); 
#endif 
    ios_base::sync_with_stdio(false);
    cout << fixed;
    cout.precision(10);
    int t = 1;
    //cin >> t;  
    for (int i = 1; i <= t; ++i) {
        //cout << "Case #" << i << ": ";
        solve();
    }
#ifdef YA 
    //cout << "\n\n\nTime:" << ((clock() - start) / 1.0 / CLOCKS_PER_SEC);
#endif 
    return 0;
}

struct query{
    int id;
    int l;
    int r;
    query(int id, int l, int r) :id(id), l(l), r(r){}
    bool operator <(const query& oth) const {
        return l < oth.l;
    }
    query(){}
};


enum evetype {
    UPD, BEGIN, END
};

struct eve {
    eve(){}
    int pos;
    evetype type;

    //for BEGIN END only
    int id;

    //for UPD only
    int leftborder;
    int val;

    bool operator < (const eve& oth) const {
        return pos < oth.pos || (pos == oth.pos && type < oth.type);
    }
};

const int inf = 2000000000;
const int treesz = 524288;


int setrmq[2 * treesz + 100];

void push(int v) {
    if (setrmq[v] == -1) {
        return;
    }

    for (int i = 0; i < 2; ++i) {
        if (setrmq[2 * v + i] == -1 || setrmq[2 * v + i] > setrmq[v]) {
            setrmq[2 * v + i] = setrmq[v];
        }
    }

    setrmq[v] = -1;
}

int getpos(int x, int i, int L, int R) {
    if (L == x && R == L + 1) {
        return setrmq[i];
    }

    push(i);

    int m = (L + R) / 2;
    if (x < m) {
        return getpos(x, 2 * i, L, m);
    }
    else {
        return getpos(x, 2 * i + 1, m, R);
    }
}

void setvalue(int value, int l, int r, int i, int L, int R) {
    if (l >= R || L >= r) {
        return;
    }

    if (l <= L && R <= r) {
        if (setrmq[i] == -1 || setrmq[i] > value) {
            setrmq[i] = value;
        }
        return;
    }

    push(i);

    int m = (L + R) / 2;

    setvalue(value, l, r, 2 * i, L, m);
    setvalue(value, l, r, 2 * i + 1, m, R);
}

void solve() {
    
    int n, m;
    cin >> n >> m;

    vector <int> a(n);
    vector <query> qs(m);

    vector < pair <int, int> > b(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        b[i] = mp(a[i], i);
    }

    for (int i = 0; i < m; ++i) {
        cin >> qs[i].l >> qs[i].r;
        --qs[i].l;
        --qs[i].r;
        qs[i].id = i;
    }
    sort(qs.begin(), qs.end());

    sort(b.begin(), b.end());

    vector <eve> eves;

    for (int i = 0; i < qs.size(); ++i) {
        eve tmp;
        tmp.id = i;

        tmp.pos = qs[i].l;
        tmp.type = BEGIN;
        eves.push_back(tmp);

        tmp.type = END;
        tmp.pos = qs[i].r;
        eves.push_back(tmp);
    }

    vector <int> low(n);
    int j = 0;
    for (int i = 0; i < n; ++i) {
        while (j < qs.size() && qs[j].l <= i) {
            ++j;
        }
        low[i] = j;
    }

    for (int i = 0; i < b.size(); ++i) {
        if (i && b[i - 1].first == b[i].first) {
            eve tmp;
            tmp.type = UPD;
            tmp.pos = b[i].second;
            tmp.val = b[i].second - b[i - 1].second;
            tmp.leftborder = low[b[i - 1].second];
            eves.push_back(tmp);
        }
    }


    sort(eves.begin(), eves.end());

    vector <int> ans(m);

    memset(setrmq, 255, sizeof(setrmq));

    for (int i = 0; i < eves.size(); ++i) {
        if (eves[i].type == BEGIN) {
            setvalue(inf, eves[i].id, eves[i].id + 1, 1, 0, treesz);
        }
        if (eves[i].type == END) {
            int id = qs[eves[i].id].id;
            ans[id] = getpos(eves[i].id, 1, 0, treesz);
        }
        if (eves[i].type == UPD) {
            setvalue(eves[i].val, 0, eves[i].leftborder, 1, 0, treesz);
        }
    }

    for (int i = 0; i < m; ++i) {
        if (ans[i] == inf) {
            ans[i] = -1;
        }
        cout << ans[i] << "\n";
    }
}
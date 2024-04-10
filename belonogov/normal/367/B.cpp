#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = 1e6 + 10;
const long long INF = 1e9 + 19;

int n, m, p;
int a[N];
int b[N];
int use[N];
int tmr;
int go[N];
vector < int > pos[N];
int need[N];
int cnt[N];

void read() {
    scanf("%d%d%d", &n, &m, &p);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < m; i++)
        scanf("%d", &b[i]); 
}

vector < int > calc(vector < int > tmp) {
    //db(tmp.size());
    //for (auto x: tmp)
        //cerr << x << " ";
    //cerr << endl;
    tmr++; 
    int n = tmp.size();

    for (int i = n - 1; i >= 0; i--) {
        int x = tmp[i];
        if (use[x] != tmr) {
            use[x] = tmr;
            pos[x].clear();
        }
        pos[x].pb(i); 
        if ((int)pos[x].size() <= need[x])
            go[i] = -1;
        else
            go[i] = pos[x][(int)pos[x].size() - 1 - need[x]];
    }
        
    tmr++;
    for (int i = 0; i < m; i++) {
        int x = b[i];
        if (use[x] != tmr) {
            use[x] = tmr;
            cnt[x] = 0;
        }
        cnt[x]++;
    }
    int all = m;

    int mn = -1;
    for (int i = 0; i < n; i++) {
        if (cnt[tmp[i]] > 0) {
            cnt[tmp[i]]--;
            all--;
        }
        if (all == 0) {
            mn = i;
            break;
        }
    }
    //db(mn);
    vector < int > res;
    if (mn == -1) return res;
    for (int i = 0; i < n; i++) {
        assert(mn - i + 1 >= m);
        if (mn - i + 1 == m) {
            res.pb(i);
        }
        if (go[i] == -1) break;
        mn = max(mn, go[i]);
    }
    return res;
}

void solve() {
    vector < int > xx;
    for (int i = 0; i < n; i++)
        xx.pb(a[i]);
    for (int i = 0; i < m; i++)
        xx.pb(b[i]);
    sort(xx.begin(), xx.end());
    xx.resize(unique(xx.begin(), xx.end()) - xx.begin());

    for (int i = 0; i < n; i++)
        a[i] = lower_bound(xx.begin(), xx.end(), a[i]) - xx.begin();     
    for (int i = 0; i < m; i++)
        b[i] = lower_bound(xx.begin(), xx.end(), b[i]) - xx.begin();
    for (int i = 0; i < m; i++)
        need[b[i]]++;

    vector < int > answer;
    for (int i = 0; i < min(p, n); i++) {
        vector < int > tmp;
        for (int j = i; j < n; j += p)
            tmp.pb(a[j]);
        if ((int)tmp.size() < m)
            break;
        vector < int > res = calc(tmp);
        
        for (auto x: res)
            answer.pb(i + x * p);
    }
    sort(answer.begin(), answer.end());
    printf("%d\n", (int)answer.size());
    for (auto x: answer)
        printf("%d ", x + 1);
    puts("");
}

void stress() {

}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        int k = 1;
        for (int tt = 0; tt < k; tt++) {
            read();
            solve();
        }
    }
    else {
        stress();
    }

    return 0;
}
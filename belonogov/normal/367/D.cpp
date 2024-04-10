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

int n, m, d;
vector < int > b[N];
int color[N];
int cnt[N];
int masks[N];

void read() {
    scanf("%d%d%d", &n, &m, &d); 
    for (int i = 0; i < m; i++) {
        int t;
        scanf("%d", &t);
        b[i].resize(t);
        for (int j = 0; j < t; j++) {
            scanf("%d", &b[i][j]); 
            b[i][j]--;
        }
    }
}

bool cmpCnt(int a, int b) {
    return __builtin_popcount(a) < __builtin_popcount(b);
}

void solve() {
    for (int i = 0; i < m; i++) {
        for (auto x: b[i])
            color[x] = i;
    } 
    for (int i = 0; i < d; i++) {
        cnt[color[i]]++;
    }

    vector < int > ban;
    for (int i = 0; i + d <= n; i++) {
        int mask = 0;
        for (int j = 0; j < m; j++)
            if (cnt[j] > 0)
                mask |= (1 << j);

        ban.pb(mask);
        
        cnt[color[i]]--;
        if (i + d < n)
            cnt[color[i + d]]++;
    }
    sort(ban.begin(), ban.end());
    ban.resize(unique(ban.begin(), ban.end()) - ban.begin());

    vector < vector < int > > g(m + 1);
    for (int mask = 0; mask < (1 << m); mask++) 
        g[__builtin_popcount(mask)].pb(mask);
    

    sort(ban.begin(), ban.end(), cmpCnt);

    
    
    for (int ans = 1; ans <= n; ans++) {
        //db(ans);
        int cur = 0;
        for (auto x: g[ans])
            masks[cur++] = x;

        for (int i = 0; i < (int)ban.size(); i++) {
            if (i % 1000 == 0 && clock() * 1.0 / CLOCKS_PER_SEC > 0.8) {
                printf("%d\n", ans);
                return;
            }
            int tt = 0;
            for (int j = 0; j < cur; j++)
                if ((ban[i] & masks[j]) != 0)
                    masks[tt++] = masks[j];

            cur = tt;
            if (cur == 0) {
                //db2(i, ban.size());
                break;
            }
        }         
        //cerr << clock() * 1.0 / CLOCKS_PER_SEC << endl;
        if (cur > 0) {
            printf("%d\n", ans);
            return; 
        }
    } 
    assert(false);

}

void stress() {

}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    freopen("test.txt", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        int k = 1;
        for (int tt = 0; tt < k; tt++) {
            read();
            solve();
            //cerr << clock() * 1.0 / CLOCKS_PER_SEC << endl;
        }
    }
    else {
        stress();
    }

    return 0;
}
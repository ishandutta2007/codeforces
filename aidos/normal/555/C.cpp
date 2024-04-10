#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <ctime>

#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()

const int inf = (1ll << 31) - 1;
const int maxn = (int) 1e5 + 10;

using namespace std;

int n, q;
int a[200200];
int b[200200];
pii c[200200];
set < int > S[3];
map < int, int > m[3];
char xx[20];


int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    scanf("%d %d", &n, &q);
    for(int i = 0, l, r; i < q; i++){
        char tt;
        cin >> l >> r >> tt;
        int cur = 0;
        if(tt == 'L') {
            cur=1;
            swap(l, r);
        }
        if(m[cur^1].count(r) || m[cur].count(l)){
            printf("0\n");
            continue;
        }
        set < int > :: iterator it = S[cur].lower_bound(l);
        set < int > :: iterator it2 = S[cur^1].lower_bound(r);
        int ans = 0;
        if(it != S[cur].end()){
            if(it2 != S[cur^1].begin() && S[cur ^1].size() > 0){
                it2--;
                int l2 = n + 1 - *it2;
                if(l < l2 && l2 < *it)
                    ans = *it2;
                else ans = m[cur][*it];
            }                    
            else {
                ans = m[cur][*it];
            }
        }else if(it2 != S[cur^1].begin() && S[cur^1].size() > 0){
            it2--;
            ans = (*it2);
        }
        printf("%d\n", r - ans);
        S[cur].insert(l);
        m[cur][l] = ans;
    }
    
    





    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}
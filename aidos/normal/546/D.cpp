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


int cnt[5000100];
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    for(int i = 2; i <= 5000000; i++){
        if(cnt[i] == 0){
            ll cur = i;
            while(cur <= 5000000){
                for(int j = cur; j <= 5000000; j+=cur){
                    cnt[j]++;
                }
                cur *= i;
            }
        }
    }
    for(int i = 1; i <= 5000000; i++){
        cnt[i] += cnt[i-1];
    }
    int t, x, y;
    scanf("%d", &t);
    while(scanf("%d %d", &x, &y) == 2){
        printf("%d\n", cnt[x] - cnt[y]);
    }   
    



    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}
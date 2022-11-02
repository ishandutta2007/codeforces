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

int a[maxn];
int n;
int m;
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n >> m; 
    int x = 0;
    for(int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
    }
int sum = 0;
for(int i = 0; i < m; i++){
int t;
scanf("%d", &t);
if(t == 1){
int v, x;
scanf("%d %d", &v, &x);
a[v-1] = x - sum;
}
else if(t == 2){
int x;
scanf("%d", &x);
sum+=x;
}else {
int x;
scanf("%d", &x);
printf("%d\n", a[x-1] + sum);
}
}


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}
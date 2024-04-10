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
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()
#define sz(a) (int)a.size()

const int inf = (int)1e9;
const int maxn = (int) 1e5 + 10;

using namespace std;

int a[4];
void solve(){
    for(int i = 0; i<3; i++)
        cin >> a[i];
    int  t =0;
    int ans = 0;
    while(a[0] + a[1] + a[2]> 0){
        int x = min(a[t], 2);
        a[t] -= x;
        ans++;
        t= (t+1) % 3;
    }
    cout << ans+29 << endl;
}

int main () {
    #ifdef LOCAL
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    #endif
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}
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

const int inf = (1ll << 30) - 1;
const int maxn = (int) 1e5 + 10;
const int mod = (int) 1e9 + 7;
using namespace std;

int n;
int a[300300];
int m;
int b[300300];
bool check(int x, int y) {
    for(int i = 0; i < n; i++) {
        if(a[i] == x || b[i] == x || a[i] == y || b[i] == y) continue;
        return 0;
    }
    return 1;
}
bool ok(int x) {
    for(int i = 0; i < n; i++){
        if(a[i] == x || b[i] == x) continue;
        return check(x, a[i]) || check(x, b[i]);
    }
    return 1;
    
}
void solve(){
    scanf("%d%d", &m, &n);
    for(int i = 0; i < n; i++) scanf("%d%d", &a[i], &b[i]);
    if(ok(a[0]) || ok(b[0])) {
        printf("YES\n");
    }else{
        printf("NO\n");
    }
}

int main () {
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}
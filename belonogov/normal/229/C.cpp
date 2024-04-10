#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cstring>
#include <cassert>
#include <ctime>


using namespace std;
#define forn(i, n) for(int i = 0; i < n; i++)
#define forab(i, a, b) for(int i = a; i < b; i++)
typedef long long ll;

const int maxn = 2e6;
int a[maxn];

int main(){
 //   freopen("in", "r", stdin);
  //  freopen("out", "w", stdout);
    ll n, m, ans;
    int x, y;
    cin >> n >> m;
    ans = n * (n - 1) * (n - 2) / 6;
    forn(i, m){
        scanf("%d %d", &x, &y); x--; y--;
        ans -= n - 2 - a[x] - a[y];
        a[x]++;
        a[y]++;
    }
    cout << ans;

    return 0;
}
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <cmath>
#include <vector>
#include <set>
#include <map>

using namespace std;
#define pb push_back
#define mp make_pair

#define forn(i, n) for(int i = 0; i < n; i++)
#define forab(i, a, b) for(int i = a; i < b; i++)
#define forba(i, a, b) for(int i = a; i > b; i--)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
typedef long long ll;
typedef double db;

const int maxn = 1e5 + 10;

pair < int, int > a[maxn];
int anss[maxn];

int main(){
   // freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    int x, n, h, mx, mn, mx1, mx2, mn1, mn2, mn3, ans0, ans2;
    cin >> n >> h;
    forn(i, n){
        cin >> x;
        a[i] = mp(x, i);
    }
    if (n == 2){
        cout << 0 << endl;
        forn(i, n)
            cout << "1 ";
        return 0;
    }
    sort(a, a + n);
    mx2 = a[n - 1].ff + a[n - 2].ff;
    mx1 = a[0].ff + a[n - 1].ff + h;

    mx = max(mx2, mx1);

    mn1 = a[0].ff + a[1].ff + h;
    mn2 = a[1].ff + a[2].ff;
    mn3 = a[0].ff + a[1].ff;

    mn = min(mn2, mn1);


    ans2 = mx - mn;
    ans0 = mx2 - mn3;
    assert(ans0 >= 0 && ans2 >= 0);
    if (ans0 < ans2){
        printf("%d\n", ans0);
        forn(i, n)
            printf("1 ");
    }
    else{
        printf("%d\n", ans2);
        forn(i, n)
            anss[i] = 2;
        anss[a[0].ss] = 1;
        forn(i, n)
            printf("%d ", anss[i]);
    }


    return 0;
}
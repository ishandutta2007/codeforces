#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;
const int maxn = 1e3 + 10;
typedef long long ll;
#define forn(i, n) for(int i = 0; i < n; i++)
#define forab(i, a, b) for(int i = a; i < b; i++)
int a[maxn][maxn];
int b[maxn][maxn];


ll sqr(ll a){
    return a * a;
}


ll solve(int n, int m, int & x){
    int l = 0;
        ll m1, m2;
    int r = n + 1;
    ll resm1, resm2;
    while(r - l > 1){
        m1 = (r + l + l) / 3;
        m2 = (r + r + l) / 3;
        resm1 = 0;
        resm2 = 0;
        forn(i, n)
            forn(j, m){
                resm1 += sqr(4 * (m1 - i) - 2) * a[i][j];
                resm2 += sqr(4 * (m2 - i) - 2) * a[i][j];
            }
        if (resm1 <= resm2)
            r = m2;
        else
            l = m1 + 1;
    }
    resm1 = 0;
    resm2 = 0;

    forn(i, n)
        forn(j, m){
            resm1 += sqr(4 * (l - i) - 2) * a[i][j];
            resm2 += sqr(4 * (r - i) - 2) * a[i][j];
        }
    if (resm1 <= resm2){
        x = l;
        return resm1;
    }
    x = r;
    return resm2;


}



ll solve2(int n, int m, int & x){
    int l = 0;
    ll m1, m2;
    int r = n + 1;
    ll resm1, resm2, ans;
    while(r - l > 1){
        m1 = (r + l + l) / 3;
        m2 = (r + r + l) / 3;
        resm1 = 0;
        resm2 = 0;
        forn(i, n)
            forn(j, m){
                resm1 += sqr(4 * (m1 - i) - 2) * b[i][j];
                resm2 += sqr(4 * (m2 - i) - 2) * b[i][j];
            }
        if (resm1 <= resm2)
            r = m2;
        else{
            l = m1 + 1;
            ans = resm1;
        }
    }
    resm1 = 0;
    resm2 = 0;
    forn(i, n)
        forn(j, m){
            resm1 += sqr(4 * (l - i) - 2) * b[i][j];
            resm2 += sqr(4 * (r - i) - 2) * b[i][j];
        }
    if (resm1 <= resm2){
        x = l;
        return resm1;
    }
    x = r;
    return resm2;



}




int main()
{
    int n, m, x, y;
    ll ans = 0;
    cin >> n >> m;
    forn(i, n)
        forn(j, m){
            scanf("%d", &a[i][j]);
            b[j][i] = a[i][j];
        }
    ans = solve(n, m, x);
    ans += solve2(m, n, y);
    cout << ans << "\n";
    cout << x << " " << y;
    return 0;
}
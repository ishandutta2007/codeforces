 #include <iostream>
#include <cstdio>

using namespace std;
#define forn(i, n) for(i = 0; i < n; i++)
#define forab(i, a, b) for(i = a; i < b; i++)
#define forba(i, b, a) for(i = b; i > a; i--)

typedef long long ll;
typedef double db;
const int maxn = 1e5;
ll a[maxn];


int main(){
     int n, i, t;
    ll ans;
    cin >> n;
    forn(i, n)
        cin >> a[i];

    ans = 0;
    forn(i, n - 1){
        t = 1;
        while(i + t * 2 < n)
            t *= 2;
        a[i + t] += a[i];
        ans += a[i];
        a[i] = 0;
        cout << ans << "\n";
    }


    return 0;

}
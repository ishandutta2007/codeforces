#include <iostream>
#include <cstdio>

using namespace std;
#define forn(i, n) for(i = 0; i < n; i++)
#define forab(i, a, b) for(i = a; i < b; i++)
#define forba(i, b, a) for(i = b; i > a; i--)

typedef long long ll;
typedef double db;
const ll p = 1e9 + 7;

ll calc(ll n){
    ll b;
    if (n < 1)
        return 1;
    if (n % 2 == 1)
        return (calc(n - 1) * 2) % p;
    else{
        b = calc(n / 2);
        return (b * b) % p;
    }
}


int main(){
   ll n, x, y;
    cin >> n;
    if (n == 0){
        cout << 1;
        return 0;
    }
    //cerr << calc(10);
    x = (calc(n) + 1) % p;
    y = calc(n - 1);
    cout << (x * y) % p; 

    return 0;

}
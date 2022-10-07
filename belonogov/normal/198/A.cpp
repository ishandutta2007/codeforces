#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
#define forn(i, n) for(i = 0; i < n; i++)
#define forab(i, a, b) for(i = a; i < b; i++)
#define forba(i, b, a) for(i = b; i > a; i--)

typedef long long ll;
typedef double db;

const int maxn = 2e5;


int main(){
   ll k, b, t, x;
    int n, i;
    cin >> k >> b >> n >> t;
    x = 1;
    for(i = 0; x * k + b <= t; i++){
        x = x * k + b;
    }
    cout << max(n - i, 0);
     



    return 0;

}
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

const int maxn = 2e5;

ll pow1(ll x, ll n, ll m){
    if (n <= 0)
        return 1;
    if (n % 2 == 0){
        ll y = pow1(x, n / 2, m);
        return (y * y) % m;
    }
    return (pow1(x, n - 1, m) * x) % m;
}

int main(){
     ll n, m, ans = 0;
    cin >> n >> m;
    ans = pow1(3, n, m);
    cout << (ans + m - 1) % m;
    return 0;
}
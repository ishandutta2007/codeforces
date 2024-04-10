#include <cstdio>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#define ll long long

using namespace std;

const int maxn = (int)2e5 + 10;
char s[maxn], t[maxn];

int main() {
    ll n, k;
    
    cin >> n >> k;
    
    n = min(n, k - 1);
    
    ll l = k - n;
    ll r = n;
    
    if (l > r) {
        cout << 0 << endl;
    } else {
        cout << (r - l + 1) / 2 << endl;
    }
    
    return 0;
}
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
#include <bitset>
#include <time.h>
#define ll long long
#define mp make_pair
#define pii pair <int, int>

using namespace std;

int main() {
    srand(time(NULL));
    ll n;
    int k;
    
    cin >> n >> k;
    
    ll l = 1, r = n;
    
    while (true) {
        if (r - l >= 50) {
            ll m = (l + r) >> 1;
            
            cout << l << ' ' << m << endl;

            string s;
            
            cin >> s;
            
            if (s[0] == 'Y') {
                r = m;
            } else if (s[0] == 'N') {
                l = m + 1;
            } else {
                throw 1;
            }
            
            l = max((ll)1, l - k);
            r = min(n, r + k);
        } else {
            ll x = rand() % (r - l + 1);
            x += l;
            
            cout << x << ' ' << x << endl;
            
            string s;
            
            cin >> s;
            
            if (s[0] == 'Y') {
                return 0;
            } else if (s[0] != 'N') {
                throw 1;
            }
            
            l = max((ll)1, l - k);
            r = min(n, r + k);
        }
    }
    
    return 0;
}
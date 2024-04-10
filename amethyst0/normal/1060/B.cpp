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
#define ld long double

using namespace std;

const int maxn = 100;

int dp[maxn][11];

vector <int> z;

int go(int pos, int o) {
    if (dp[pos][o] != -1) {
        return dp[pos][o];
    }
    
    if (pos == (int)z.size()) {
        if (o == 0) {
            return 0;
        } else {
            return -(int)1e9;
        }
    }
    
    int ans = - (int)1e9;
    
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            int no = (i + j + o) % 10;
            
            if (no == z[pos]) {
                ans = max(ans, go(pos + 1, (i + j + o) / 10) + i + j);
            }
        }
    }
    
    return dp[pos][o] = ans;
}

int main() {
    ll n;
    
    cin >> n;
    
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    while (n != 0) {
        z.push_back(n % 10);
        n /= 10;
    }    
    
    memset(dp, -1, sizeof dp);
    
    cout << go(0, 0) << endl;
    
    return 0;
}
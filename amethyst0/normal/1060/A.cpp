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

const int maxn = 110;
char s[maxn];

int main() {
    int n;
    
    cin >> n;

    scanf("%s", s);
    
    int cnt = 0;
    
    for (int i = 0; i < n; i++) {
        if (s[i] == '8') {
            cnt++;
        }
    }
    
    int ans = 0;
    
    for (int i = 1; i <= cnt; i++) {
        if ((n - i) / 10 >= i) {
            ans = i;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}
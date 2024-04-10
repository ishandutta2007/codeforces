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

const int maxn = 140;
char s[maxn][maxn];

int main() {
    int n, m;
    
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }
    
    int x = -1, y = -1, x1 = -1, y1 = -1;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == 'B') {
                x = i;
                y = j;
                break;
            }
        }
    }
    
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (s[i][j] == 'B') {
                x1 = i;
                y1 = j;
                break;
            }
        }
    }
    
    cout << (x + x1) / 2 + 1 << ' ' << (y + y1) / 2 + 1 << endl;
    
    return 0;
}
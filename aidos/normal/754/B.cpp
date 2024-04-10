#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)3e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n, k;
char c[5][5];
int dx[] = {1, 0, 1, 1};
int dy[] = {0, 1, 1, -1};
void solve() {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            cin >> c[i][j];
        }
    }
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++){
            for(int k = 0; k < 4; k++) {
                int good = 1;
                int cnt = 0;
                for(int t = 0; t < 3; t++) {
                    int x = i + dx[k] * t;
                    int y = j + dy[k] * t;
                    if(x >= 0 && x < 4 && y >= 0 && y < 4) {
                        if(c[x][y] == 'o') good = 0;
                        if(c[x][y] == 'x') cnt++;
                    } else {
                        good = 0;
                    }
                }
                if(good && cnt == 2) {
                    cout << "YES\n";
                    return;
                }
            }
        }
    }
    cout << "NO\n";
}


int main() {
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}
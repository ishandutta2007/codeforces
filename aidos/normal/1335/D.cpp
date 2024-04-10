#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)3e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n, k;
char c[10][10];
void solve() {
    for(int i = 0 ;i < 9; i++) 
        for(int j = 0; j < 9; j++) cin >> c[i][j];
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            if(c[i][j] == '1') c[i][j] = '2';
        }
    }
    for(int i = 0; i < 9; i++) cout << c[i] << "\n";
}


int main() {
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}
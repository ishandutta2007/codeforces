#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = (int)1e9 + 9;
const int inf = (1<<30) - 1;
int n, k;
string s;
int u[maxn];
void solve() {
    cin >> n >> k >> s;
    int len = k/2;
    for(int i = 0; i < n; i++) {
        if(s[i] == '(') {
            u[i] = 1;
            len--;
            if(len == 0) break;
        }
    }
    len = k/2;
    for(int i = n-1; i >=0; i--) {
        if(s[i] == ')') {
            u[i] = 1;
            len--;
            if(len == 0) break;
        }
    }
    for(int i = 0; i < n; i++)
        if(u[i]) cout << s[i];
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
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
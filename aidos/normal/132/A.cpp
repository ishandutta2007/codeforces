#pragma optimize("", on)
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int) 998244353;
const int inf = (1<<30) - 1;
int n, m;
string s;
int get(int x, int y) {
    int a = 0;
    int b = 0;
    for(int i = 0; i < 8; i++) {
        if(x & (1<<i)) {
            a ^= (1<<(7-i));
        }
        if(y & (1<<i)) {
            b ^= (1<<(7-i));
        }
    }
    return (b-a + 256) % 256;
}
void solve() {
    getline(cin, s);
    int last = 0;
    for(char c: s) {
        int d = get(c, last);
        cout << d << "\n";
        last = c;
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    //cin.tie(0);
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
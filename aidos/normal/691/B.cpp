#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
const double pi = acos(-1);

vector<int> prefix_function(string s) {
    int n = s.size();
    vector<int> p(n, 0);
    for(int i = 1; i < n; i++) {
        int z = p[i-1];
        while(z > 0 && s[z] != s[i]) z = p[z-1];
        if(s[z] == s[i]) z++;
        p[i] = z;
    }
    return p;
}
string s = "AHIMOoTUVvWwXxY", t;
int eq(char u,char v) {
    for(int i = 0; i < s.size(); i++) if(s[i] == u && s[i] == v) return 1;
    if(u == 'q' && v == 'p') return 1;
    if(u == 'p' && v == 'q') return 1;
    if(u == 'b' && v == 'd') return 1;
    if(u == 'd' && v == 'b') return 1;
    return 0;

}
void solve() {
    cin >> t;
    for(int i = 0; i < t.size(); i++) {
        if(!eq(t[i], t[t.size()-i-1])) {
            cout << "NIE\n";
            return;
        }
    }
    cout << "TAK\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
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
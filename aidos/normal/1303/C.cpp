#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = 998244353;
const int inf = (1<<30) - 1;
const double pi = acos(-1);
int n;
string s;
void solve() {
    cin >> s;
    string t;
    int pos=0;
    for(const char &c: s) {
        if(t.size() == 0) {
            t += c;
        } else if(t.find(c) == string::npos) {
            if(pos == 0) {
                t = c + t;
            } else if(pos == t.size() - 1) {
                t += c;
                pos++;
            } else {
                cout << "NO\n";
                return;
            }
        } else if(pos > 0 && t[pos-1] == c) {
            pos--;
        } else if(pos + 1 < t.size() && t[pos + 1] == c) {
            pos++;
        }else {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    for(char c = 'a'; c <= 'z'; c++){
        if(t.find(c) == string::npos) t += c;
    }
    cout << t << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
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
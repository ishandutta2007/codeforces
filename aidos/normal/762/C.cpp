#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
const double pi = acos(-1);
int n;

string s, t;
int l[maxn];
int r[maxn];
void solve() {
    cin >> s >> t;
    int pos = 0;
    for(int i = 0; i < s.size(); i++) {
        if(pos < t.size() && t[pos] == s[i]) pos++;
        l[i] = pos;
    }
    pos = t.size()-1;
    for(int i = s.size() - 1; i >= 0; i--) {
        r[i] = pos;
        if(pos >= 0 && t[pos] == s[i]) pos--;
    }
    if(pos == -1) {
        cout << t << "\n";
        return;
    }
    int len = t.size();
    int L = 0;
    int R = t.size()-1;
    for(int i = 0; i < s.size(); i++) {
        int cur = r[i] - l[i] + 1;
        if(len > cur) {
            len = cur;
            L = l[i];
            R = r[i];
        }
    }
    if(len > pos+1) {
        len = pos + 1;
        L = 0;
        R = pos;
    }
    for(int i = 0; i < t.size(); i++) {
        if(i < L) cout << t[i];
        else if(i > R) cout << t[i];
    }
    if(len == t.size()) cout << '-';
    cout << "\n";
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
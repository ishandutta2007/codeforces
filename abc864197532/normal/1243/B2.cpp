#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define endl '\n'

void solve() {
    int n;
    string s1, s2;
    cin >> n >> s1 >> s2;
    for (char c = 'a'; c <= 'z'; ++c) {
        if ((count(s1.begin(), s1.end(), c) + count(s2.begin(), s2.end(), c)) % 2) {
            cout << "NO" << endl;
            return;
        }
    }
    vector <pii> ans;
    fop (i,0,n) {
        if (s1[i] == s2[i]) continue;
        bool is = false;
        fop (j,i+1,n) {
            if (s1[i] == s1[j]) {
                ans.eb(j, i);
                swap(s1[j], s2[i]);
                is = true;
                break;
            }
        }
        if (is) continue;
        fop (j,i+1,n) {
            if (s1[i] == s2[j]) {
                ans.eb(j, j);
                ans.eb(j, i);
                swap(s1[j], s2[j]);
                swap(s1[j], s2[i]);
                break;
            }
        }
    }
    cout << "YES" << endl << ans.size() << endl;
    for (pii i : ans) cout << i.first + 1 << ' ' << i.second + 1 << endl; 
}


int main () {
    int t;
    cin >> t;
    while (t--) solve();
}
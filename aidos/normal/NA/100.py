
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = (int)5e5 + 10;
int n, m, k;
int a[maxn];
pair<int, int> t[4*maxn];
void upd(int v, int tl, int tr, int pos, int val) {
    if(tl == tr) {
        if(!val) {
            t[v] = {-1, -1};
        } else {
            t[v] = {0, 1};
        }
    } else {
        int mid = (tl + tr)/2;
        if(pos <= mid) {
            upd(v * 2, tl, mid, pos, val);
        } else {
            upd(v * 2 + 1, mid+1, tr, pos, val);
        }
        t[v].first = min(t[v * 2].first, t[v * 2+1].first + t[v * 2].second);
        t[v].second = t[v*2].second + t[v*2+1].second;
    }
}
void solve() {
    string s;
    cin >> s;
    if(s.size() % 2 == 1) {
        cout << -1 << "\n";
        return;
    }
    int bal = 0;
    ll ans = 0;
    vector<pair<int, int>> d;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(') {
            upd(1, 0, s.size()-1, i, 1);
            bal++;
        } else if(s[i] == ')') {
            upd(1, 0, s.size()-1, i, 0);
            bal--;
        } else{
            bal++;
            int x, y;

            upd(1, 0, s.size()-1, i, 1);
            cin >> x >> y;
            ans += x;
            d.push_back({y-x, i});
        }
        if(bal < 0) {
            cout << -1 << "\n";
            return;
        }
    }
    bal = 0;

    for(int i = s.size()-1; i >= 0; i--) {
        if(s[i] == ')') {
            bal++;
        } else if(s[i] == '(') {
            bal--;
        } else{
            bal++;
        }
        if(bal < 0) {
            cout << -1 << "\n";
            return;
        }
    }
    sort(d.begin(), d.end());
    for(int i = 0; i < d.size(); i++) {
        int pos=d[i].second;
        upd(1, 0, s.size()-1, pos, 0);
        if(t[1].first >= 0) {
            s[pos] = ')';
            ans += d[i].first;
        } else {
            upd(1, 0, s.size()-1, pos, 1);
            s[pos] = '(';
        }
    }
    cout<<ans << "\n" << s << "\n";
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    //cin >> t;
    for(int i=1; i <= t; i++) {
        solve();
    }
    return 0;
}
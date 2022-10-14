#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<lli,lli> 
#define X first
#define Y second
vector <pii> input;
vector <int> ans;

bool ask (lli len, int k) {
    vector <pair<pii, int>> now;
    fop (i,0,input.size()) {
        if (input[i].Y - len + 1 > input[i].X) now.eb(mp(input[i].X, input[i].Y - len + 1), i);
    }
    sort(now.begin(), now.end());
    priority_queue <pii, vector<pii>, greater<pii>> seg;
    fop (i,0,now.size()) {
        while (seg.size() and seg.top().X <= now[i].X.X) seg.pop();
        seg.push({now[i].X.Y, now[i].Y});
        if (seg.size() >= k) {
            ans.clear();
            fop (_,0,k) {
                ans.pb(seg.top().Y);
                seg.pop();
            }
            return true;
        }
    }
    return false;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    input.resize(n);
    fop (i,0,n) {
        cin >> input[i].X >> input[i].Y;
        input[i].Y++;
    }
    lli len = 0;
    FOP (i,32,0) {
        if (ask(len + (1ll << i), k)) len += (1ll << i);
    }
    cout << len << endl;
    for (int i : ans) cout << i + 1 << ' ';
    if (ans.empty()) fop (i,0,k) cout << i + 1 << ' ';
    cout << endl;
}
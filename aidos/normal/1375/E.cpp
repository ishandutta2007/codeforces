#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)5e5 + 10;
const int mod = (int)1e9 + 9;
const int inf = (1<<30) - 1;
int n, m;
pii a[maxn];
int b[maxn];
int pos[maxn];

set<int> bad;
vector<pii>ans;
void Swap(int l, int r){
    ans.emplace_back(make_pair(l+1, r + 1));
    for(int t = -1; t < 2; t ++) {
        if (bad.count(b[r] + t)) bad.erase(b[r] + t);
        if (bad.count(b[l] + t)) bad.erase(b[l] + t);
    }

    swap(b[l], b[r]);
    pos[b[r]] = r;
    pos[b[l]] = l;
    for(int t = -1; t < 2; t ++) {
        if (b[r]+t >= 0 && b[r] + t + 1 < n && pos[b[r] + t + 1] < pos[b[r] + t]) bad.insert(b[r] + t);
        if (b[l]+t >= 0 && b[l] + t + 1 < n && pos[b[l] + t + 1] < pos[b[l] + t]) bad.insert(b[l] + t);
    }
}
void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a, a + n);
    for(int i = 0; i < n; i++) {
        b[a[i].second] = i;
    }
    for(int i = 0; i < n; i++) {
        pos[b[i]] = i;
    }
    for(int i = 1; i < n; i++) {
        if(pos[i-1] > pos[i])bad.insert(i-1);
    }

    while(bad.size() > 0) {
        int x = *(--bad.end());
        //bad.erase(x);
        Swap(pos[x + 1], pos[x]);
    }
    //reverse(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for(auto x:ans) {
        cout << x.first << " " << x.second << "\n";
    }
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
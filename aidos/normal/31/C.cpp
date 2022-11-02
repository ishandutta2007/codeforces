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
int a[maxn], b[maxn];
vector<int> c;
int cnt[maxn];
void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        a[i] *= 2;
        a[i]++;
        b[i] *= 2;
        b[i]--;
        c.emplace_back(a[i]);
        c.emplace_back(b[i]);
    }
    sort(c.begin(), c.end());
    c.resize(unique(c.begin(), c.end()) - c.begin());
    for(int i = 0; i < n; i++) {
        a[i] = lower_bound(c.begin(), c.end(), a[i]) - c.begin() + 1;
        b[i] = lower_bound(c.begin(), c.end(), b[i]) - c.begin() + 1;
    }
    int mx = c.size();
    for(int i = 0; i < n; i++) {
        cnt[a[i]]++;
        cnt[b[i] + 1]--;
    }
    for(int i = 1; i <= mx; i++) {
        cnt[i] += cnt[i - 1];
    }
    int posl = -1, posr = -1;
    for(int i = 1; i <= mx; i++) {
        if(cnt[i] > 2) {
            cout << 0 << "\n";
            return;
        }
        if(cnt[i] <= 1) continue;
        if(posl == -1) {
            posl = i;
        }
        posr = i;
    }
    vector<int> ans;
    for(int i = 0; i < n; i++) {
        if(posl == -1) {
            ans.emplace_back(i + 1);
        } else if(posl >= a[i] && posr <= b[i]){
            ans.emplace_back(i + 1);
        }
    }
    cout << ans.size() << "\n";
    for(int id: ans) cout << id << " ";
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
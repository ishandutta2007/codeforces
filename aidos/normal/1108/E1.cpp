#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n, m;
int a[maxn];
vector<int> gl[maxn], gr[maxn];
int suff[maxn];
int pref[maxn];
int b[maxn];
void solve(){
    cin >> n >> m;
    vector<pii> x, y;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    pref[0] = inf;
    suff[n + 1] = inf;
    vector<pii> segments;
    int pos = 1;
    for(int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        segments.emplace_back(make_pair(l, r));
        gl[l].emplace_back(r);
        gr[r].emplace_back(l);
    }
    for(int i = 1; i <= n; i++) {
        b[i] = a[i];
    }
    for(int i = 1; i <= n; i++) {
        pref[i] = min(pref[i-1], b[i]);
        for(int l: gr[i]) {
            for(int j = l; j <= i; j++) {
                b[j]--;
                pref[i] = min(b[j], pref[i]);
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        b[i] = a[i];
    }
    for(int i = n; i>=1; i--) {
        suff[i] = min(suff[i+1], b[i]);
        for(int r: gl[i]) {
            for(int j =i; j <= r; j++) {
                b[j]--;
                suff[i] = min(b[j], suff[i]);
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        int cur = a[i] - min(pref[i-1], suff[i+1]);
        if(ans < cur) {
            ans = cur;
            pos = i;
        }
    }

    cout << ans << "\n";
    vector<int> L;
    for(int i = 0; i < m;i++) {
        if(segments[i].second < pos) {
            L.emplace_back(i+1);
        }else if(segments[i].first > pos) {
            L.emplace_back(i + 1);
        }
    }
    cout << L.size() << "\n";
    for(int id: L) {
        cout << id << " ";
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
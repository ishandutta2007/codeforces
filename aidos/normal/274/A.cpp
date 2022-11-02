#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int) 1e6 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1 << 30) - 1;
const double pi = acos(-1);
const double eps = 1e-15;
int n, m, k;
int a[maxn];
pii c[maxn];
int get(vector<int> x) {
    int ans = 1;
    int last = 1;
    for(int i = 1; i < x.size(); i++) {
        if(x[i] - x[i-1] == 1) {
            if(last) {
                last = 0;
            }else {
                last = 1;
                ans++;
            }
        }else{
            last = 1;
            ans++;
        }
    }
    return ans;
}
void solve() {
    cin >> n >> k;
    for(int i = 0 ; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);

    if(k == 1) {
        cout << n << "\n";
        return;
    }
    for(int i = 0; i < n; i++) {
        while(a[i] % k == 0) {
            a[i]/=k;
            c[i].second++;
        }
        c[i].first = a[i];
    }
    sort(c, c + n);
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(i > 0 && c[i-1].first == c[i].first) continue;
        int j = i;
        vector<int> x;
        for(int j = i; j < n; j++) {
            if(c[j].first == c[i].first) {
                x.push_back(c[j].second);
            }else break;
        }
        ans += get(x);
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for (int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}
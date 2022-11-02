#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)3e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n;
void solve() {
    cin >> n;
    int cnt0 = 0;
    int cnt1 = 0;
    vector<int> a;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(const char &c: s) {
            if(c == '0') cnt0++;
            else cnt1++;
        }
        a.push_back(s.size()/2);
    }
    int cnt = cnt0/2 + cnt1/2;
    sort(a.begin(), a.end());
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] > cnt) break;
        cnt -= a[i];
        ans++;
    }
    cout << ans << "\n";
}

int main() {
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
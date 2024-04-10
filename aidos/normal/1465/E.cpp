#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e6 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n;
ll T;
string s;
void solve() {
    cin >> n >> T >> s;
    T += 1<<(s[n-2] - 'a');
    T -= 1<<(s[n-1] - 'a');
    sort(s.begin(),s.begin()+n-2);
    reverse(s.begin(),s.begin()+n-2);
    for(int i = 0; i < n-2; i++) {
        int cur = s[i] - 'a';
        if(abs(T - (1<<cur)) < abs(T+(1<<cur))) {
            T -= 1<<cur;
        } else T += 1<<cur;
    }
    if(T == 0) cout << "Yes\n";
    else cout << "No\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}
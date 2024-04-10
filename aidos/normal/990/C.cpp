#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)6e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n;
string s;
ll cnta[maxn];
ll cntb[maxn];
ll z;
void solve(){
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s;
        int bal = 0;
        int mi = 0;
        for(int j = 0; j < s.size(); j++) {
            if(s[j] == '(') bal++;
            else if(bal == 0) {
                mi++;
            } else {
                bal--;
            }
        }
        if(mi == 0 && bal == 0) z++;
        else if(mi == 0) {
            cnta[bal]++;
        }else if(bal == 0) {
            cntb[mi]++;
        }
    }
    ll ans = z * z;
    for(int i = 0; i < maxn;i++)ans += cnta[i] * cntb[i];
    cout << ans<< "\n";
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
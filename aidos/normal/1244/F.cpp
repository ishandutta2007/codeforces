#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)5e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n;
int k;
string s;
int g[maxn];
void solve() {
    cin >> n >> k >> s;
    int ok = 1;
    for(int i = 0; i < n; i++) {
        int a = (i + n - 1) % n;
        int b = (i + 1) % n;
        if(s[a] == s[i] || s[b] == s[i]) {
            ok = 0;
            g[i] = 1;
        }
    }
    if(ok) {
        if(k % 2 == 1) {
            for(int i = 0; i < n; i++) {
                s[i] = 'W' + 'B' - s[i];
            }
        }
        cout << s << "\n";
        return;
    }
    int pos = 0;
    while(g[pos] == 0) {
        pos++;
    }
    for(int i = 0; i < n; ) {
        if(g[(i + pos) % n] == 1) {
            i++;
            continue;
        }
        int j = i;
        while(g[(i + pos) % n] == 0) {
            i++;
        }
        int L = j;
        int R = i - 1;
        for(int it = 0; it + L <= R - it; it++) {
            int posl = (pos + it + L) % n;
            int posr = (pos + R - it) % n;
            if(it < k) {
                if(it % 2 == 0) {
                    s[posl] = 'W' + 'B' - s[posl];
                    if(posl != posr) s[posr] = 'W' + 'B' - s[posr];
                }
            } else {
                if(k % 2 == 1) {
                    s[posl] = 'W' + 'B' - s[posl];
                    if(posl != posr) s[posr] = 'W' + 'B' - s[posr];
                }
            }
        }
    }
    cout << s << "\n";

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
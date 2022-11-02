#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int) 1e9 + 7;
const int inf = (1<<30) - 1;
ll k;
int a[maxn];
string s = "codeforces";
ll get() {
    ll res = 1;
    for(int i = 0; i < s.size(); i++) res *= a[i];
    return res;
}
void solve() {
    cin >> k;
    for(int i = 0; i < s.size(); i++) {
        a[i] = 1;
    }
    while(get() < k) {
        int mi = a[0] + 1;
        int z = -1;
        for(int i = 0; i < s.size(); i++) {
            if(a[i] < mi) {
                mi = a[i];
                z = i;
            }
        }
        a[z]++;
    }
    for(int i = 0; i < s.size(); i++) {
        for(int j = 0; j < a[i]; j++) {
            cout << s[i];
        }
    }

}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
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
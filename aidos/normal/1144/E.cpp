#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
const double pi = acos(-1);
int n, m, k;
string s, t;
int a[maxn];
void solve() {
    cin >> k >> s >> t;
    int c = 0;
    string ans = "";
    for(int i=0; i < k; i++) {
        a[i]=s[i]-'a' + t[i] - 'a';
    }
    for(int i = k-1; i>0; i--) {
        if(a[i] >= 26) {
            a[i] -= 26;
            a[i-1]++;
        }
    }
    for(int i = 0; i < k; i++) {
        int x =(a[i] + c * 26);
        c = x % 2;
        ans+='a' + x/2;
    }
    cout << ans << "\n";
}


int main() {
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
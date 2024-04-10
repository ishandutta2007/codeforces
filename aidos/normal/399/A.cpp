#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)3e2 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
const double pi = acos(-1);
int n, p, k;
void solve() {
    cin >> n >> p >> k;
    vector<int> a;
    for(int i = max(p-k, 1); i <= n && i <= p + k; i++) {
        a.push_back(i);
    }
    if(a[0] != 1) cout << "<< ";
    for(int i = 0; i < a.size(); i++) {
        if(i) cout << " ";
        if(a[i] == p) cout << "(";
        cout << a[i];
        if(a[i] == p) cout << ")";
    }
    if(a.back() != n) cout << " >>";
    cout << "\n";
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
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)3e3 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
const double pi = acos(-1);
int n, k;
int s;
void solve() {
    cin >> n >> s;
    map<int, int> a, b;
    for(int i = 0; i < n; i++) {
        string x;
        int p, v;
        cin >> x >> p >> v;
        if(x == "S") a[-p] += v;
        else b[-p] += v;
    }
    while(a.size() > s) {
        a.erase(a.begin());
    }
    while(b.size() > s) {
        b.erase(--b.end());
    }
    for(auto v: a) {
        cout << "S" << " " << -v.first << " " << v.second << "\n";
    }

    for(auto v: b) {
        cout << "B" << " " << -v.first << " " << v.second << "\n";
    }


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
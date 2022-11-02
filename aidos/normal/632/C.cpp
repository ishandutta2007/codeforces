#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int) 1e9 + 7;
const int inf = (1<<30) - 1;
int n, m;
string s;
bool cmp(string x, string y){
    if(x + y != y + x) return x + y < y + x;
    return x.size() < y.size();
}
void solve() {
    cin >> n;
    vector<string> d;
    for(int i = 0; i < n; i++) {
        cin >> s;
        d.emplace_back(s);
    }
    sort(d.begin(), d.end(), cmp);
    for(int i = 0; i < d.size(); i++) cout << d[i];
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
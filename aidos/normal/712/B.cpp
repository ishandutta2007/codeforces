#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
const double pi = acos(-1);

string s;
void solve() {
    cin >> s;
    if(s.size() % 2 == 1) {
        cout << -1 << "\n";
        return;
    }
    int a = 0, b = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == 'U') a++;
        if(s[i] == 'D') a--;
        if(s[i] == 'L') b++;
        if(s[i] == 'R') b--;
    }
    cout << (abs(a) + abs(b))/2 << "\n";
}


int main() {
    ios_base::sync_with_stdio(false);
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
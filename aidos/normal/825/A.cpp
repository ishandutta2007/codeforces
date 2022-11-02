#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)5e5 + 10;
const int mod = (int) 1e9 + 7;
const int inf = (1<<30) - 1;
vector<int> pref;
int n;
string s;
void solve() {
    cin >> n >> s;
    int i = 0;
    while(i < s.size()) {
        int cnt = 0;
        while(i < s.size() && s[i] == '1') cnt++, i++;
        cout<<cnt;
        i++;
    }
    if(s.back() == '0') cout<<0;
}

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
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
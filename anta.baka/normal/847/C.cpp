#include <bits/stdc++.h>

using namespace std;

#define int long long

int n, k;
string s;

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    cin >> n >> k;
    int op = 0;
    while(s.size() != 2 * n) {
        if(k >= op && s.size() + op + 2 <= 2 * n) {
            k -= op;
            s.push_back('(');
            op++;
        } else {
            s.push_back(')');
            op--;
        }
    }
    if(k != 0) cout << "Impossible";
    else cout << s;
}
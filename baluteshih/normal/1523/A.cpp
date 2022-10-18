#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

string s;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n, m, flag = 0;
        cin >> n >> m >> s;
        for (int i = 1; i <= m && !flag; ++i) {
            flag = 1;
            string tmp(s);
            for (int j = 0; j < n; ++j) {
                int cnt = 0;
                cnt += (j > 0 && s[j - 1] == '1');
                cnt += (j + 1 < n && s[j + 1] == '1');
                if (cnt == 1 && s[j] == '0') {
                    tmp[j] = '1';
                    flag = 0;
                }
            }
            s.swap(tmp);
        }
        cout << s << "\n";
    }
}
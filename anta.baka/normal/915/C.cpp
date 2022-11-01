#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string a, b;
vector<int> c1(10, 0), c2(10, 0);

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    cin >> a >> b;
    if(b.size() > a.size()) {
        sort(a.rbegin(), a.rend());
        return cout << a, 0;
    }
    for(char x : a) c1[x - '0']++;
    for(char x : b) c2[x - '0']++;
    if(c1 == c2) return cout << b, 0;

    string ans;
    for(int len = 0; len < a.size(); len++) {
        string s;
        vector<int> c = c1;
        for(int i = 0; i < len; i++) {
            if(c[b[i] - '0']-- == 0)
                goto HELL;
            s.push_back(b[i]);
        }
        for(int dig = b[len] - '0' - 1; dig >= (len == 0 ? 1 : 0); dig--)
            if(c[dig]) {
                s.push_back(char(dig + '0'));
                c[dig]--;
                for(int i = 9; i >= 0; i--)
                    for(int j = 0; j < c[i]; j++)
                        s.push_back(char(i + '0'));
                break;
            }
        if(s.size() == a.size())
            ans = max(ans, s);
    }
    HELL:
    cout << ans;
}
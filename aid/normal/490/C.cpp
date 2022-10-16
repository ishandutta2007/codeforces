#include <iostream>
#include <string>

using namespace std;

const int MAXN = 1000 * 1000 + 5;
int ra[MAXN], rb[MAXN];
string s;

int main() {
    ios_base::sync_with_stdio(false);
    int a, b;
    cin >> s >> a >> b;
    int n = s.length();
    for(int i = 0; i < n; i++)
        ra[i] = ((i? ra[i - 1] * 10 : 0) + (s[i] - '0')) % a;
    for(int i = n - 1, p10 = 1; i >= 0; i--, p10 = (p10 * 10) % b)
        rb[i] = ((i == n - 1? 0 : rb[i + 1]) + (s[i] - '0') * p10) % b;
    for(int i = 0; i + 1 < n; i++)
        if(!ra[i] && !rb[i + 1] && s[i + 1] != '0') {
            cout << "YES\n" << s.substr(0, i + 1) << '\n'
                 << s.substr(i + 1, n - i - 1) << '\n';
            return 0;
        }
    cout << "NO\n";
    return 0;
}
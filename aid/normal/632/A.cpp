#include <iostream>
#include <string>

using namespace std;

const int MAXN = 45;
char c[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, p;
    cin >> n >> p;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if(s.length() == 4)
            c[i] = false;
        else
            c[i] = true;
    }
    long long x = 0;
    for(int i = n - 1; i >= 0; i--)
        if(c[i])
            x = 2 * x + 1;
        else
            x = 2 * x;
    int cnt = 0;
    for(int i = 0; i < n; i++)
        if(c[i])
            cnt++;
    cout << x * p - cnt * (p / 2) << '\n';
    return 0;
}
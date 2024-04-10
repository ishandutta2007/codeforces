#include <iostream>
#include <string>

using namespace std;

const int MAXN = 100 * 1000 + 5;
int a[MAXN], b[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    string s, t;
    cin >> s >> t;
    int n = s.length(), m = t.length();
    for(int i = 0; i < n; i++)
        a[n - i - 1] = s[i] - '0';
    for(int i = 0; i < m; i++)
        b[m - i - 1] = t[i] - '0';
    for(int i = MAXN - 3; i >= 0; i--)
        for(int j = i; j < MAXN - 2 && a[j] && a[j + 1]; j += 2) {
            a[j] = 0;
            a[j + 1] = 0;
            a[j + 2] = 1;
        }
    for(int i = MAXN - 3; i >= 0; i--)
        for(int j = i; j < MAXN - 2 && b[j] && b[j + 1]; j += 2) {
            b[j] = 0;
            b[j + 1] = 0;
            b[j + 2] = 1;
        }
    for(int i = MAXN - 1; i >= 0; i--)
        if(a[i] != b[i]) {
            if(a[i])
                cout << ">\n";
            else
                cout << "<\n";
            return 0;
        }
    cout << "=\n";
    return 0;
}
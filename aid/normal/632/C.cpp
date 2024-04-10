#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int MAXN = 50 * 1000 + 5;
string s[MAXN];

bool cmp(const string &a, const string &b) {
    return a + b < b + a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> s[i];
    sort(s, s + n, &cmp);
    for(int i = 0; i < n; i++)
        cout << s[i];
    cout << '\n';
    return 0;
}
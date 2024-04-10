#include <iostream>
#include <string>

using namespace std;

const int MAXN = 100 * 1000 + 5;
string s[MAXN];

void getMin(string &s) {
    int n = s.length();
    if(s[0] == '?')
        s[0] = '1';
    for(int i = 1; i < n; i++)
        if(s[i] == '?')
            s[i] = '0';
}

bool getMin2(string &ps, string &s) {
    int n = s.length(), m = ps.length();
    if(n > m) {
        getMin(s);
        return true;
    }
    if(n < m)
        return false;
    int p = 0;
    while(p < n && (s[p] == ps[p] || s[p] == '?'))
        p++;
    if(p == n || s[p] < ps[p]) {
        while(p >= 0 && (s[p] != '?' || (s[p] == '?' && ps[p] == '9')))
            p--;
        if(p < 0)
            return false;
    }
    if(s[p] == '?')
        s[p] = ps[p] + 1;
    p--;
    while(p >= 0) {
        if(s[p] == '?')
            s[p] = ps[p];
        p--;
    }
    getMin(s);
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> s[i];
    getMin(s[0]);
    for(int i = 0; i + 1 < n; i++)
        if(!getMin2(s[i], s[i + 1])) {
            cout << "NO\n";
            return 0;
        }
    cout << "YES\n";
    for(int i = 0; i < n; i++)
        cout << s[i] << '\n';
    return 0;
}
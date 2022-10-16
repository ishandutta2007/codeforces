#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    n--;
    string s, t;
    cin >> s >> t;
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());
    for(int i = 0; i < n; i++)
        if(t[i] == 'N')
            t[i] = 'S';
        else if(t[i] == 'E')
            t[i] = 'W';
        else if(t[i] == 'S')
            t[i] = 'N';
        else
            t[i] = 'E';
    reverse(t.begin(), t.end());
    s += '$';
    s += t;
    n = s.length();
    vector<int> p(n);
    p[0] = 0;
    for(int i = 1; i < n; i++) {
        p[i] = p[i - 1];
        while(p[i] && s[i] != s[p[i]])
            p[i] = p[p[i] - 1];
        if(s[i] == s[p[i]])
            p[i]++;
    }
    if(p[n - 1])
        cout << "NO\n";
    else
        cout << "YES\n";
    return 0;
}
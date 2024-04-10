#include <bits/stdc++.h>

using namespace std;

map <string, string> mp;
string s[5000];

int main() {
	ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        string a, b;
        cin >> a >> b;
        if (a.size() > b.size())
            mp[a] = b;
        else
            mp[a] = a;
    }
    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int i = 0; i < n; i++)
        cout << mp[s[i]] << " ";
}
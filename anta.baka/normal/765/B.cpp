#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen("in.txt","r",stdin);
    string s;
    cin >> s;
    int n = s.length();
    vector<bool> ok(n, false);
    char c = 'a';
    for(int i = 0; i < n; i++)
        if(!ok[i]) {
            if(s[i] != c)
                return cout << "NO", 0;
            for(int j = i; j < n; j++)
                if(s[j] == c)
                    ok[j] = true;
            c++;
        }
    cout << "YES";
}
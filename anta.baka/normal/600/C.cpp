#include <bits/stdc++.h>

using namespace std;

int c[26];

int main() {
    string s;
    cin >> s;
    int n = s.length();
    for(int i = 0; i < n; i++)
        c[s[i]-'a']++;
    vector<int> odd;
    for(int i = 0; i < 26; i++)
        if(c[i]%2)
            odd.push_back(i);
    int m = odd.size();
    for(int i = 0; i < m/2; i++) {
        c[odd[i]]++;
        c[odd[m-i-1]]--;
    }
    for(int i = 0; i < 26; i++)
        for(int j = 0; j < c[i]/2; j++)
            cout << char('a'+i);
    if(n%2)
        for(int i = 0; i < 26; i++)
            if(c[i]%2)
                cout << char('a'+i);
    for(int i = 25; i >= 0; i--)
        for(int j = 0; j < c[i]/2; j++)
            cout << char('a'+i);
}
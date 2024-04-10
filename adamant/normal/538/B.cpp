#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int k = *max_element(s.begin(), s.end()) - '0';
    cout << k << endl;
    while(k--)
    {
        string k = s;
        for(int i = 0; i < s.size(); i++)
            k[i] = min(k[i], '1'),
            s[i] = max('0', (char)(s[i] - 1));
        while(k[0] == '0')
            k.erase(0, 1);
        cout << k << ' ';
    }
}
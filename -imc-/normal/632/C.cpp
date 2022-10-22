#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<string> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    
    sort(s.begin(), s.end(), [](const string& a, const string& b) { return a + b < b + a; });
    
    for (int i = 0; i < n; i++)
        cout << s[i];
    cout << endl;
    
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string t;
    cin >> t;
    string s;
    string x[10] = {"", "", "2", "3", "223", "5", "35", "7", "2227", "7332"};
    for(int i = 0; i < n; i++)
    {
        s += x[t[i] - '0'];
    }
    sort(s.begin(), s.end(), greater<char>());
    cout << s << "\n";
}
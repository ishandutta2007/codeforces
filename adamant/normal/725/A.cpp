#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string s;
    cin >> n >> s;
    int l = 0;
    int r = 0;
    while(l < s.size() && s[l] == '<')
        l++;
    while(r < s.size() && s[n - r - 1] == '>')
        r++;
    cout << l + r << endl;
    return 0;
}
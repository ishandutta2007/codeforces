#include <bits/stdc++.h>

using namespace std;

#define int uint64_t

string rev(string s)
{
    reverse(begin(s), end(s));
    return s;
}

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    while(count(begin(s), end(s), s[0]) == 1)
        rotate(begin(s), begin(s) + 1, end(s));
    //cout << s << endl;
    int k = s.find(s[0], 1);
    if(k == 1)
    {
        cout << "Impossible\n";
        return 0;
    }
    int n = s.size();
    string A = rev(s.substr(0, k / 2 + k % 2)) + s.substr(k + 1, (n - k) / 2 - k % 2);
    string B = s.substr(k / 2 + k % 2, k / 2) + rev(s.substr(k + (n - k) / 2 + 1 - k % 2));
    cout << A << endl << B << endl;
    return 0;
}
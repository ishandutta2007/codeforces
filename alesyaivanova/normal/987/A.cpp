#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int a[6] = {};
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        char c = s[0];
        if (c == 'p')
            a[0]++;
        else if (c == 'g')
            a[1]++;
        else if (c == 'b')
            a[2]++;
        else if (c == 'o')
            a[3]++;
        else if (c == 'r')
            a[4]++;
        else
            a[5]++;
    }
    cout << 6 - n << "\n";
    string ans[6] = {"Power", "Time", "Space", "Soul", "Reality", "Mind"};
    for (int i = 0; i < 6; i++)
    {
        if (!a[i])
            cout << ans[i] << "\n";
    }
}
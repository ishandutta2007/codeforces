#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string s[3];
    for (int i = 0; i < 3; i++)
        cin >> s[i];
    int ma[3] = {};
    for (int i = 0; i < 3; i++)
    {
        int num[52] = {};
        for (int e = 0; e < (int) s[i].length(); e++)
        {
            if (s[i][e] >= 'a' && s[i][e] <= 'z')
                num[s[i][e] - 'a']++;
            else
                num[(s[i][e] - 'A') + 26]++;
        }
        for (int e = 0; e < 52; e++)
        {
            if ((num[e] == (int)s[i].length()) && (n == 1))
            {
                    num[e]--;
            }
            else
                num[e] = min(num[e] + n, (int)s[i].length());
        }
        for (int e = 0; e < 52; e++)
            ma[i] = max(ma[i], num[e]);
    }
    if (ma[0] > ma[1] && ma[0] > ma[2])
        cout << "Kuro";
    else if (ma[1] > ma[2] && ma[1] > ma[0])
        cout << "Shiro";
    else if (ma[2] > ma[0] && ma[2] > ma[1])
        cout << "Katie";
    else
        cout << "Draw";
}
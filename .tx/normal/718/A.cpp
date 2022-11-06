#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string s;
vector <int> a;
int main()
{
    int n, t;
    cin >> n;
    cin >> t;
    cin >> s;
    bool st = false;
    string c = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '.')
        {
            st = true;
            continue;
        }
        if (st)
            a.push_back(s[i] - '0');
        else
            c += s[i];
    }
    bool come = false;
    int now = -2;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] >= 5)
        {
            now = i;
            break;
        }
    }
    bool stop = false;
    while ((!(stop)) && (now != -1) && (now != -2) && (t != 0) && now > 0)
    {
        now--;
        a[now]++;
        if (a[now] < 5)
            stop = true;
        t--;
    }

    if (t > 0 && a[0] >= 5)
        come = true;
    string ans = "";
    if (come)
    {
        for (int i = c.length() - 1; i >= 0; i--)
        {
            int nowc = c[i] - '0';
            if (come)
                nowc++;
            if ((nowc == 10) && (i == 0))
            {
                ans += "01";
                continue;
            }
            if (nowc == 10)
            {
                ans += '0';
                come = true;
                continue;
            }
            come = false;
            ans += nowc + '0';
        }
        reverse(ans.begin(), ans.end());
        cout << ans;
        return 0;
    }
    cout << c;
    cout << ".";
    if (now == -2)
        now = a.size() - 1;
    for  (int i = 0; i <= now; i++)
    {
        cout << a[i];
    }
    return 0;
}
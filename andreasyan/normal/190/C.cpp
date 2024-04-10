#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair

vector<string> v;

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    int q = 0;
    string u;
    stack<pair<bool, bool> > s;
    string ans;
    while (cin >> u)
    {
        v.push_back(u);
    }
    for (int i = 0; i < v.size(); ++i)
    {
        string u = v[i];
        if (u == "pair")
        {
            if (!s.empty())
            {
                if (s.top().first == false)
                    s.top().first = true;
                else if (s.top().second == false)
                {
                    ans += ',';
                    s.top().second = true;
                }
            }
            s.push(m_p(false, false));
            ans += u;
            ans += '<';
            while (!s.empty())
            {
                if (s.top().first && s.top().second)
                {
                    ans += '>';
                    s.pop();
                }
                else
                    break;
            }
        }
        else
        {
            if (!s.empty())
            {
                if (s.top().first == false)
                {
                    s.top().first = true;
                }
                else if (s.top().second == false)
                {
                    s.top().second = true;
                    ans += ',';
                }
            }
            ans += u;
            while (!s.empty())
            {
                if (s.top().first && s.top().second)
                {
                    ans += '>';
                    s.pop();
                }
                else
                    break;
            }
        }
        if (s.empty() && i != v.size() - 1)
        {
            cout << "Error occurred" << endl;
            return 0;
        }
    }
    if (!s.empty())
    {
        cout << "Error occurred" << endl;
        return 0;
    }
    cout << ans << endl;
    return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;
vector <int> a;
set <int> more;
set <int> less_;
int main()
{
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    a.resize(26);
    if (s.length() < 26)
    {
        cout << -1;
        return 0;
    }
    int need = 0;
    for (int i = 0; i < 26; i++)
    {
        more.insert(i);
        a[i] = 1;
    }
    int count = 0;
    for (int i = 0; i < 25; i++)
    {
        if (s[i] == '?')
        {
            count++;
            continue;
        }
        a[s[i] - 'A']--;
        if (a[s[i] - 'A'] == 0)
            more.erase(more.find(s[i] - 'A'));
        if (a[s[i] - 'A'] == -1)
        {
            less_.insert(s[i] - 'A');
        }
    }
    int st = 0;
    bool flag = false;
    for (int i = 0; i + 26 <= s.length(); i++)
    {
        if (s[i + 26 - 1] != '?')
        {
            a[s[i + 26 - 1] - 'A']--;
            if (a[s[i + 26 - 1] - 'A'] == 0)
                more.erase(more.find(s[i + 26 - 1] - 'A'));
            if (a[s[i + 26 - 1] - 'A'] == -1)
                less_.insert(s[i + 26 - 1] - 'A');
        }
        else
            count++;

        if ((less_.empty()) && (count == more.size()))
        {
            flag = true;
            st = i;
            break;
        }

        if (s[i] != '?')
        {
            a[s[i] - 'A']++;
            if (a[s[i] - 'A'] == 0)
                less_.erase(less_.find(s[i] - 'A'));
            if (a[s[i] - 'A'] == 1)
                more.insert(s[i] - 'A');
        }
        else
            count--;
    }
    if (flag)
    {
        for (int i = 0; i < s.length(); i++)
        {
            if ((s[i] == '?') && (i >= st) && (!(more.empty())))
            {
                cout << char(*more.begin() + 'A');
                more.erase(more.begin());
            }
            else
            {
                if (s[i] == '?')
                    cout << 'A';
                else
                    cout << s[i];

            }
        }
    }
    else
        cout << -1;
    return 0;
}
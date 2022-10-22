#include <bits/stdc++.h>

#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long li;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string good;
    cin >> good;
    vector<char> isGood(26);
    for (char c: good)
        isGood[c - 'a'] = true;
    
    string p;
    cin >> p;
    
    int n;
    cin >> n;
    
    int star = -1;
    for (int i = 0; i < p.size(); i++)
        if (p[i] == '*')
            star = i;
    
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        
        int prefMatch = 0;
        while (prefMatch < s.size() && prefMatch < p.size() && ((s[prefMatch] == p[prefMatch]) || (p[prefMatch] == '?' && isGood[s[prefMatch] - 'a'])))
            prefMatch++;
        
        int sufMatch = 0;
        while ((int)s.size() - 1 - sufMatch >= 0 && (int)p.size() - 1 - sufMatch >= 0 &&
                ((s[s.size() - 1 - sufMatch] == p[p.size() - 1 - sufMatch]) || (p[p.size() - 1 - sufMatch] == '?' && isGood[s[s.size() - 1 - sufMatch] - 'a'])))
            sufMatch++;
        
        if (star == -1 && s.size() != p.size())
        {
            cout << "NO\n";
            continue;
        }
        
        if (star == -1)
        {
            if (prefMatch + sufMatch >= s.size())
            {
                cout << "YES\n";
                continue;
            }
            else
            {
                cout << "NO\n";
                continue;
            }
        }
        
        if (prefMatch != star)
        {
            cout << "NO\n";
            continue;
        }
        
        if (sufMatch != (int)p.size() - star - 1)
        {
            cout << "NO\n";
            continue;
        }
        
        if (prefMatch + sufMatch > (int)s.size())
        {
            cout << "NO\n";
            continue;
        }
        
        bool fail = false;
        for (int i = prefMatch; i <= (int)s.size() - 1 - sufMatch; i++)
            if (isGood[s[i] - 'a'])
            {
                cout << "NO\n";
                fail = true;
                break;
            }
            
        if (!fail)
            cout << "YES\n";
    }
    
    return 0;
}
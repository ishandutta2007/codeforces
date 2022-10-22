#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

typedef long long li;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string s, t;
    cin >> s >> t;
    
    vector<int> sCount(26), tCount(26);
    int numQuestion = 0;
    for (char c: s)
        if (c != '?')
            sCount[c - 'a']++;
        else
            numQuestion++;
        
    for (char c: t)
        tCount[c - 'a']++;
    
    int low = 0, high = 1e6 + 1;
    // low can, high can't
    
    while (low + 1 != high)
    {
        int m = (low + high) / 2;
        
        li needQuestion = 0;
        for (int i = 0; i < 26; i++)
            needQuestion += max(tCount[i] * (li)m - sCount[i], (li)0);
        
        if (needQuestion <= numQuestion)
            low = m;
        else
            high = m;
    }
    
    vector<int> rep(26);
    for (int i = 0; i < 26; i++)
        rep[i] = max(tCount[i] * (li)low - sCount[i], (li)0);
    
    for (char& c: s)
        if (c == '?')
        {
            bool replaced = false;
            for (int i = 0; i < 26; i++)
                if (rep[i] != 0)
                {
                    rep[i]--;
                    c = 'a' + i;
                    replaced = true;
                    break;
                }
                
            if (!replaced)
                c = 'a';
        }
    
    cout << s << endl;
    
    return 0;
}
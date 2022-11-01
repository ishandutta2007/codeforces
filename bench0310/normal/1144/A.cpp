#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for(int o=0;o<n;o++)
    {
        string s;
        cin >> s;
        set<char> c;
        bool good=1;
        for(int i=0;i<(int)s.size();i++)
        {
            if(c.find(s[i])!=c.end()) good=0;
            c.insert(s[i]);
        }
        if((int)((*c.rbegin())-(*c.begin()))+1!=(int)s.size()) good=0;
        if(good) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
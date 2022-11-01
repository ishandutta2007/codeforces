#include <bits/stdc++.h>
using namespace std;

void strlwr(string &h)
{                 
    for (int i=0; i<h.size(); i++)
        if (h[i] >= 'A' && h[i] <='Z')
            h[i] = h[i] - 'A' + 'a';
}

int main()
{
    map<string, int> m;
    int n;
    cin >> n;
    vector <int> l[300];
    
    for (int i=0; i<n; i++)
    {
        int a, b;
        string s;
        cin >> s;
        strlwr(s);
        if (m.count(s))
        {
            a = m[s];
        } else {
            int x = m.size();
            m[s] = x;
            a = m[s];
    //      cout << s << " " << m[s] << "\n";
        }
        cin >> s;
        cin >> s;
        strlwr(s);
        if (m.count(s))
        {
            b = m[s];
        } else {
            int x = m.size();
            m[s] = x;
            b = m[s];

    //      cout << s << " " << m[s] << "\n";
        }
        l[a].push_back(b);
    }
//  for (int i=0; i<n; i++)
//      for (int j = 0; j<l[i].size(); j++)
//          cout << i <<  " " << l[i][j] << "\n";
    int ar[300] = {};
    for (int i=0; i<m.size(); i++)
        ar[i] = 1;
    for (int i=0; i<m.size(); i++)
        for (int j = 0; j<m.size(); j++)
            for (int k = 0; k<l[j].size(); k++)
                ar[j] = max(ar[j], ar[l[j][k]] + 1);
    int r = 0;
    for (int i=0; i<m.size(); i++)
        r = max(r, ar[i]);
    cout << r;
}
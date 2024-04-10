#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    vector<string> v(n);
    multiset<string> s;
    for(int i=0;i<n;i++)
    {
        cin >> v[i];
        s.insert(v[i]);
    }
    vector<string> p;
    string pal;
    for(int i=0;i<n;i++)
    {
        if(s.find(v[i])==s.end()) continue;
        string t=v[i];
        reverse(t.begin(),t.end());
        if((v[i]!=t&&s.find(t)!=s.end())||(v[i]==t&&s.count(v[i])>=2))
        {
            p.push_back(v[i]);
            p.push_back(t);
            s.erase(s.find(v[i]));
            s.erase(s.find(t));
        }
        else if(v[i]==t)
        {
            pal=v[i];
            s.erase(s.find(v[i]));
        }
    }
    cout << p.size()*m+pal.size() << endl;
    for(int i=0;i<(int)p.size();i+=2) cout << p[i];
    cout << pal;
    for(int i=(int)p.size()-1;i>=0;i-=2) cout << p[i];
    cout << endl;
    return 0;
}
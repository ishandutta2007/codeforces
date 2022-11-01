#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    set<int> s[n+1];
    int a,b;
    for(int i=0;i<m;i++)
    {
        cin >> a >> b;
        s[max(a,b)].insert(min(a,b));
    }
    vector<int> v[n+1];
    for(int i=1;i<=n;i++)
    {
        v[i].push_back(i);
        v[i].push_back(i);
    }
    int y=n+1;
    for(int i=n;i>=1;i--)
    {
        for(set<int>::iterator it=s[i].begin();it!=s[i].end();it++)
        {
            v[i].push_back(i);
            v[i].push_back(y);
            v[*it].push_back(*it);
            v[*it].push_back(y);
            y++;
        }
    }
    for(int o=1;o<=n;o++)
    {
        cout << v[o].size()/2 << endl;
        for(int i=0;i<(int)v[o].size();i+=2)
        {
            cout << v[o][i] << " " << v[o][i+1] << endl;
        }
    }
    return 0;
}
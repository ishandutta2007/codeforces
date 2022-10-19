#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N=200005;

int n;
int l[N],r[N];

int z;
map<int,int> p;

vector<int> v;

vector<int> a[N*3],b[N*3];

bool c[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>l[i]>>r[i];
        v.push_back(l[i]);
        v.push_back(r[i]);
        v.push_back(r[i]+1);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();++i)
    {
        if(p.find(v[i])==p.end())
            p[v[i]]=z++;
    }
    for(int i=1;i<=n;++i)
    {
        a[p[l[i]]].push_back(i);
        b[p[r[i]+1]].push_back(i);
    }
    set<int> s;
    for(int i=0;i<z;++i)
    {
        for(int j=0;j<b[i].size();++j)
            s.erase(b[i][j]);
        for(int j=0;j<a[i].size();++j)
            s.insert(a[i][j]);
        if(s.size()==1)
            c[*s.begin()]=true;
    }
    for(int i=1;i<=n;++i)
    {
        if(!c[i])
        {
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<"-1"<<endl;
    return 0;
}
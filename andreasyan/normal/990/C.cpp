#include <bits/stdc++.h>
using namespace std;
const int N=300005;

int n;
string s[N];
int v[N],minu[N];

map<int,vector<int> > m;

int byn(int x)
{
    int l=0,r=m[-x].size()-1;
    while((r-l)>4)
    {
        int mid=(l+r)/2;
        if(m[-x][mid]<=x)
            l=mid;
        else
            r=mid;
    }
    for(int i=r;i>=l;--i)
        if(m[-x][i]<=x)
            return i+1;
    return 0;
}

vector<int> c;
int main()
{
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>s[i];
        int si=s[i].size();
        int p=0;
        minu[i]=N;
        for(int j=0;j<si;++j)
        {
            if(s[i][j]=='(')
                ++p;
            else
                --p;
            minu[i]=min(minu[i],p);
        }
        v[i]=p;
    }
    for(int j=0;j<n;++j)
    {
        m[v[j]].push_back(-minu[j]);
        c.push_back(v[j]);
    }
    sort(c.begin(),c.end());
    for(int i=0;i<c.size();++i)
    {
        if(!i || c[i]!=c[i-1])
            sort(m[c[i]].begin(),m[c[i]].end());
    }
    long long ans=0;
    for(int i=0;i<n;++i)
    {
        if(minu[i]<0)
            continue;
        ans+=byn(v[i]);
    }
    cout<<ans<<endl;
    return 0;
}
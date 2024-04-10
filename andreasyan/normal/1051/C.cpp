#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N=102;

int n;
vector<int> a[N];

map<int,bool> c[N];
map<int,int> p[N];

char ans[N];
int main()
{
    //freopen("input.txt","r",stdin);
    cin>>n;
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        a[x].push_back(i);
    }
    c[0][0]=true;
    for(int i=0;i<N-1;++i)
    {
        for(map<int,bool>::iterator it=c[i].begin();it!=c[i].end();++it)
        {
            int x=it->first;
            if(a[i+1].size()==0 || a[i+1].size()==2)
            {
                c[i+1][it->first]=true;
                p[i+1][it->first]=0;
            }
            if(a[i+1].size()==1)
            {
                c[i+1][it->first+1]=true;
                p[i+1][it->first+1]=1;
                c[i+1][it->first-1]=true;
                p[i+1][it->first-1]=-1;
            }
            if(a[i+1].size()>2)
            {
                c[i+1][it->first]=true;
                p[i+1][it->first]=0;
                c[i+1][it->first+1]=true;
                p[i+1][it->first+1]=1;
                c[i+1][it->first-1]=true;
                p[i+1][it->first-1]=-1;
            }
        }
    }
    if(c[N-1][0]==false)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    int x=0;
    for(int i=N-1;i>=1;--i)
    {
        if(p[i][x]==0)
        {
            for(int j=0;j<a[i].size();++j)
                ans[a[i][j]]='A';
        }
        if(p[i][x]==1)
        {
            ans[a[i][0]]='A';
            for(int j=1;j<a[i].size();++j)
                ans[a[i][j]]='B';
        }
        if(p[i][x]==-1)
        {
            ans[a[i][0]]='B';
            for(int j=1;j<a[i].size();++j)
                ans[a[i][j]]='A';
        }
        x=x-p[i][x];
    }
    cout<<ans<<endl;
    return 0;
}
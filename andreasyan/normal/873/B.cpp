#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N=100005;

int n;
char a[N];

map<pair<int,int>,int> b;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("forest.in","r",stdin);
    //freopen("forest.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>a[i];
    b[m_p(0,0)]=-1;
    int p0=0,p1=0;
    int ans=0;
    for(int i=0;i<n;++i)
    {
        if(a[i]=='0')
            p0++;
        else
            p1++;
        int pp0=p0,pp1=p1;
        pp0-=min(p0,p1);
        pp1-=min(p0,p1);
        if(b.find(m_p(pp0,pp1))!=b.end())
            ans=max(ans,i-b[m_p(pp0,pp1)]);
        else
            b[m_p(pp0,pp1)]=i;
    }
    cout<<ans<<endl;
    return 0;
}
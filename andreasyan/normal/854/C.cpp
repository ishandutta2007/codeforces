#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N=300005;
struct ban
{
    int x,i;
    ban(){}
    ban(int x,int i)
    {
        this->x=x;
        this->i=i;
    }
};
bool operator<(const ban& a,const ban& b)
{
    return a.x<b.x;
}

int n,k;
int a[N];

int ans[N];

priority_queue<ban> q;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("forest.in","r",stdin);
    //freopen("forest.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    for(int i=1;i<=k;++i)
        q.push(ban(a[i],i));
    long long yans=0;
    for(int i=k+1;i<=n+k;++i)
    {
        if(i<=n)
            q.push(ban(a[i],i));
        ban t=q.top();
        q.pop();
        ans[t.i]=i;
        yans+=(1LL*(i-t.i)*t.x);
    }
    cout<<yans<<endl;
    for(int i=1;i<=n;++i)
        cout<<ans[i]<<' ';
    cout<<endl;
    return 0;
}
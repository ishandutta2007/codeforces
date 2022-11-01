#include<bits/stdc++.h>
using namespace std;
#define ll int
#define N (3333)

ll n,k,a[N],sit[N],ans,d[N][N];
bool empty;

int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=n-1;i>=0;i--)
    {
        if(a[i]==100 || sit[i+1]==2)sit[i]=2;
        else if(a[i]==0 && sit[i+1]==0)sit[i]=0;
        else sit[i]=1;
        //cout<<sit[i]<<" ";
    }
    
    queue <pair <ll,ll> > q;
    d[0][1]=1;
    q.push({0,1});
    while(q.size())
    {
        ll x=q.front().first,y=q.front().second;
        //cout<<x<<" "<<y<<"\n";
        q.pop();    
        if(x>=n)
        {
            if(!empty)ans++,empty=1;
            continue ;  
        }
        ans++;
        if(d[x][y]>k || y>=n)continue;
        if(a[x]!=0)
        {
            if(sit[y]!=2 && !d[x][y+1])
                q.push({x,y+1}),d[x][y+1]=d[x][y]+1;
            if(sit[y]!=0 && !d[y+1][y+2])
                q.push({y+1,y+2}),d[y+1][y+2]=d[x][y]+1;
        }
        if(a[x]!=100)
            if(sit[y]!=0 && !d[y][y+1])
                q.push({y,y+1}),d[y][y+1]=d[x][y]+1;
    }
    
    cout<<ans;  
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
inline ll tavan(ll a,ll n) {ll p=1;while(n>0){if(n%2){p=p*a;}n>>=1;a*=a;}return p;}
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (1001*1000)
#define INF ((ll)1e7)

ll n,m,num[N],dis[N];
string s;
vector <ll> e[N];

int main ()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            char c;
            scanf(" %c",&c);
            s+=c;
        }
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            for(int q1=-1;q1<=1;q1++)
                for(int q2=-1;q2<=1;q2++)
                    if((!q1 ^ !q2) && i+q1>=0 && j+q2>=0 && i+q1<n && j+q2<m)
                        if((s[i*m+j]=='D' && s[(i+q1)*m+j+q2]=='I') ||
                           (s[i*m+j]=='I' && s[(i+q1)*m+j+q2]=='M') ||
                           (s[i*m+j]=='M' && s[(i+q1)*m+j+q2]=='A') ||
                           (s[i*m+j]=='A' && s[(i+q1)*m+j+q2]=='D'))
                            e[i*m+j].push_back((i+q1)*m+j+q2),num[(i+q1)*m+j+q2]++; 
    ll p=0,ans=0;                       
    queue <ll> q;                               
    for(int i=0;i<n*m;i++)
        if(!num[i])
            q.push(i);
    for(int i=0;i<N;i++)dis[i]=-INF;        
    while(q.size())
    {
        ll x=q.front();
        q.pop();
        p++;
        if(s[x]=='D')dis[x]=max(dis[x],1);
        ans=max(ans,dis[x]);
        for(int i=0;i<e[x].size();i++)
        {
            dis[e[x][i]]=max(dis[e[x][i]],dis[x]+1);
            num[e[x][i]]--;
            if(num[e[x][i]]==0)
                q.push(e[x][i]);
        }
    }
    if(p!=n*m)printf("Poor Inna!\n");
    else if(ans<4)printf("Poor Dima!\n");
    else printf("%d\n",ans/4);
    return 0;
}
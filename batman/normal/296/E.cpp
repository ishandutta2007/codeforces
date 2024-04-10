#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N (111)
#define MOD ((ll)1e9+7)

ll n,k,num[2],d[2][N][N],t[2][N][N],c[N][N];

void calc()
{
    for(int i=0;i<N;i++)c[i][i]=c[i][0]=1;
    for(int i=1;i<N;i++)
        for(int j=1;j<i;j++)
            c[i][j]=(c[i-1][j]+c[i-1][j-1])%MOD;    
}

int main()
{
    calc();
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        ll x;
        cin>>x;
        num[x/50-1]++;
    }
    
    queue <pair<pair<ll,ll>,ll> > q;
    q.push({{num[0],num[1]},1});
    d[0][num[0]][num[1]]=t[0][num[0]][num[1]]=1;
    
    while(q.size())
    {
        ll x=q.front().first.first,y=q.front().first.second,p=q.front().second;
        bool m=((p==1)?0:1);
        q.pop();
        //cout<<x<<" "<<y<<" "<<p<<"\n";
        ll x2=x,y2=y;
        if(p==-1)x2=num[0]-x,y2=num[1]-y;
        for(int i=0;i<=x2;i++)
            for(int j=0;j<=y2;j++)
                if((i || j) && i*50+j*100<=k)
                {
                    if(!d[!m][x-p*i][y-p*j] || d[m][x][y]<d[!m][x-p*i][y-p*j])
                        t[!m][x-p*i][y-p*j]+=(((t[m][x][y]*c[x2][i])%MOD)*c[y2][j])%MOD,t[!m][x-p*i][y-p*j]%=MOD;
                    if(!d[!m][x-p*i][y-p*j])
                        d[!m][x-p*i][y-p*j]=d[m][x][y]+1,q.push({{x-p*i,y-p*j},-p});        
                }       
    }
    cout<<d[1][0][0]-1<<"\n"<<t[1][0][0];
    return 0;
}
#include<bits/stdc++.h>
#define ll int
#define pb push_back
#define mp make_pair
#define ld long double
#define F first
#define S second
#define pii pair<ll,ll>

using namespace std;

const ll maxn=5100;
const ll mod=1e9+7;
const ll inf=1e9+500;
int ali;
ll dp[maxn][maxn][3];
ll a[maxn];

inline ll find_h(ll x,ll b){ali++;
    if(b==0)return min(a[x],a[x-1]-1);
    if(b==1)return a[x];ali++;
    if(b==2)return min(a[x],a[x+1]-1);ali++;
}

void fil(ll x){
    dp[x][0][0]=a[x]-find_h(x,0);ali++;
    dp[x][0][1]=a[x]-find_h(x,1);
    dp[x][0][2]=a[x]-find_h(x,2);ali++;
    for(ll i=1;i<maxn;i++){ali++;
        dp[x][i][0]=inf;
        dp[x][i][1]=inf;ali++;
        dp[x][i][2]=inf;
    }
}
int main()
{ali++;
    ll n;
    cin>>n;ali++;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }ali++;
    fil(0);
    fil(1);
    for(ll i=2;i<=n+1;i++){ali++;
        dp[i][0][0]=a[i]-find_h(i,0);
        dp[i][0][1]=a[i]-find_h(i,1);ali++;
        dp[i][0][2]=a[i]-find_h(i,2);
        for(ll j=1;j<=((i+1)/2);j++){ali++;
            dp[i][j][0]=min(a[i]-find_h(i,0)+dp[i-1][j][1],a[i]-min(find_h(i,0),find_h(i,0))+dp[i-2][j-1][2]);ali++;
            dp[i][j][1]=min(a[i]-find_h(i,1)+dp[i-1][j][1],a[i]-min(find_h(i,0),find_h(i,1))+dp[i-2][j-1][2]);ali++;
            dp[i][j][2]=min(a[i]-find_h(i,2)+dp[i-1][j][1],a[i]-min(find_h(i,0),find_h(i,2))+dp[i-2][j-1][2]);ali++;
        }
        for(ll j=(i+1)/2+1;j<maxn;j++){ali++;
            dp[i][j][0]=inf;
            dp[i][j][1]=inf;ali++;
            dp[i][j][2]=inf;
        }ali++;
    }
    for(ll i=1;i<=((n+1)/2);i++){ali++;
        cout<<dp[n+1][i][0]<<' ';ali++;
    }
}
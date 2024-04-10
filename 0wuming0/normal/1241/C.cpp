#include"bits/stdc++.h"
#define ll long long
using namespace std;
ll a[200015],sum[200015],x,y,t,s,n;
bool cmp(ll a,ll b){return a>b;}
ll gcd(ll a,ll b)
{
    if(a==0||b==0)return a+b;
    if(a>b)a%=b;else b%=a;
    return gcd(a,b);
}
ll solve(ll k)
{
    ll a,b,c;
    c=k/(t*s/gcd(t,s));
    a=k/t;
    b=k/s;
    a-=c;
    b-=c;
    ll ans=0;
    ans+=sum[c]/100*(x+y);
    ans+=(sum[c+a]-sum[c])/100*x;
    ans+=(sum[c+a+b]-sum[c+a])/100*y;//cout<<k<<endl<<a<<endl<<b<<endl<<ans<<endl;
    return ans;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(int i=0;i<n;i++)scanf("%d",a+i);
        sort(a,a+n,cmp);
        sum[0]=0;
        sum[1]=a[0];
        for(int i=2;i<=n;i++)sum[i]=sum[i-1]+a[i-1];
        scanf("%d%d%d%d",&x,&t,&y,&s);
        if(x<y){swap(x,y);swap(t,s);}
        ll k;
        scanf("%lld",&k);
        int x1,x2,x;
        x1=1;x2=n;
        if(solve(n)<k){printf("-1\n");continue;}
        while(x1!=x2)
        {
            x=(x1+x2)/2;
            if(solve(x)<k)x1=x+1;
            else x2=x;
        }//cout<<n<<endl;
        printf("%d\n",x1);
    }
    return 0;
}
/*
4
1
100
50 1
49 1
100
8
100 200 100 200 100 200 100 100
10 2
15 3
107
3
1000000000 1000000000 1000000000
50 1
50 1
3000000000
5
200 100 100 100 100
69 5
31 2
90

1
5
200 100 100 100 100
69 5
31 2
90
*/
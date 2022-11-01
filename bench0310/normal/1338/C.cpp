#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<array<bool,3>> a={{1,0,1},{0,1,1}};
vector<vector<array<bool,3>>> v={{{0,0,0},{1,0,1},{0,1,1},{1,1,0}},{{0,0,0},{0,1,1},{1,1,0},{1,0,1}}};

bool solve(ll n,ll idx)
{
    //cout << "in " << n << " " << idx << endl;
    //zeroes
    ll sum=0;
    for(ll i=0;i<idx-1;i+=2) sum+=(1ll<<i);
    sum=3ll*sum;
    if(n<=sum) return 0;
    n-=sum;
    //first one
    ll temp=idx;
    if(temp&1) temp--;
    sum=3ll*(1ll<<temp);
    if(n<=sum) return a[idx&1][(n-1+3)%3];
    n-=sum;
    //loop
    ll sz=3ll*4ll*(1ll<<temp);
    n%=sz;
    if(n==0) n=sz;
    for(ll i=0;i<4;i++)
    {
        if(n>3ll*(1ll<<temp))
        {
            n-=(3ll*(1ll<<temp));
            continue;
        }
        return v[idx&1][i][(n-1+3)%3];
        break;
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        ll n;
        scanf("%I64d",&n);
        ll res=0;
        for(int i=0;i<58;i++) if(solve(n,i)==1) res+=(1ll<<i);
        printf("%I64d\n",res);
    }
    return 0;
}
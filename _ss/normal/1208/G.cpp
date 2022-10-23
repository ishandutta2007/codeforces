#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const int N=1e6;
int lp[N+10];

void sieve()
{
    for (int i=2;i<=N;i++)
        if (!lp[i])
            for (int j=i;j<=N;j+=i)
                if (!lp[j]) lp[j]=i;
}

int phi(int x)
{
    ll res=x;
    while (lp[x])
    {
        res=res/lp[x]*(lp[x]-1);
        int tmp=lp[x];
        while (lp[x]==tmp) x/=tmp;
    }
    return res;
}

int val[N+10];

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    sieve();
    for (int i=1;i<=n-2;i++) val[i]=phi(i+2);
    sort(val+1,val+n-2+1);
    val[1]=val[2]=3;
    ll res=0;
    for (int i=1;i<=k;i++) res=res+val[i];
    cout<<res;
    return 0;
}
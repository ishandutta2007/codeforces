#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(),vr.end()
#define vi vector<int>
#define vll vector<ll>
const int N=2e5+10,V=1e7;
int lp[V+10];

void sieve()
{
    for (int i=2;i<=V;i++)
        if (!lp[i])
            for (int j=i;j<=V;j+=i)
                if (!lp[j]) lp[j]=i;
}

int compress(int x)
{
    int res=1;
    while (x>1)
    {
        int tmp=lp[x],d=0;
        while (tmp==lp[x])
        {
            x/=tmp;
            d^=1;
        }
        if (d) res*=tmp;
    }
    return res;
}

int a[N],n,k;

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    sieve();
    int t;
    cin>>t;
    while (t--)
    {
        cin>>n>>k;
        for (int i=1;i<=n;i++) cin>>a[i],a[i]=compress(a[i]);
        set<int> st;
        int res=1;
        for (int i=1;i<=n;i++)
        {
            if (st.count(a[i])) st.clear(),res++;
            st.insert(a[i]);
        }
        cout<<res<<"\n";
    }
    return 0;
}
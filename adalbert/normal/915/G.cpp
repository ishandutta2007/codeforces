#include <bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen (name".out","w",stdout);
#define time pdojegoritg
#define left eorgjrptgj
#define right rtyjtokh
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int arr=2e6+100;
ll md=1e9+7;
ll step[arr],m[arr];
ll bpow (ll a, ll n)
{
	ll res = ll(1);
	while (n)
		if (n & ll(1)) {
			res *= a;
			res%=md;
			--n;
		}
		else {
			a *= a;
			a%=md;
			n >>= ll(1);
		}
	return res;
}

int getm(int u)
{
    int cnt=0;
    for (int i=2;i*i<=u;i++)
    {
        if (u%i==0)
        {
            if (u%(i*i)==0)
                return(0);
            return(-m[u/i]);
        }
        int now=0;
        while (u%i==0)
        {
            u/=i;
            now++;
        }
        if (now>1)
            return(0);
        cnt+=now;
    }
    if (u!=1)
        cnt++;

    if (cnt%2)
        return(-1); else
        return(1);
}

ll getf(int n, int u)
{
    return(m[u]*step[n/u]);
}

int ans[arr];

signed main()
{
    ll n,k;
    cin>>n>>k;

    step[0]=0;
    for (int i=1;i<=k;i++)
        step[i]=bpow(i,n);

    for (int i=1;i<=k;i++)
        m[i]=getm(i);

    for (int i=1;i<=k;i++)
    {
        if (m[i]!=0)
        for (int j=i;j<=k;j+=i)
        {

            ans[j]-=getf(j-1,i);
            ans[j]+=getf(j,i);
            ans[j]%=md;
            ans[j]+=md;
            ans[j]%=md;
        }
    }

    ll res=0;

    for (int i=2;i<=k;i++)
    {
        ans[i]+=ans[i-1];
        ans[i]%=md;
        res+=(ans[i]^i);
        res%=md;
    }

    res+=(ans[1]^ll(1));
    res%=md;

    cout<<res;
}
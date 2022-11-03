#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <memory.h>
#include <string.h>
#include <complex>
#include <queue>
#include <cstdlib>
#include <ctime>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen (name".out","w",stdout);
#define left eorgjrptgj
#define right rtyjtokh
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int arr=1e6+100;
const int md=1e9+7;

int a[arr];
int nxt[arr];

int bpow(int u, int step)
{
    if (step==0)
        return(1); else
        if (step%2)
        return(bpow(u,step-1)*u%md); else
        return(bpow(u*u%md,step/2));
}

int fact[arr],rfact[arr];

signed main()
{
    fast;
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    for (int i=n;i>=1;i--)
        if (a[i]!=a[i+1])
        nxt[i]=i+1; else
        nxt[i]=nxt[i+1];

    int ans=0;

    fact[0]=1;
    for (int i=1;i<=n;i++)
    {
        fact[i]=fact[i-1]*i;
        fact[i]%=md;
    }

    rfact[n]=bpow(fact[n],md-2);

    for (int i=n-1;i>=0;i--)
        rfact[i]=rfact[i+1]*(i+1)%md;

    int res=0;

    int dor=0;
    for (int i=1;i<=n;i++)
    {
        int now=a[i];
        int big=n-nxt[i]+1;
        if (a[i]!=a[i-1])
            dor=nxt[i]-i;
        if (big!=0)
        {
            big+=dor;
            big--;
            now*=fact[big];
            now%=md;
            now*=fact[n];
            now%=md;
            now*=rfact[big+1];
            now%=md;
            ans+=now;
            ans%=md;
        }

    }

    cout<<ans;
}
/*

*/
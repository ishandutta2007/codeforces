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
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define time pdojegoritg
#define files(name) freopen(name".in","r",stdin); freopen (name".out","w",stdout);
#pragma GCC optimize ("O3")
#pragma GCC optimize ("O2")
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define vi vector<int>
#define endl "\n"
#define int ll

int dil[10000000],f[10000000],undil[10000000],pref[10000000];

int nsd(int a, int b)
{
    while (a!=0 && b!=0)
        if (a>b) a%=b; else b%=a;
        return(a+b);
}
int n;
bool bad(int u)
{
    return(u==1 || (dil[u]==0 && u*2>n));
}

signed main()
{

    cin>>n;
    dil[1]=0;
    for (int i=2;i<=n;i++)
        if (dil[i]==0)
        {
            for (int j=2*i;j<=n;j+=i)
                if (dil[j]==0)
                dil[j]=i;
        }

    f[1]=1;
    for (int i=2;i<=n;i++)
        if (dil[i]==0)
        f[i]=i-1,undil[i]=1; else
        {
            int now=dil[i];
            while (i%(now*dil[i])==0)
                now*=dil[i];

            if (now==i)
                f[i]=now-now/dil[i]; else
            f[i]=f[i/now]*f[now];
            undil[i]=undil[i/now]+1;
        }



    int ans1=0;

    for (int i=1;i<=n;i++)
        if (dil[i]!=0)
        ans1+=i-f[i]-1;

    int ansbad=0;
    int cnt_bad=0;
    for (int i=1;i<=n;i++)
        if (i==1 || (i>n/2 && dil[i]==0))
        {

            cnt_bad++;
            ansbad+=i-1;
        } else
        {
            ansbad+=cnt_bad;
        }

    int ans0=n;

    int ans2=0;

    int cnt=0;
    for (int i=1;i<=n;i++)
        if (dil[i]!=0)
        {
            ans2+=f[i]-cnt+undil[i];
        } else cnt++;

    for (int i=1;i<=n;i++)
        if (!bad(i))
        {
            if (dil[i]==0)
                pref[i]++; else
                pref[dil[i]]++;
        }


    for (int i=1;i<=n;i++)
        pref[i]+=pref[i-1];

    for (int i=2;i<=n;i++)
        if (!bad(i) && dil[i]==0)
        {
            ans2 += pref[n/i];
                for (int j=i;j<=n;j+=i)
                if (dil[j] <= n / i)
                    if (!(dil[j]==0 && j>n/i))
                    ans2--;
        }

    for (int i=2; i<=n; i++)
    {
        int a=dil[i];
        if (a==0)
        a=i;
        int b=i/a;
        if (b!=1 && dil[b]==0 && a!=b)
        {
            ans2--;
        }
    }
    int all=(n-cnt_bad)*(n-cnt_bad-1)/2;
    int ans3=all-ans1-ans2;

    cout<<ans1+ans2*2+ans3*3;
}
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
#define fir first
#define sec second
#define pb push_back
#define left einrdonbwrjnbo
#define right ejrngkeijvbr
#define pb push_back

#define fast    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
typedef long double ld;

const int arr=3e5+10;
const int md=1e9+7;
#define int ll

int f[int(5e6)+4],use[int(5e6)+4];

signed main()
{
    for (int i=2;i<=5*1e6;i++)
        if (use[i]==0)
    {
        for (int j=i;j<=5e6;j+=i)
            if (use[j]==0)
            use[j]=i;
    }
    f[1]=0;
    f[2]=1;
    for (int i=3;i<=5e6;i++)
    {
        f[i]=i*(use[i]-1)/2%md+f[i/use[i]]%md;
        f[i]%=md;
    }

    int t,l,r;
    cin>>t>>l>>r;
    int now=1;
    int ans=0;
    for (int i=l;i<=r;i++)
    {

        now%=md;
        ans+=now*f[i]%md;
        ans%=md;
        now*=t;
    }
    cout<<ans;
}
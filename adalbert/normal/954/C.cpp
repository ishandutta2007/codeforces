#include<bits/stdc++.h>
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
#define files(name) freopen(name".dat","r",stdin); freopen (name".sol","w",stdout);
#define left eorgjrptgj
#define right rtyjtokh
#define int ll

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int md=1e9+7;

int a[300000];

signed main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    int res=1e9;
    for (int i=1;i<n;i++)
    {
        if (abs(a[i]-a[i+1])>1)
        {
            res=abs(a[i]-a[i+1]);
        }
    }

    for (int i=1;i<n;i++)
    {
        if (a[i]+1==a[i+1])
        {
            if (a[i]%res==0)
            {
                cout<<"NO";
                return(0);
            }
        } else
        if (a[i]-1==a[i+1])
        {
            if (a[i+1]%res==0)
            {
                cout<<"NO";
                return(0);
            }
        } else
        if (abs(a[i]-a[i+1])!=res)
        {
            cout<<"NO";
            return(0);
        }
    }

    int p=0;
    for (int i=1;i<=n;i++)
        p=max(p,a[i]/res+(a[i]%res!=0));

    cout<<"YES\n";
    cout<<p<<' '<<res<<'\n';
}
/*

*/
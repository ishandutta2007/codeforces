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
typedef long long  ll;
typedef double ld;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
#define int ll

int sum2[200000],sum1[200000],cnt1[200000],cnt2[200000];

signed main()
{
    fast;
    string st1,st2;
    cin>>st1>>st2;

    for (int i=0;i<st1.size();i++)
        if (st1[i]=='A')
        sum1[i+1]=0,cnt1[i+1]=1+cnt1[i]; else
        sum1[i+1]=1,cnt1[i+1]=0;

    for (int i=0;i<st2.size();i++)
        if (st2[i]=='A')
        sum2[i+1]=0,cnt2[i+1]=1+cnt2[i]; else
        sum2[i+1]=1,cnt2[i+1]=0;

    for (int i=1;i<=st1.size();i++)
        sum1[i]+=sum1[i-1];
    for (int i=1;i<=st2.size();i++)
        sum2[i]+=sum2[i-1];

    int n;
    cin>>n;
    while (n--)
    {
        int l1,  r1;
        int l2,  r2;
        cin>>l1>>r1>>l2>>r2;
        int c1=min(cnt1[r1],r1-l1+1);
        int c2=min(cnt2[r2],r2-l2+1);

        if ((sum1[r1]-sum1[l1-1])%2!=(sum2[r2]-sum2[l2-1])%2)
        {
            cout<<0;
        } else
        if ((sum1[r1]-sum1[l1-1])>(sum2[r2]-sum2[l2-1]))
        {
            cout<<0;
        } else
        if ((sum1[r1]-sum1[l1-1])==(sum2[r2]-sum2[l2-1]))
        {
            if (c1>=c2 && c1%3==c2%3)
                cout<<1; else
                cout<<0;
        } else
        {
            if (c1>=c2 && c1%3==c2%3 && !(c1==(r1-l1+1)))
                cout<<1; else
                {
                    if (c1-1>=c2)
                        cout<<1; else
                        cout<<0;
                }
        }

    }
}
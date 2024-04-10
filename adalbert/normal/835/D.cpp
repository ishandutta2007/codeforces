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
#define files(name) freopen(name".sol","r",stdin); freopen (name".dat","w",stdout);
#pragma GCC optimize ("O3")
#pragma GCC optimize ("O2")
#define time pdojegoritg
typedef long long ll;
typedef long double ld;
const int arr=4*1e5;
ll base=31;
ll md=1e9+9;

string st;

ll hesh1[arr],hesh2[arr],step[arr];

ll get1(int l,int r)
{
    return((hesh1[r]-hesh1[l]+md)%md*step[st.size()-r])%md;
}

ll get2(int l,int r)
{
    return((hesh2[r]-hesh2[l]+md)%md*step[st.size()-r])%md;
}

bool simple(int l,int r)
{
    return(get1(l,r)==get2(st.size()-r+1,st.size()-l+1));
}

int ans[5100];
bool dp[5100][5100];

signed main()
{
    cin>>st;
    step[0]=1;
    for (int i=1;i<=6000;i++)
        step[i]=step[i-1]*base%md;

    for (int i=1;i<=st.size();i++)
    {
        hesh1[i]=(hesh1[i-1]+ll(st[i-1]-'a'+1)*step[i]%md)%md;
    }

    reverse(st.begin(),st.end());

    for (int i=1;i<=st.size();i++)
    {
        hesh2[i]=(hesh2[i-1]+ll(st[i-1]-'a'+1)*step[i]%md)%md;
    }

    int mnlen=1;
    int n=st.size();

    for (int i=1;i<=n;i++)
        for (int j=i;j<=n;j++)
        {
            dp[i][j]=simple(i,j);
        }

    md=1e9+9;

    for (int i=1;i<=6000;i++)
        step[i]=step[i-1]*base%md;

    reverse(st.begin(),st.end());

    for (int i=1;i<=st.size();i++)
    {
        hesh1[i]=(hesh1[i-1]+ll(st[i-1]-'a'+1)*step[i]%md)%md;
    }

    reverse(st.begin(),st.end());

    for (int i=1;i<=st.size();i++)
    {
        hesh2[i]=(hesh2[i-1]+ll(st[i-1]-'a'+1)*step[i]%md)%md;
    }

    for (int i=1;i<=n;i++)
        for (int j=i;j<=n;j++)
        {
            dp[i][j]=simple(i,j);
            ans[1]+=dp[i][j];
        }

    int now=1;

    while (mnlen<=n)
    {
        now++;
        mnlen*=2;
        for (int siz=n;siz>=mnlen;siz--)
            for (int i=1;i+siz-1<=n;i++)
                {
                    int len=siz/2;
                    int j=i+siz-1;
                    dp[i][j]&=dp[i][i+len-1];
                    dp[i][j]&=dp[j-len+1][j];
                    ans[now]+=dp[i][i+siz-1];
                }
    }
    for (int i=1;i<=n;i++)
        cout<<ans[i]<<' ';
}
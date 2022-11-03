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
#define int ll
typedef long long ll;
typedef long double ld;
const int arr=4*1e5;
vector<ll> all;
int len;
ll now;

int mx[20],mn[20];

int cnt[12],c_now[12],ans,c[12];

bool check()
{
    for (int i=0;i<19;i++)
    {
        if (mn[i]==mx[i])
        {
            if (cnt[mn[i]]==0) return(0);
            cnt[mn[i]]--;
        } else
        {
            for (int j=mn[i]+1;j<mx[i];j++)
                if (cnt[j]!=0) return(1);
            for (int j=0;j<10;j++)
                    c_now[j]=cnt[j];
            if (cnt[mn[i]]!=0)
            {
                c_now[mn[i]]--;
                int last=9;
                bool ch=1;
                for (int j=i+1;j<19;j++)
                {
                    while (c_now[last]==0) last--;
                    if (last>mn[j]) break;
                    if (last<mn[j])
                    {
                        ch=0;
                        break;
                    }
                    c_now[last]--;
                }
                if (ch) return(1);
            }
            for (int j=0;j<10;j++)
                    c_now[j]=cnt[j];
            if (cnt[mx[i]]!=0)
            {
                c_now[mx[i]]--;
                int last=0;
                bool ch=1;
                for (int j=i+1;j<19;j++)
                {
                    while (c_now[last]==0) last++;
                    if (last<mx[j]) break;
                    if (last>mx[j])
                    {
                        ch=0;
                        break;
                    }
                    c_now[last]--;
                }
                if (ch) return(1);
            }
            return(0);
        }
    }
    return(1);
}

void rec(int u)
{
    if (len==18)
    {
        for (int i=0;i<10;i++)
            c[i]=cnt[i];

        /*if (!check())
        {
            for (int i=0;i<10;i++)
                cout<<c[i]<<' ';
            cout<<'\n';
            exit(0);
        }*/
        ans+=check();
        for (int i=0;i<10;i++)
            cnt[i]=c[i];
        return;
    }
    if (u!=9)
        rec(u+1);

    cnt[u]++;
    len++;

    rec(u);

    cnt[u]--;
    len--;
}

signed main()
{

    ll l,r;
    cin>>l>>r;
    cnt[0]=1;
    for (int i=0;i<19;i++)
    {
        mn[i]=l%ll(10);
        mx[i]=r%ll(10);
        l/=ll(10);
        r/=ll(10);
    }
    reverse(mn,mn+19);
    reverse(mx,mx+19);

    rec(0);
    cout<<ans;
}
/*
1 1000000000000000000
*/
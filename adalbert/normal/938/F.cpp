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
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

bool dp[5100][5100];

int get(int a, int u)
{
    return((a&(1<<u))!=0);
}

pair<int,int> pred[5100][5100];

signed main()
{
    vector<pair<int,int> > now;

    dp[0][0]=1;
    now.pb({0,0});

    string st;
    cin>>st;

    int mx=int(log2(int(st.size())));

    int len=int(st.size())-(1<<mx)+1;

    for (int i=1;i<=len;i++)
    {
        vector<pair<int,int> > new_;

        for (int jj=0;jj<now.size();jj++)
        {
            pair<int,int> j=now[jj];
            for (int pl=0;pl<mx;pl++)
                if (!get(j.sec,pl))
                if (!dp[j.fir+(1<<pl)][j.sec+(1<<pl)])
                {
                    dp[j.fir+(1<<pl)][j.sec+(1<<pl)]=1;
                    now.pb({j.fir+(1<<pl),j.sec+(1<<pl)});
                    pred[j.fir+(1<<pl)][j.sec+(1<<pl)]=j;
                }
        }
        char mnchar ='z';

        for (auto i:now)
            mnchar=min(mnchar,st[i.fir]);

        for (auto i:now)
        {
            if (st[i.fir]==mnchar)
                if (dp[i.fir+1][i.sec]==0)
            {
                dp[i.fir+1][i.sec]=1;
                pred[i.fir+1][i.sec]=i;
                new_.pb({i.fir+1,i.sec});
            }
        }
        now=new_;
    }

    for (int jj=0;jj<now.size();jj++)
    {
        pair<int,int> j=now[jj];
        for (int pl=0;pl<mx;pl++)
            if (!get(j.sec,pl))
            if (!dp[j.fir+(1<<pl)][j.sec+(1<<pl)])
            {
                dp[j.fir+(1<<pl)][j.sec+(1<<pl)]=1;
                now.pb({j.fir+(1<<pl),j.sec+(1<<pl)});
                pred[j.fir+(1<<pl)][j.sec+(1<<pl)]=j;
            }
    }


    int now1=st.size();
    int now2=(1<<mx)-1;
    string ans="";

    while (!(now1==0 && now2==0))
    {
        if (pred[now1][now2].sec==now2)
        {
            now1--;
            ans+=st[now1];
        } else
        {
            pair<int,int> u=pred[now1][now2];
            now1=u.fir;
            now2=u.sec;
        }
    }

    reverse(ans.begin(),ans.end());
    cout<<ans<<'\n';
}
/*

*/
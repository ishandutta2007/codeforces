#include <bits/stdc++.h>
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
const int arr=5e5+100;

pair<int,int> dp[arr][20];
int cost[arr];
int len[arr];

int mx[arr][20];

signed main()
{
    fast;
    int q;
    cin>>q;
    int last=1;
    len[1]=1;
    int rans=0;

    while (q--)
    {
        int type;
        cin>>type;
        if (type==1)
        {
            last++;
            int r;
            cin>>r>>cost[last];

            cost[last]^=rans;
            r^=rans;
            //cout<<r<<' '<<cost[last]<<"!!!"<<'\n';

            for (int i=19;i>=0;i--)
                if (r!=0)
            {
                if (mx[r][i]<cost[last])
                    r=dp[r][i].fir;

            }
            while (cost[r]<cost[last] && r!=0)
                r=dp[r][0].fir;

            len[last]=len[r]+1;
            dp[last][0].fir=r;
            dp[last][0].sec=cost[last];
            mx[last][0]=cost[last];
            for (int i=1;i<20;i++)
            {
                dp[last][i].fir=dp[dp[last][i-1].fir][i-1].fir;
                dp[last][i].sec=dp[dp[last][i-1].fir][i-1].sec+dp[last][i-1].sec;
                mx[last][i]=max(mx[dp[last][i-1].fir][i-1],mx[last][i-1]);
            }
        } else
        {
            int r,x;
            cin>>r>>x;
             r^=rans;
            x^=rans;
            //cout<<r<<' '<<x<<"sss\n";


            int ans=0;

            for (int i=19;i>=0;i--)
            {
                if (dp[r][i].sec<=x && r!=0)
                {
                    ans+=min(len[r],(ll(1)<<i));
                    x-=dp[r][i].sec;
                    r=dp[r][i].fir;
                    //cout<<r<<'\n';
                }
            }

            cout<<ans<<'\n';
            rans=ans;
        }
    }
}
/*
7
1 1 3
1 2 3
2 3 4
1 2 0
1 5 3
2 5 5
2 7 22
*/
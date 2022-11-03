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
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int arr=2e5+100;
int md=1e9+7;

int cnt[arr];

int dp[1100][1100][2];

int get(int u)
{
    if (u==1)
        return(0);
    int cnt=0;
    while (u!=0)
    {
        cnt+=u%2;
        u/=2;
    }
    return(get(cnt)+1);
}

signed main()
{
    string st;
    cin>>st;
    int k;
    cin>>k;

    dp[0][0][1]=1;

    for (int i=0;i<st.size();i++)
        for (int cnt=0;cnt<=st.size();cnt++)
        {
            if (st[i]=='0')
            {
                dp[i+1][cnt][0]+=dp[i][cnt][0];
                dp[i+1][cnt+1][0]+=dp[i][cnt][0];

                dp[i+1][cnt][1]+=dp[i][cnt][1];

                dp[i+1][cnt][0]%=md;
                dp[i+1][cnt+1][0]%=md;

                dp[i+1][cnt][1]%=md;
            } else
            {
                dp[i+1][cnt+1][1]+=dp[i][cnt][1];
                dp[i+1][cnt][0]+=dp[i][cnt][1];

                dp[i+1][cnt+1][0]+=dp[i][cnt][0];
                dp[i+1][cnt][0]+=dp[i][cnt][0];

                dp[i+1][cnt+1][1]%=md;
                dp[i+1][cnt][0]%=md;

                dp[i+1][cnt+1][0]%=md;
                dp[i+1][cnt][0]%=md;
            }
        }
    dp[st.size()][1][0]--;
    if (k==0)
    {
        cout<<1;
        return(0);
    }

    int ans=0;
    for (int i=1;i<=st.size();i++)
        if (get(i)+1==k)
        {
            ans+=dp[st.size()][i][0]+dp[st.size()][i][1];
            ans%=md;
        }


    cout<<ans;
}
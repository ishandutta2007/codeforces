#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define m_p make_pair
#define get leirogoerg
#define files(s) freopen(s".in","r",stdin); freopen(s".out","w",stdout);
#define left dogjreg
#define right dgfdogjreg
#define int ll
typedef long long ll;
typedef long double ld;
const int arr=6e5;

vector<int> dil;
int gt[arr][2];
int cnt[100];
int dp1[2*arr],dp2[2*arr];
const int md=1e9+7;

int get(int u)
{
    int res=0;
    for (int i=0;i<dil.size();i++)
    {
        int cnt=0;
        while (u%dil[i]==0)
        {
            u/=dil[i];
            cnt++;
        }
        res+=(1<<i)*(cnt%2);
    }

    return(res);
}

bool simple(int u)
{
    for (int i=2;i*i<=u;i++)
        if (u%i==0)
        return(0);
    return(1);
}

signed main()
{
    gt[0][0]=1;
    for (int i=0;i<arr-5;i++)
        for (int c=0;c<2;c++)
        {
            gt[i+1][c]+=gt[i][c];
            gt[i+1][c]%=md;
            gt[i+1][!c]+=gt[i][c];
            gt[i+1][!c]%=md;
        }

    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        cnt[a]++;
    }

    for (int i=2;i<=70;i++)
    {
        if (simple(i))
            dil.pb(i);
    }

    dp1[0]=1;

    for (int i=1;i<=70;i++)
    {
        int mx=(1<<20);
        int now=get(i);
        //cout<<now<<' '<<cnt[i]<<'\n';

        for (int j=0;j<mx;j++)
        {
            dp2[j]+=dp1[j]*gt[cnt[i]][0];
            dp2[j]%=md;
            dp2[j^now]+=dp1[j]*gt[cnt[i]][1];
            dp2[j^now]%=md;
        }

        for (int i=0;i<mx;i++)
        {
            dp1[i]=dp2[i];
            dp2[i]=0;
        }

    }

    cout<<(dp1[0]-1+md)%md;
}

/*
1
0.1 0.2 0.3
1.0 0.5 0.3
1.0 0.0 0.2
*/
#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const int N=1e5+10;
char s[N];
int n,a[N],cnt[30];
vector<int> vt[30];
int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>(s+1);
    n=strlen(s+1);
    for (int i=1;i<=n;i++) a[i]=(s[i]-'a'+1),vt[a[i]].pb(i);
    double res=0;
    for (int i=1;i<=26;i++)
    {
        int len=vt[i].size();
        double val=0;
        for (int j=2;j<=n;j++)
        {
            double tmp=0;
            for (int t=1;t<=26;t++) cnt[t]=0;
            for (int x : vt[i]) cnt[a[(x+j-2)%n+1]]++;
            for (int t=1;t<=26;t++)
                if (cnt[t]==1) tmp+=(double)1/(double)len;
            val=max(val,tmp);
        }
        res+=val*(double)len/(double)n;
    }
    printf("%.9f",res);
    return 0;
}
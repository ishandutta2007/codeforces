#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const int N=1e6+10;
ll n,a[N],ps[N],dp[N];
double tb[N];
int main()
{
    //freopen("ss.inp","r",stdin);
    scanf("%I64d",&n);
    for (int i=1;i<=n;i++) scanf("%I64d",&a[i]),ps[i]=ps[i-1]+a[i],dp[i]=1,tb[i]=a[i];
    for (int i=n-1;i;i--)
    {
        double val=a[i],len=1;
        while (i+len-1<n)
        {
            int t=i+len;
            if (tb[t]>=val) break;
            len+=dp[t];
            val=(double)(ps[i+(int)len-1]-ps[i-1])/len;
        }
        tb[i]=val;
        dp[i]=len;
    }
    for (int i=1;i<=n;i++)
    {
        printf("%.12f\n",tb[i]);
        int len=dp[i];
        for (int t=2;t<=len;t++) printf("%.12f\n",tb[i]);
        i+=dp[i]-1;
    }
    return 0;
}
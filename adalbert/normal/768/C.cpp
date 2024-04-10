#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
typedef double ld;
#define int ll
#define y1 humiuyn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
int cnt[10][10000];
signed main()
{
    int n,k,x;
    cin>>n>>k>>x;
    for (int i=1;i<=n;i++)
    {
    	int a;
    	cin>>a;
    	cnt[0][a]++;
    }
    while (k--)
    {
    	int coun=0;
    	for (int i=0;i<=3000;i++)
    	{
    		if (coun%2==0)
    		{
    			cnt[1][i]+=cnt[0][i]/2;
    			cnt[1][i^x]+=(cnt[0][i]+1)/2;
    		} else 
    		{
    			cnt[1][i^x]+=cnt[0][i]/2;
    			cnt[1][i]+=(cnt[0][i]+1)/2;
    		}
    		coun+=cnt[0][i];
    	}
    	for (int i=3000;i>=0;i--)
    	{
    		cnt[0][i]=cnt[1][i];
    		cnt[1][i]=0;
    	}
    	
    }
    int mx=0;
    int mn=1e9;
    for (int i=0;i<=3000;i++)
    {
    	if (cnt[0][i]!=0)
    	{
    		mn=min(mn,i);
    		mx=max(mx,i);
    	}
    }
    cout<<mx<<' '<<mn<<'\n';
}
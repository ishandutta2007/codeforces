#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)501*1000)
#define K ((ll)10*1000*1001)
#define MOD ((ll)1e9+7)

int n,num[K],cnt[K],id[K],a[N],b[N];
vector <int> d_p[N];
ll dp[K],tvn[N],ans;
bitset <K> mark,is;

int number=1,bultin,_id,m,now;
ll new_ans;

void solve(ll x)
{
	if(x==m)
	{
		if(!cnt[number])return ;
		if(bultin%2)new_ans+=tvn[cnt[number]-1];
		else new_ans-=tvn[cnt[number]-1];
		return ;
	}
	solve(x+1);
	bultin++,number*=d_p[_id][x];
	solve(x+1);
	bultin--,number/=d_p[_id][x];
}

int main()
{
    scanf("%d",&n);
    tvn[0]=1;
    for(int i=1;i<N;i++)tvn[i]=(tvn[i-1]*2)%MOD;
    for(int i=0;i<n;i++)
    {
    	scanf("%d",&a[i]);b[i]=a[i];
    	num[a[i]]++;
    	is[a[i]]=1;
	}
	int n2=n;
	sort(b,b+n);n2=unique(b,b+n)-b;
	for(int i=0;i<n2;i++)id[b[i]]=i;
	mark[1]=1;
	for(ll i=1;i<K;i++)
	{
		if(!mark[i])
			for(ll j=i;j<K;j+=i)
			{
				mark[j]=1;
				if(is[j])d_p[id[j]].push_back(i);
			}
		for(ll j=i;j<K;j+=i)cnt[i]+=num[j];
	}
	for(ll i=K-1;i>=1;i--)
	{
		dp[i]=tvn[cnt[i]]-1;
		for(ll j=2*i;j<K;j+=i)dp[i]-=dp[j];
		dp[i]%=MOD;dp[i]+=MOD;dp[i]%=MOD;
	}
	for(int i=0;i<n;i++)
	{
		_id=id[a[i]],m=d_p[_id].size(),now=a[i],new_ans=dp[1];
		solve(0);
		new_ans%=MOD;
		ans+=dp[1]-2*new_ans;ans%=MOD;
	}
	ans+=MOD;ans%=MOD;
	printf("%I64d",ans);
    return 0;
}
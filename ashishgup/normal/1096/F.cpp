#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;
const int MOD=998244353;

int n, ques=0, ans=0, have=0;
int a[N], idx[N], bit[N], exist[N], qpref[N];

int pow(int a, int b, int m)
{
	int ans=1;
	while(b)
	{
		if(b&1)
			ans=(ans*a)%m;
		b/=2;
		a=(a*a)%m;
	}
	return ans;
}

int modinv(int k)
{
	return pow(k, MOD-2, MOD);
}

void update(int idx, int val)
{
	while(idx<=n)
	{
		bit[idx]+=val;
		idx+=idx&-idx;
	}
}

int pref(int idx)
{
	int ans=0;
	while(idx>0)
	{
		ans+=bit[idx];
		idx-=idx&-idx;
	}
	return ans;
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		idx[a[i]]=i;
		ques+=(a[i]==-1);
		qpref[i]=qpref[i-1]+(a[i]==-1);
	}
	for(int i=1;i<=n;i++)
	{
		if(idx[i])
			exist[i]=exist[i-1]+1;
		else
			exist[i]=exist[i-1];
	}
	have=n-ques;
	int cur=ques*(ques-1)/2;
	cur%=MOD;
	cur*=modinv(2);
	cur%=MOD;
	ans+=cur;	
	ans%=MOD;
	for(int i=1;i<=n;i++)
	{
		if(!idx[i])
			continue;
		int behind=pref(idx[i]);
		int ahead=exist[i-1] - behind;
		ans+=ahead;
		ans%=MOD;
		int num=ques-qpref[idx[i]];
		int den=ques;
		if(ques>0)
		{
			int g=__gcd(num, den);
			num/=g;
			den/=g;
			int cur=num*modinv(den);
			cur%=MOD;
			ans+=((i-1)-exist[i-1])*cur;
			ans%=MOD;
		}
		num=qpref[idx[i]];
		den=ques;
		if(ques>0)
		{
			int g=__gcd(num, den);
			num/=g;
			den/=g;
			int cur=num*modinv(den);
			cur%=MOD;
			ans+=(n-i-(exist[n]-exist[i]))*cur;
			ans%=MOD;
		}
		if(idx[i])
			update(idx[i], 1);
	}
	cout<<ans;
	return 0;
}
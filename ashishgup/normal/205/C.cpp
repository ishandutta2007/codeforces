#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int len;
int a[20];
int cache[20][10][2];

int dp(int i, int firstdig, int checksmall)
{
	if(i==len+1)
		return checksmall;
	if(i==len)
	{
		if(checksmall)
			return 1;
		if(firstdig<a[i])
			return 1;
		return 0;
	}
	int &ans=cache[i][firstdig][checksmall];
	if(ans!=-1)
		return ans;
	ans=0;
	if(checksmall)
	{
		for(int j=0;j<=9;j++)
		{
			ans+=dp(i+1, firstdig, 1);
		}
	}
	else
	{
		for(int j=0;j<=a[i];j++)
		{
			ans+=dp(i+1, firstdig, j<a[i]);
		}
	}
	return ans;
}

int f(int k)
{	
	int storelen=0;
	int idx=1;
	while(k>0)
	{
		a[idx++]=k%10;
		k/=10;
		storelen++;
	}
	reverse(a+1, a+storelen+1);
	int ans=0;
	for(int l=1;l<=storelen;l++)
	{
		len=l;
		memset(cache, -1, sizeof(cache));
		for(int firstdig=1;firstdig<=9;firstdig++)
		{	
			if(l<storelen || firstdig<=a[1])
				ans+=dp(2, firstdig, firstdig<a[1]||l<storelen);
		}
	}
	return ans;
}

int32_t main()
{
	IOS;
	int l, r;
	cin>>l>>r;
	int ans=f(r+1) - f(l);
	cout<<ans;
	return 0;
}
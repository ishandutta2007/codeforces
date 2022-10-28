#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, store, inp, firstdig;
int ans[2];

void print(string s)
{
	cout<<"? "<<s<<endl;
	cin>>inp;
}

int check(int l, int r)
{
	string s="";
	for(int i=0;i<n;i++)
		s+='0';
	for(int i=l;i<=r;i++)
		s[i]='1';
	print(s);
	if(firstdig==0)
		return (inp-store)!=(r-l+1);
	else
		return (store-inp)!=(r-l+1);
}

int work(int lo, int hi)
{
	while(lo<hi)
	{
		int mid=(lo+hi)>>1;
		if(check(lo, mid))
			hi=mid;
		else
			lo=mid+1;
	}
	return lo;
}

int32_t main()
{
	cin>>n;
	string s="";
	for(int i=1;i<=n;i++)
		s+='0';
	print(s);
	store=inp;
	s[0]='1';
	print(s);
	if(inp<store)
		firstdig=1;
	else
		firstdig=0;
	s[0]='0';
	int idx=work(1, n-1);
	idx++;
	ans[firstdig]=1;
	ans[firstdig^1]=idx;
	cout<<"! "<<ans[0]<<" "<<ans[1];
	return 0;
}
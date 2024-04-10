#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)101*1000)
#define K ((ll)53)

string ex="What are you doing at the end of the world? Are you busy? Will you save us?";
string ex2="What are you doing while sending ";
string ex3="? Are you busy? Will you send ";
ll cnt[N];

char solve(int n,ll k)
{
	if(n==0)return ex[k-1];
	if(k<=ex2.size())return ex2[k-1];
	if(k<=ex2.size()+2+cnt[n-1])
	{
		if(k==ex2.size()+1 || k==ex2.size()+2+cnt[n-1])return '"';
		return solve(n-1,k-ex2.size()-1);
	}
	k-=ex2.size()+2+cnt[n-1];
	if(k<=ex3.size())return ex3[k-1];
	if(k<=ex3.size()+2+cnt[n-1])
	{
		if(k==ex3.size()+1 || k==ex3.size()+2+cnt[n-1])return '"';
		return solve(n-1,k-ex3.size()-1);
	}
	return '?';
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cnt[0]=ex.size();
	for(int i=1;i<K;i++)
	{
		cnt[i]=2*(cnt[i-1]+2)+ex2.size()+ex3.size()+1;
		if(cnt[i]>(ll)1e18)break;
	}
	for(int i=K;i<N;i++)cnt[i]=(ll)2e18;
	int q;cin>>q;
	while(q--)
	{
		int n;
		ll k;
		cin>>n>>k;
		if(n<K && k>cnt[n])
		{
			cout<<'.';
			continue;
		}
		cout<<solve(n,k);
	}
    return 0;
}
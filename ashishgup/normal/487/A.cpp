#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int h1, a1, d1, h2, a2, d2;
int ch, ca, cd;

int check(int k, int given, int taken)
{
	int opph=h2;
	while(k>0 && opph>0)
	{
		k-=taken;
		opph-=given;
	}
	if(k<=0)
		return 0;
	return 1;
}

int binsearch(int lo, int hi, int given, int taken)
{
	while(lo<hi)
	{
		int mid=(lo+hi)>>1;
		if(check(mid, given, taken))
			hi=mid;
		else
			lo=mid+1;
	}
	return lo;
}

int32_t main()
{
	IOS;
	cin>>h1>>a1>>d1>>h2>>a2>>d2;
	cin>>ch>>ca>>cd;
	int taken=a2-d1;
	int dmg=a1-d2;
	int ans=0;
	if(dmg<=0)
	{
		ans+=(abs(dmg) + 1)*ca;
		dmg=1;
	}
	if(taken<=0)
	{
		cout<<ans;
		return 0;
	}
	int finans=1e18;
	for(int i=dmg;i<=200;i++)
	{
		for(int j=taken;j>=0;j--)
		{
			int curcost=ans;
			curcost+=(i-dmg)*ca;
			curcost+=(taken-j)*cd;
			int healthreqd=binsearch(h1, 10000, i, j);
			curcost+=(healthreqd-h1)*ch;
			finans=min(finans, curcost);
		}
	} 
	cout<<finans;
	return 0;
}
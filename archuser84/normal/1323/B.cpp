#include <iostream>
#define ll long long
#define Loop(x,a,b) for(int x = a; x < b; x++)
using namespace std;

const int N = 50000;

int main()
{
	bool a[N],b[N];
	ll cnt1[N+1]={0},cnt2[N+1]={0};
	ll n,m,k;
	cin >> n >> m >> k;
	ll cnt=0;
	Loop(i,0,n)
	{
		cin >> a[i];
		//a[i]=1;
		if(a[i]==0)
		{
			cnt1[cnt]++;
			cnt = 0;
		}
		else
			cnt++;
	}
	cnt1[cnt]++;
	
	cnt=0;
	Loop(i,0,m)
	{
		cin >> b[i];
		//b[i]=1;
		if(b[i]==0)
		{
			cnt2[cnt]++;
			cnt = 0;
		}
		else
			cnt++;
	}
	cnt2[cnt]++;
	
	ll ans = 0;
	ll div;
	for(div = 1;div*div<k;div++)
	{
		if(k%div)
			continue;

		ll x=0,y=0;
		Loop(i,div,n+1)
			x+=cnt1[i]*(i-div+1);
		Loop(i,k/div,m+1)
			y+=cnt2[i]*(i-k/div+1);
		ans += x*y;

		x=0;y=0;
		Loop(i,div,m+1)
			x+=cnt2[i]*(i-div+1);
		Loop(i,k/div,n+1)
			y+=cnt1[i]*(i-k/div+1);
		ans += x*y;
	}

	if(div*div==k)
	{
		ll x=0,y=0;
		Loop(i,div,n+1)
			x+=cnt1[i]*(i-div+1);
		Loop(i,div,m+1)
			y+=cnt2[i]*(i-div+1);
		ans += x*y;
	}

	cout << ans << '\n';
}
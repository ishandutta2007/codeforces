#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int getreduced(int x, int y)
{
	int curarea=x*y;
	while(curarea%3==0)
	{
		curarea/=3;
		curarea*=2;
	}
	while(curarea%2==0)
		curarea/=2;
	return curarea;
}

int getk(int x, int y, int k)
{
	int ans=0;
	int curarea=x*y;
	while(curarea%k==0)
	{
		ans++;
		curarea/=k;
	}
	return ans;
}

void reducek(int &x, int &y, int k, int mult, int ops)
{
	while(x%k==0 && ops>0)
	{
		ops--;
		x/=k;
		x*=mult;
	}
	while(y%k==0 && ops>0)
	{
		ops--;
		y/=k;
		y*=mult;
	}
}

int32_t main()
{
	IOS;
	int a1, b1, a2, b2;
	cin>>a1>>b1>>a2>>b2;
	int reduced1=getreduced(a1, b1);
	int reduced2=getreduced(a2, b2);
	if(reduced1!=reduced2)
	{
		cout<<"-1";
		return 0;
	}
	int ans=0;
	int threes=getk(a1, b1, 3);
	int threes2=getk(a2, b2, 3);
	ans+=abs(threes-threes2);
	if(threes2>threes)
		reducek(a2, b2, 3, 2, threes2-threes);
	else
		reducek(a1, b1, 3, 2, threes-threes2);
	int twos=getk(a1, b1, 2);
	int twos2=getk(a2, b2, 2);
	ans+=abs(twos-twos2);
	if(twos2>twos)
		reducek(a2, b2, 2, 1, twos2-twos);
	else
		reducek(a1, b1, 2, 1, twos-twos2);
	cout<<ans<<endl;
	cout<<a1<<" "<<b1<<endl;
	cout<<a2<<" "<<b2<<endl;
	return 0;
}
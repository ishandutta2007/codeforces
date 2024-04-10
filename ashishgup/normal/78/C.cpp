#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n, m, k;
int ans=1;
map<pair<int, int>, int> cache;

int canWin(int x, int player)
{
	pair<int, int> p={x, player};
	if(cache.find(p)!=cache.end())
		return cache[p];
	int ans=0;
	for(int i=1;i*i<=x;i++)
	{
		if(x%i!=0)
			continue;
		if(i%2 && x/i!=x && x/i>=k)
			ans|=(!canWin(x/i, player^1));
		if((x/i)%2 && i!=x && i>=k)
			ans|=(!canWin(i, player^1));
		if(i%2==0 && x/i != x && x/i>=k)
			ans=1;
		if((x/i)%2==0 && i!=x && i>=k)
			ans=1;
	}
	return ans;
}

int32_t main()
{
	IOS;
	cin>>n>>m>>k;
	if(n%2==0)
		ans=0;
	else
		ans=canWin(m, 0)>0;
	if(ans)
		cout<<"Timur";
	else
		cout<<"Marsel";
	return 0;
}
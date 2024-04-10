#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int a, b, m, r0;
int prv[N];

int32_t main()
{
	IOS;
	memset(prv, -1, sizeof(prv));
	cin>>a>>b>>m>>r0;
	prv[r0]=0;	
	int cur=r0;
	for(int i=1;;i++)
	{
		cur=(a*cur + b)%m;
		if(prv[cur]!=-1)
		{
			cout<<i-prv[cur];
			return 0;
		}
		prv[cur]=i;
	}
	return 0;
}
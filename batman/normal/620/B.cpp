#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N (301*1000)
#define INF ((ll)1e14)
#define MOD ((ll)1e9+7)

ll a,b,num[10]={6,2,5,5,4,5,6,3,7,6},ans;

void calc(ll x)
{
	while(x)
	{
		ans+=num[x%10];
		x/=10;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>a>>b;
	for(int i=a;i<=b;i++)
		calc(i);
	cout<<ans;		
    return 0;
}
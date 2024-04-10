#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)1001*1000)
#define K ((ll)20)

ll n,num;
bool mark[N];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		ll x;
		cin>>x;
		if(x==i+1){num+=2;continue;}
		if(!mark[x])num++;
		mark[x]=1;
	}
	cout<<num/2<<endl;
	return 0;
}
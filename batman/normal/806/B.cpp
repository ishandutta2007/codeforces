#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)2020)
#define INF ((ll)1e9)

ll n,a[N][5];
ll ac[5]={},sub[5]={};

int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=0;j<5;j++)
		{
			cin>>a[i][j];
			if(a[i][j]!=-1)ac[j]++,sub[j]++;
			if(a[i][j]==-1)a[i][j]=INF;
		}
	for(int t=0;t<=20000;t++)
	{
		ll num1=0,num2=0;
		for(int j=0;j<5;j++)
		{
			ll sc=3000;
			if(n+t<ac[j]*32)sc=2500;
			if(n+t<ac[j]*16)sc=2000;
			if(n+t<ac[j]*8)sc=1500;
			if(n+t<ac[j]*4)sc=1000;
			if(n+t<ac[j]*2)sc=500;
	//		cout<<sc<<" ";
	//		cout<<sc-sc/250*a[1][j]<<" "<<sc-sc/250*a[2][j]<<"\n";
			if(a[1][j]!=INF)num1+=sc-sc/250*a[1][j];
			if(a[2][j]!=INF)num2+=sc-sc/250*a[2][j];
		}
	//	cout<<"|||| "<<num1<<" "<<num2<<"\n";
		if(num1>num2)return cout<<t,0;
		for(int j=0;j<5;j++)
		{
			sub[j]++;
			if(a[2][j]<a[1][j] && a[1][j]!=INF)ac[j]++;
		}	
	}
	cout<<"-1\n";
	return 0;
}
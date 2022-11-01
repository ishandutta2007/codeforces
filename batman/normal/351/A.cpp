#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n,a[4444],p,num[2],ans;
long double eee;


int main()
{
 	cin>>n;
 	for(int i=0;i<2*n;i++)
 	{
 		string ex;
 		int j;
 		cin>>ex;
 		for(j=0;ex[j]!='.';j++);
 		j++;
 		ll ex2=(ex[j]-'0')*100+(ex[j+1]-'0')*10+(ex[j+2]-'0');
 		if(ex2)
 			a[p++]=ex2;//cout<<a[p-1]<<"\n";
 			
	}
	sort(a,a+p);
	ll i=0;
	p--;
	while(num[0]<n && num[1]<n && i<=p)
	{
		if(abs(ans-a[i])<=abs(ans+1000-a[p]))
			ans-=a[i++],num[0]++;
		else
			ans+=(1000-a[p--]),num[1]++;	
		//cout<<ans<<endl;	
	}
	if(i<=p)
	{
		if(num[0]<n)
		{
			for(int j=i;j<=p;j++)
				ans-=a[j];
		}
		else
		{
			for(int j=i;j<=p;j++)
				ans+=(1000-a[j]);
		}
	}
	long double res=(double)ans/1000;
	cout<<fixed<<setprecision(3)<<abs(res);
 	return 0;
}
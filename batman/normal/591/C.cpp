//Platform Version 1.4 (TOF VERSION)
#include <bits/stdc++.h>
using namespace std;
#define tof main()
#define ST(a,b) cout<<fixed<<setprecision((b))<<((ld)a)<<"\n";
#define IB ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
typedef long double ld;
ifstream fin("input.txt");
ofstream fout("output.txt");
const ld PI=((ld)2*asin(1));
const ll INF=((ll)1e14);
const ll MOD=((ll)1e9+7);
const ll N =301*1000;

ll n,x,maxi;
bool a[501*1000],mark;



int main()
{
	IB
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=1;i<n-1;i++)
	{
		if(a[i]!=a[i-1] && a[i]!=a[i+1])
			x++,mark=1;
		else 
			x=0;
		maxi=max(maxi,x);
	}
	if(!mark)
		cout<<"0\n";
	else 
		cout<<(maxi-1)/2+1<<"\n";
	x=0;
	for(int i=1;i<n;i++)
	{
		if(a[i]!=a[i-1] && a[i]!=a[i+1] && i!=n-1)
			x++;
		else
		{
			//print
			if(x%2==1)
				for(int j=i-x;j<i;j++)
					a[j]=a[i];	
			else
			{
				int j,p=0;
				for(j=i-x;p<x/2;j++,p++)
					a[j]=a[i-x-1];
				for(;j<i;j++)
					a[j]=a[i];	
			}
			x=0;
		}
		
		maxi=max(maxi,x);
	}
	
	for(int i=0;i<n;i++)cout<<a[i]<<" ";	
	
    return 0;
}
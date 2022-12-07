#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int T=1000000000;
void print (int x,int y)	{cout<<"? "<<x<<" "<<y<<endl;}
int main()
{
	int L=1,R=T,x;
	int t1,t2;
	print(L,1);cin>>x;t1=x;
	print(R,1);cin>>x;t2=x;
	int ll=1,rr=T;
	while (L<=R)
	{
		int mid=(L+R)>>1;
		print(mid,1);
		cin>>x;
		if (x==-1) return 0;
		if (t1-(mid-1)==x&&t2-(T-mid)==x)//both
		{
			//printf("OKOK:%d\n",mid);
			int l=mid,r=mid;
			int d=x+1;
			print(l,T);
			cin>>x; 
			if (x==-1) return 0;
			int u=T-x;
			cout<<"! "<<l<<" "<<d<<" "<<r<<" "<<u<<endl;
			return 0;
		}
		if (t1-(mid-1)==x) {ll=mid;L=mid+1;}
		else if (t2-(T-mid)==x) {rr=mid;R=mid-1;}
		else
		{
			int l=1+t1-x;
			int r=T-(t2-x);
			int d=x+1;
			print(l,T);
			cin>>x; 
			if (x==-1) return 0;
			int u=T-x;
			cout<<"! "<<l<<" "<<d<<" "<<r<<" "<<u<<endl;
			return 0;
		}
	}
	int l=ll;
	int r=rr;
	int d=x+1;
	print(l,T);
	cin>>x; 
	if (x==-1) return 0;
	int u=T-x;
	cout<<"! "<<l<<" "<<d<<" "<<r<<" "<<u<<endl;
	return 0;
}
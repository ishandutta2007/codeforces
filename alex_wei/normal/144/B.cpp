#include<bits/stdc++.h>
using namespace std;
#define ll long long
int u,r,d,l,n,x[1005],y[1005],ra[1005],ans;
bool check(double i,double j,double k){return sqrt(i*i+j*j)<=k;}
int main()
{
	cin>>d>>l>>u>>r>>n;
	if(u<d)swap(u,d);
	if(r<l)swap(l,r);
	for(int i=1;i<=n;i++)
		cin>>x[i]>>y[i]>>ra[i];
	for(int i=d;i<=u;i++){
		int p1=0,p2=0;
		for(int j=1;j<=n;j++){
			if(check(x[j]-i,y[j]-l,ra[j]))
				p1=1;
			if(check(x[j]-i,y[j]-r,ra[j]))
				p2=1;
		}
		ans+=p1+p2;
	}
	for(int i=l+1;i<r;i++){
		int p1=0,p2=0;
		for(int j=1;j<=n;j++){
			if(check(x[j]-u,y[j]-i,ra[j]))
				p1=1;
			if(check(x[j]-d,y[j]-i,ra[j]))
				p2=1;
		}
		ans+=p1+p2;
	}
	cout<<(u-d)*2+(r-l)*2-ans<<endl;
	return 0;
}
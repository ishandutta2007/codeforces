#include<bits/stdc++.h>
using namespace std;
double ans,posb[100002];
int n,p,l,r;
int main()
{
	cin>>n>>p;
	for(int i=1;i<=n;i++){
		cin>>l>>r;
		double len=r-l+1;
		r=r-r%p;
		l=l+(l%p==0?0:p-l%p);
		l<=r?posb[i]=1.0-((r-l)/p+1.0)/len:posb[i]=1.0;
	}
	for(int i=2;i<=n;i++)
		ans+=2000.0*(1-posb[i]*posb[i-1]);
	printf("%.6lf",ans+2000.0*(1-posb[n]*posb[1]));
	return 0; 
}
#include <bits/stdc++.h>
#define int long long
#define ll long long
#define db double
#define fi first
#define se second
#define pii pair<int,int>
#define vi vector<int>

using namespace std;
int x[3],y[3]; 
int dis(int a,int b,int c,int d) {
	return abs(c-a)+abs(d-b);
}
signed main() {
	for (int i=0;i<3;i++) cin>>x[i]>>y[i];
	ll mn=1e18; 
	int px,py; 
	for (int i=0;i<3;i++) {
		for (int j=0;j<3;j++) {
			int nx=x[i],ny=y[j];
			int nd=0;
			for (int k=0;k<3;k++) {
				nd+=dis(nx,ny,x[k],y[k]);
			}
			if (nd<mn) {
				mn=nd;
				px=nx,py=ny; 
			}
		}
	}
	vector< pair<pii,pii> > ans;
	for (int i=0;i<3;i++) {
		if (px==x[i] || py==y[i]) {
			ans.push_back({{px,py},{x[i],y[i]}}); 
		}                                                                      
		else ans.push_back({{px,py},{x[i],py}}),ans.push_back({{x[i],py},{x[i],y[i]}}); 
	}
	printf("%d\n",ans.size());
	for (auto x:ans) cout<<x.fi.fi<<' '<<x.fi.se<<' '<<x.se.fi<<' '<<x.se.se<<'\n'; 
	return 0;
}
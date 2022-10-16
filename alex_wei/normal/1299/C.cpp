#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+5;
struct seg{
	ll sum;
	int l,r;
};
ll n,a[N],cnt,l[N],r[N];
vector <seg> ans;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	ans.push_back({a[1],1,1});
	for(int i=2;i<=n;i++){
		ans.push_back({a[i],i,i});
		while(ans.size()>1){
			int len=ans.size();
			seg x=ans[len-2],y=ans[len-1];
			double avx=1.l*x.sum/(x.r-x.l+1),avy=1.l*y.sum/(y.r-y.l+1);
			if(avx>=avy)ans.pop_back(),ans.pop_back(),ans.push_back({x.sum+y.sum,x.l,y.r});
			else break;
		}
	}
	for(int i=0;i<ans.size();i++){
		seg x=ans[i];
		double ave=1.l*x.sum/(x.r-x.l+1);
		for(int j=x.l;j<=x.r;j++)printf("%.9lf\n",ave);
	}
	return 0;
}
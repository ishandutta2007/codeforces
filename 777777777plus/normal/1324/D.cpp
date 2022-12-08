#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int n,a[N],b[N],c[N];
ll ans;

int main(){
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=n;++i)cin>>b[i];
	for(int i=1;i<=n;++i)c[i]=a[i]-b[i];
	sort(c+1,c+n+1);
	for(int i=1;i<=n;++i)if(a[i]>b[i])ans--;
	for(int i=1;i<=n;++i){
		int p=upper_bound(c+1,c+n+1,b[i]-a[i])-c;
		ans+=n-p+1;
	}
	ans/=2;
	cout<<ans<<endl;
}
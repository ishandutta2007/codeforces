#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5+5;

int T;
int n,k,a[N],b[N],f[N];

int main(){
	cin>>n>>k;
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)a[i]-=i;
	for(int i=1;i<=k;++i)scanf("%d",&b[i]);
	a[0]=-1e9;a[n+1]=2e9;
	b[0]=0;b[k+1]=n+1;
	int ans=0;
	for(int i=0;i<=k;++i){
		int l=b[i],r=b[i+1];
		if(a[l]>a[r]){
			puts("-1");
			return 0;
		}
		int top;
		f[top=1]=a[l];
		for(int i=l+1;i<=r;++i){
			if(a[i]>=f[top]){
				f[++top]=a[i];
				if(i==r)ans+=(r-l+1)-top;
			}
			else{
				int p=upper_bound(f+1,f+top+1,a[i])-f;
				if(p!=1)f[p]=a[i];
				if(i==r)ans+=(r-l+1)-p;
			}
		}
	}
	cout<<ans<<endl;
}
#include<bits/stdc++.h>
#define N 100100
using namespace std;
pair<int,int> a[N];
int ppy[N],pny[N],spy[N],sny[N];
inline long long sq(int x){
	return 1LL*x*x;
}
int main(){
	int n;
	const int inf=1e9;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d",&a[i].first,&a[i].second);
	}
	sort(a,a+n);
	ppy[0]=spy[n]=-inf;
	pny[0]=sny[n]=inf;
	for(int i=0;i<n;i++){
		ppy[i+1]=max(ppy[i],a[i].second);
		pny[i+1]=min(pny[i],a[i].second);
	}
	for(int i=n-1;i>=0;i--){
		spy[i]=max(spy[i+1],a[i].second);
		sny[i]=min(sny[i+1],a[i].second);
	}
	long long y_only=sq(ppy[n]-pny[n]);
	long long l=-1,r=1LL<<60;
	while(l+1<r){
		long long m=(l+r)/2;
		int sqm=ceil(sqrt(m))+10;
		while(1LL*sqm*sqm>m) sqm--;
		bool flag=false;
		int i,j;
		for(i=j=0;i<n;i++){
			while(j<n&&a[j].first<=a[i].first+sqm&&a[j].first<=-a[i].first) j++;
			int py=max(ppy[i],spy[j]),ny=min(pny[i],sny[j]);
			if(py<ny){
				flag=true;
				break;
			}
			long long diag=max(sq(a[j-1].first),sq(a[i].first))+max(sq(py),sq(ny));
			long long yd=sq(py-ny);
			if(diag<=m&&yd<=m){
				flag=true;
			}
		}
		for(i=j=n;j>0;j--){
			while(i>0&&a[j-1].first<=a[i-1].first+sqm&&a[i-1].first>=-a[j-1].first) i--;
			int py=max(ppy[i],spy[j]),ny=min(pny[i],sny[j]);
			if(py<ny){
				flag=true;
				break;
			}
			long long diag=max(sq(a[j-1].first),sq(a[i].first))+max(sq(py),sq(ny));
			long long yd=sq(py-ny);
			if(diag<=m&&yd<=m){
				flag=true;
			}
		}
		i=j=0;
		while(i<n&&a[i].first<0) j=++i;
		while(i>=0&&j<=n){
			if(j>=n || i>0 && abs(a[i-1].first)<abs(a[j].first)) i--;
			else j++;
			if(i<0||j>n||a[j-1].first-a[i].first>sqm) break;
			int py=max(ppy[i],spy[j]),ny=min(pny[i],sny[j]);
			if(py<ny){
				flag=true;
				break;
			}
			long long diag=max(sq(a[j-1].first),sq(a[i].first))+max(sq(py),sq(ny));
			long long yd=sq(py-ny);
			if(diag<=m&&yd<=m){
				flag=true;
			}
		}
		if(flag) r=m;
		else l=m;
	}
	printf("%lld\n",min(r,y_only));
	return 0;
}
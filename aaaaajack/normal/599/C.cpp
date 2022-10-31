#include<bits/stdc++.h> 
#define N 100100
#define F first
#define S second
using namespace std;
pair<int,int> p[N],a[N];
int main(){
	int n,ans=0,mx=-1;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&p[i].F),p[i].S=i,a[i]=p[i];
	sort(p,p+n);
	for(int i=0;i<n;i++){
		mx=max(mx,lower_bound(p,p+n,a[i])-p);
		if(mx==i) ans++;
	}
	printf("%d\n",ans);
	return 0;
}
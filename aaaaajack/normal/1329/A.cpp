#include<bits/stdc++.h>
#define N 200100
#define all(x) begin(x),end(x)
using namespace std;
typedef long long ll;
int a[N],ans[N];
int main(){
	int n,m;
	ll sum=0;
	scanf("%d%d",&n,&m);
	bool gg=false;
	for(int i=0;i<m;i++){
		scanf("%d",&a[i]);
		sum+=a[i];
		if(a[i]+i>n) gg=true;
	}
	if(sum<n) gg=true;
	n-=a[m-1];
	for(int i=m-2;i>=0;i--){
		ans[i]=min(a[i],n-i);
		n-=ans[i];
	}
	for(int i=1;i<m-1;i++) ans[i]+=ans[i-1];
	if(gg) puts("-1");
	else{
		printf("1");
		for(int i=0;i<m-1;i++) printf(" %d",ans[i]+1);
		puts("");
	}
	return 0;
}
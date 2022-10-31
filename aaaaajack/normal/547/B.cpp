#include<cstdio>
#include<algorithm>
#define N 200100
using namespace std;
int l[N],r[N],a[N],m[N],v[N],cnt=0;
int main(){
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++){
		while(cnt&&a[i]<=a[v[cnt-1]]) cnt--;
		if(cnt) l[i]=i-v[cnt-1];
		else l[i]=i+1;
		v[cnt++]=i;
	}
	cnt=0;
	for(i=n-1;i>=0;i--){
		while(cnt&&a[i]<=a[v[cnt-1]]) cnt--;
		if(cnt) r[i]=v[cnt-1]-i;
		else r[i]=n-i;
		m[l[i]+r[i]-1]=max(m[l[i]+r[i]-1],a[i]);
		v[cnt++]=i;
	}
	for(i=n-1;i>=1;i--){
		m[i]=max(m[i],m[i+1]);
	}
	for(i=1;i<=n;i++) printf("%d%c",m[i],i<n?' ':'\n');
	return 0;
}
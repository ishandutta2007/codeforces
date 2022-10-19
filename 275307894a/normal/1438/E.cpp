#include<cstdio>
#include<cstring>
using namespace std;
int n,m,k,x,y,z,last[500039][2],a[500039],s[500039],ans;
long long q[500039];
inline void swap(int &x,int &y){x^=y^=x^=y;}
inline void check(int x,int y){
	if(y-x<2||!x) return;
	if(q[y-1]-q[x]==(a[y]^a[x])) ans++;
}
inline void find(int flag){
	register int i,j;memset(last,0,sizeof(last));
	for(i=1;i<=n;i++){
		last[s[i]][1]=last[s[i]][0];last[s[i]][0]=i;
		for(j=s[i]+1;j<=29;j++) check(last[j][0],i),check(last[j][1],i);
		if(!flag) check(last[s[i]][1],i);
	}
}
int main(){
	register int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]),q[i]=q[i-1]+a[i];
	for(i=1;i<=n;i++){
		for(j=29;j>=0;j--) if(a[i]&(1<<j)) {s[i]=j;break;}
	}
	find(0);
	for(i=1;i<=n/2;i++) swap(a[i],a[n-i+1]),swap(s[i],s[n-i+1]);
	for(i=1;i<=n;i++) q[i]=q[i-1]+a[i];
	find(1);
	printf("%d\n",ans);
}
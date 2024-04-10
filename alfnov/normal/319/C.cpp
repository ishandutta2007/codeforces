#include<bits/stdc++.h>
using namespace std;
int a[200005],b[200005],q[200005];
long long f[200005];
double slop(int x,int y){
	return 1.0*(f[y]-f[x])/(b[x]-b[y]);
}
//qwq
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),--a[i];
	for(int i=1;i<=n;++i)scanf("%d",&b[i]);
	memset(f,63,sizeof(f));
	f[1]=b[1];
	int head=0,tail=-1;
	q[++tail]=1;
	for(int i=2;i<=n;++i){
		while(head<tail&&slop(q[head],q[head+1])<=a[i])++head;
		f[i]=b[i]+f[q[head]]+1ll*b[q[head]]*a[i];
		while(head<tail&&slop(q[tail-1],q[tail])>=slop(q[tail],i))--tail;
		q[++tail]=i;
	}
	cout<<f[n]<<endl;
	return 0;
}
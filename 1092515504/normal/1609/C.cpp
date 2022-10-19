#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6; 
int T,n,m,a[200100],pri[1001000];
bool inp[1001000];
void sieve(){
	for(int i=2;i<=N;i++){
		if(!inp[i])pri[++pri[0]]=i;
		for(int j=1;j<=pri[0]&&i*pri[j]<=N;j++){
			inp[i*pri[j]]=true;
			if(!(i%pri[j]))break;
		}
	}
}
ll res;
int main(){
	scanf("%d",&T),sieve();
	while(T--){
		scanf("%d%d",&n,&m),res=0;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=m;i++)for(int l=i,r1=i,r2=i,c=0;l<=n;l+=m){
			r1=max(r1,l),r2=max(r2,l);if(r2==l)c=0;
			while(r1<=n&&a[r1]==1)r1+=m;
			while(r2<=n&&!inp[a[r2]]&&c+(a[r2]!=1)<=1)c+=(a[r2]!=1),r2+=m;
//			printf("%d %d %d %d\n",l,r1,r2,c);
			res+=max(0,(r2-max(r1,l+m))/m);
//			printf("%lld\n",res);
			if(!inp[a[l]]&&a[l]!=1)c--;
		}
		printf("%lld\n",res);
	}
	return 0;
}
/*
1
9 3
2 4 2 1 1 1 1 4 2
*/
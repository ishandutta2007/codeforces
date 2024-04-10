#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,pri[100100],phi[100100];
ll tot;
void getphi(){
	phi[1]=1;
	for(int i=2;i<=n;i++){
		if(!pri[i])pri[++pri[0]]=i,phi[i]=i-1;
		for(int j=1;j<=pri[0]&&i*pri[j]<=n;j++){
			pri[i*pri[j]]=true;
			if(!(i%pri[j])){phi[i*pri[j]]=phi[i]*pri[j];break;}
			phi[i*pri[j]]=phi[i]*phi[pri[j]];
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	getphi();
	for(int i=2;i<=n;i++)tot+=phi[i];
//	printf("%d\n",tot);
	if(m>tot||m<n-1){puts("Impossible");return 0;}
	m-=n-1;
	puts("Possible");
	for(int i=2;i<=n;i++)printf("%d %d\n",i-1,i);
	if(!m)return 0;
	for(int i=2;i<=n;i++)for(int j=1;j<i-1;j++){
		if(__gcd(i,j)!=1)continue;
		m--,printf("%d %d\n",i,j);
		if(!m)return 0;
	}
	return 0;
}
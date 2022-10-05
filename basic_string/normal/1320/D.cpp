#include<bits/stdc++.h>
using namespace std;
const int B=(srand(time(0)),rand()^(rand()+rand()*rand())&rand())%111+5,P1=998244347,P2=998244349,N=2e5+5;
int p1[N],p2[N],h1[N],h2[N],g1[N],g2[N],d[N];
char s[N];
inline int hs1(int l,int r){
	if(l&1)return((g1[r]-g1[l-1]*1ll*p1[d[r]-d[l-1]])%P1+P1)%P1;
	return((h1[r]-h1[l-1]*1ll*p1[d[r]-d[l-1]])%P1+P1)%P1;
}
inline int hs2(int l,int r){
	if(l&1)return((g2[r]-g2[l-1]*1ll*p2[d[r]-d[l-1]])%P2+P2)%P2;
	return((h2[r]-h2[l-1]*1ll*p2[d[r]-d[l-1]])%P2+P2)%P2;
}
int main(){
	int n,q,i,j,k;
	scanf("%d%s%d",&n,s+1,&q),p1[0]=p2[0]=1;
	for(i=1;i<=n;++i){
		p1[i]=p1[i-1]*1ll*B%P1,p2[i]=p2[i-1]*1ll*B%P2;
		if(s[i]=='0'){
			d[i]=d[i-1]+1;
			h1[i]=(h1[i-1]*1ll*B+(i&1)+2)%P1;
			h2[i]=(h2[i-1]*1ll*B+(i&1)+2)%P2;
			g1[i]=(g1[i-1]*1ll*B+(i&1^1)+2)%P1;
			g2[i]=(g2[i-1]*1ll*B+(i&1^1)+2)%P2;
		}else d[i]=d[i-1],h1[i]=h1[i-1],h2[i]=h2[i-1],g1[i]=g1[i-1],g2[i]=g2[i-1];
	}
	while(q--){
		scanf("%d%d%d",&i,&j,&k);
		puts((hs1(i,i+k-1)==hs1(j,j+k-1)&&hs2(i,i+k-1)==hs2(j,j+k-1))?"Yes":"No");
	}
	return 0;
}
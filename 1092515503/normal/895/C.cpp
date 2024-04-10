#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,pri[22]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67},tot,pov[100100],d[20];
bool ins(int x){
	for(int i=20;i>=0;i--){
		if(!(x&(1<<i)))continue;
		if(d[i])x^=d[i];
		else{d[i]=x;return true;}
	}
	return false;
}
int main(){
	scanf("%d",&n),pov[0]=1;
	for(int i=1,x,y;i<=n;i++){
		scanf("%d",&x),y=0;
		for(int j=0;j<19;j++){
			if(x%pri[j])continue;
			int z=0;
			while(!(x%pri[j]))x/=pri[j],z^=1;
			y|=(z<<j);
		}
		tot+=ins(y);
		pov[i]=(pov[i-1]<<1)%mod;
	}
	printf("%d\n",pov[n-tot]-1);
	return 0;
}
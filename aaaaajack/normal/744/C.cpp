#include<bits/stdc++.h>
using namespace std;
int mb[1<<16][256];
int rc[1<<16],bc[1<<16];
int r[16],b[16];
char c[16];
inline int umax(int &a,int b){
	return a=max(a,b);
}
inline int umin(int &a,int b){
	return a=min(a,b);
}
int main(){
	int n,ans=1e9,sr=0,sb=0;
	memset(mb,-1,sizeof(mb));
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf(" %c%d%d",&c[i],&r[i],&b[i]);
		sr+=r[i],sb+=b[i];
	}
	for(int i=1;i<(1<<n);i++){
		int lb=__lg(i&-i);
		rc[i]=rc[i^(i&-i)];
		bc[i]=bc[i^(i&-i)];
		if(c[lb]=='R') rc[i]++;
		else bc[i]++;
	}
	mb[0][0]=0;
	for(int i=1;i<(1<<n);i++){
		for(int j=0;j<n;j++){
			if(i&(1<<j)){
				int pr=rc[i^(1<<j)],pb=bc[i^(1<<j)];
				for(int k=0;k<256;k++){
					if(mb[i^(1<<j)][k]<0) continue;
					umax(mb[i][k+min(pr,r[j])],mb[i^(1<<j)][k]+min(pb,b[j]));
				}
			}
		}
	}
	for(int i=0;i<256;i++){
		if(mb[(1<<n)-1][i]<0) continue;
		umin(ans,max(sr-i,sb-mb[(1<<n)-1][i]));
	}
	printf("%d\n",ans+n);
	return 0;
}
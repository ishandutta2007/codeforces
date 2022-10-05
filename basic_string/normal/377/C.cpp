#include<bits/stdc++.h>
using namespace std;
int s[109],f[1200009],t[29];
char b[29];
inline void Max(int&x,int y){
	if(x<y)x=y;
}
inline void Min(int&x,int y){
	if(x>y)x=y;
}
int main(){
	int n,m,i,j,k;
	scanf("%d",&n);
	for(i=0;i<n;++i)scanf("%d",s+i);
	sort(s,s+n,greater<int>());
	scanf("%d",&m);
	for(i=1;i<=m;++i)scanf(" %c%d",b+i,t+i);
	for(i=(1<<m)-2;i>=0;--i){
		k=__builtin_popcount(i)+1;
		if(t[k]==1)f[i]=-1e9;else f[i]=1e9;
	}
	for(i=(1<<m)-1;i;--i){
		k=__builtin_popcount(i);
		if(b[k]=='p'){
			if(t[k]==1){
				for(j=0;j<m;++j)if(i&(1<<j)){
					Max(f[i^(1<<j)],f[i]+s[j]);
				}
			}else{
				for(j=0;j<m;++j)if(i&(1<<j)){
					Min(f[i^(1<<j)],f[i]-s[j]);
				}
			}
		}else{
			if(t[k]==1){
				for(j=0;j<m;++j)if(i&(1<<j)){
					Max(f[i^(1<<j)],f[i]);
				}
			}else{
				for(j=0;j<m;++j)if(i&(1<<j)){
					Min(f[i^(1<<j)],f[i]);
				}
			}
		}
	}
	printf("%d",f[0]);
	return 0;
}
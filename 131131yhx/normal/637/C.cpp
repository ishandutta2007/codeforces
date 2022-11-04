#include<cstdio>
#include<cstring>
#include<algorithm>
char p[1010][7];
inline int ek(int j,int k){
	int ans=0;
	for(int i=0;i<6;++i) if(p[j][i]!=p[k][i])++ans;
	return ans;
}
int main(){
	int n; scanf("%d",&n);
	for(int i=0;i<n;++i) scanf("%s",p[i]);
	int lmax=6;
	for(int i=0;i<n;++i) for(int j=i+1;j<n;++j){
		lmax=std::min(lmax,(ek(i,j)-1)/2);
	}
	printf("%d\n",lmax);
	return 0;
}
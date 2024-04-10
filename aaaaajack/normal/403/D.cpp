#include<cstdio>
#define Q 1000000007
using namespace std;
int dp[2010][1010]={0},dp2[1010][1010]={0};
int cmb(int a,int b){
	if(b<0||a<b) return 0;
	if(b==0||b==a) return 1;
	if(a-b<b) return cmb(a,a-b);
	if(dp[a][b]) return dp[a][b];
	return dp[a][b]=(cmb(a-1,b)+cmb(a-1,b-1))%Q;
}
int h(int k,int n){
	if(n<0) return 0;
	return cmb(k+n-1,n);
}
int main(){
	int i,j,l,t,n,k,ans,temp;
	int fact[1010];
	fact[0]=1;
	for(i=1;i<1010;i++){
		fact[i]=1LL*fact[i-1]*i%Q;
	}
	for(l=0;l<1010;l++){
		dp2[l][1]=1;
		for(i=2;i<1010;i++){
			for(j=0;l-j*i>=0;j++){
				dp2[l][i]+=dp2[l-j*i][i-1];
				dp2[l][i]%=Q;
			}
		}
	}
	scanf("%d",&t);
	while(t--){
		ans=0;
		scanf("%d%d",&n,&k);
		n-=k;
		n-=k*(k-1)/2;
		for(i=0;i<=n;i++){
			temp=fact[k];
			temp=1LL*temp*h(k+1,i)%Q;
			temp=1LL*temp*dp2[n-i][k]%Q;
			ans+=temp;
			ans%=Q;
		}
		printf("%d\n",ans);
	}
	return 0;
}
#include<cstdio>
using namespace std;
long long dp[100][100]={0};
long long cmb(int n,int m){
	if(n<m||m<0) return 0;
	if(n==m||m==0) return 1;
	if(dp[n][m]) return dp[n][m];
	return dp[n][m]=cmb(n-1,m)+cmb(n-1,m-1);
}
int main(){
	long long m,n=0,i,j,cnt=0;
	int k,t=59,r,l;
	scanf("%I64d %d",&m,&k);
	l=k;
	if(m==0||k==1){
		printf("1\n");
	}
	else{
		k--;
		while(m){
			if(cmb(t,k)<=m){
				m-=cmb(t,k);
				n|=(1LL<<t);
				k--;
			}
			t--;
		}
		printf("%I64d\n",n);
	}
	/*for(i=n+1;i<=2*n;i++){
		r=0;
		j=i;
		while(j){
			j-=j&-j;
			r++;
		}
		if(r==l) cnt++;
	}
	printf("%I64d\n",cnt);*/
	return 0;
}
#include<bits/stdc++.h>
#define Q 31607
using namespace std;
int a[21][21];
int sign[1<<21];
int prob_row[1<<21][21];
int prob_col[21];
int prod_prob_col[1<<21];
int inv[Q];
int calc_inv(int x){
	int r=1,y=Q-2;
	while(y){
		if(y&1) r=r*x%Q;
		x=x*x%Q;
		y>>=1;
	}
	return r;
}
int no_row(int b[],int n){
	int r=1;
	for(int i=0;i<n;i++){
		r=r*(Q+1-b[i])%Q;
	}
	return r;
}
int calc_prob(int n){
	for(int i=0;i<n;i++){
		prob_col[i]=1;
		for(int j=0;j<n;j++){
			prob_col[i]*=a[i][j];
			prob_col[i]%=Q;
		}
	}
	for(int j=0;j<n;j++){
		prob_row[0][j]=1;
		for(int i=0;i<n;i++){
			prob_row[0][j]*=a[i][j];
			prob_row[0][j]%=Q;
		}
	}
	prod_prob_col[0]=1;
	int ans=(Q+1-no_row(prob_row[0],n))%Q;
	for(int i=1;i<(1<<n);i++){
		int lb=(i&-i);
		prod_prob_col[i]=prod_prob_col[i^lb]*prob_col[__lg(lb)]%Q;
		for(int j=0;j<n;j++){
			prob_row[i][j]=prob_row[i^lb][j]*inv[a[__lg(lb)][j]]%Q;
		}
		ans+=sign[i]*prod_prob_col[i]%Q*no_row(prob_row[i],n)%Q;
		ans%=Q;
	}
	return ans;
}
int main(){
	for(int i=1;i<Q;i++) inv[i]=calc_inv(i);
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&a[i][j]);
			a[i][j]*=inv[10000];
			a[i][j]%=Q;
		}
	}
	sign[0]=Q-1;
	for(int i=1;i<(1<<n);i++){
		sign[i]=Q-sign[i^(i&-i)];
	}
	int ans=calc_prob(n);
	int prob_d=1,prob_ad=1,prob_bd;
	int d[21];
	for(int i=0;i<n;i++){
		d[i]=1;
		prob_d*=a[i][i];
		prob_d%=Q;
		prob_ad*=a[i][n-1-i];
		prob_ad%=Q;
	}
	prob_bd=prob_d*prob_ad%Q;
	if(n&1){
		prob_bd=prob_bd*inv[a[n/2][n/2]]%Q;
		//printf("inv=%d\n",inv[a[n/2][n/2]]);
	}
	for(int i=0;i<n;i++) swap(a[i][i],d[i]);
	ans+=prob_d*(Q+1-calc_prob(n))%Q;
	for(int i=0;i<n;i++) swap(a[i][i],d[i]);
	for(int i=0;i<n;i++) a[i][n-1-i]=1;
	ans+=prob_ad*(Q+1-calc_prob(n))%Q;
	for(int i=0;i<n;i++) a[i][i]=1;
	ans-=prob_bd*(Q+1-calc_prob(n))%Q;
	ans%=Q;
	if(ans<0) ans+=Q;
	printf("%d\n",ans);
	return 0;
}
#include<cstdio>
#include<algorithm>
using namespace std;
int fac[10]={1,1,2,6,24,120,720,5040,40320};
double p[10][720];
int encode(int *a,int n){
	bool used[10]={};
	int i,j,k,r=0;
	for(i=0;i<n;i++){
		k=0;
		for(j=0;j<a[i];j++){
			if(!used[j]) k++;
		}
		r+=k*fac[n-1-i];
		used[a[i]]=true;
	}
	return r;
}
void decode(int *a,int n,int c){
	bool used[10]={};
	int i,j,k;
	for(i=0;i<n;i++){
		k=0;
		for(j=0;k<c/fac[n-1-i];j++){
			if(!used[j]) k++;
		}
		while(used[j]) j++;
		used[j]=true;
		a[i]=j;
		c%=fac[n-1-i];
	}
}
int count(int *a,int n){
	int i,j,r=0;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(a[i]>a[j]) r++;
		}
	}
	return r;
}
int main(){
	int i,j,n,k,l,r,a[10];
	double ans=0;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++) scanf("%d",&a[i]),a[i]--;
	p[0][encode(a,n)]=1;
	for(i=0;i<k;i++){
		for(j=0;j<fac[n];j++){
			decode(a,n,j);
			for(l=0;l<n;l++){
				for(r=l;r<n;r++){
					reverse(a+l,a+r+1);
					p[i+1][encode(a,n)]+=p[i][j]*2.0/n/(n+1);
					reverse(a+l,a+r+1);
				}
			}
		}
	}
	for(i=0;i<fac[n];i++){
		decode(a,n,i);
		ans+=p[k][i]*count(a,n);
	}
	printf("%.12f\n",ans);
	return 0;
}
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#define N 1001000
using namespace std;
int pl[30],pr[30];
long long cl[N][16],cr[N][16];
int x[N];
int main(){
	int n,a,b,lc=0,rc=0;
	long long ans=-1;
	scanf("%d%d%d",&n,&a,&b);
	for(int i=0;i<n;i++) scanf("%d",&x[i]);
	for(int i=-1;i<=1;i++){
		int tmp=x[0]+i;
		for(int j=2;j*j<=tmp;j++){
			if(tmp%j==0){
				while(tmp%j==0) tmp/=j;
				pl[lc++]=j;
			}
		}
		if(tmp>1){
			pl[lc++]=tmp;
		}
		tmp=x[n-1]+i;
		for(int j=2;j*j<=tmp;j++){
			if(tmp%j==0){
				while(tmp%j==0) tmp/=j;
				pr[rc++]=j;
			}
		}
		if(tmp>1){
			pr[rc++]=tmp;
		}
	}
	sort(pl,pl+lc);
	lc=unique(pl,pl+lc)-pl;
	sort(pr,pr+rc);
	rc=unique(pr,pr+rc)-pr;
	for(int i=0;i<lc;i++){
		if(x[0]%pl[i]==0) cl[0][i]=0;
		else cl[0][i]=b;
	}
	for(int i=0;i<rc;i++){
		if(x[n-1]%pr[i]==0) cr[n-1][i]=0;
		else cr[n-1][i]=b;
	}
	for(int i=1;i<n;i++){
		for(int j=0;j<lc;j++){
			if(cl[i-1][j]<0){
				cl[i][j]=-1;
				continue;
			}
			if(x[i]%pl[j]==0){
				cl[i][j]=cl[i-1][j];
			}
			else if((x[i]+1)%pl[j]==0||(x[i]-1)%pl[j]==0){
				cl[i][j]=cl[i-1][j]+b;
			}
			else cl[i][j]=-1;
		}
	}
	for(int i=n-2;i>=0;i--){
		for(int j=0;j<rc;j++){
			if(cr[i+1][j]<0){
				cr[i][j]=-1;
				continue;
			}
			if(x[i]%pr[j]==0){
				cr[i][j]=cr[i+1][j];
			}
			else if((x[i]+1)%pr[j]==0||(x[i]-1)%pr[j]==0){
				cr[i][j]=cr[i+1][j]+b;
			}
			else cr[i][j]=-1;
		}
	}
	for(int i=1;i<n;i++){
		for(int j=0;j<lc;j++){
			if(cl[i][j]<0||cl[i-1][j]+a<cl[i][j]) cl[i][j]=cl[i-1][j]+a;
		}
	}
	for(int i=n-2;i>=0;i--){
		for(int j=0;j<rc;j++){
			if(cr[i][j]<0||cr[i+1][j]+a<cr[i][j]) cr[i][j]=cr[i+1][j]+a;
		}
	}
	for(int i=0;i<lc;i++){
		if(ans<0||cl[n-1][i]<ans) ans=cl[n-1][i];
	}
	for(int i=0;i<rc;i++){
		if(ans<0||cr[0][i]<ans) ans=cr[0][i];
	}
	for(int i=0,j=0;i<lc&&j<rc;){
		if(pl[i]<pr[j]) i++;
		else if(pl[i]>pr[j]) j++;
		else{
			for(int k=1;k<n-1;k++){
				if(ans<0||cl[k-1][i]+cr[k][j]<ans) ans=cl[k-1][i]+cr[k][j];
			}
			i++,j++;
		}
	}
	printf("%I64d\n",ans);
	return 0;
}
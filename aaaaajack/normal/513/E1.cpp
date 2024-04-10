#include<cstdio>
#include<utility>
#include<algorithm>
#define N 420
#define K 60
using namespace std;
int dpn[N][K],dpp[N][K];
bool check[N][K];
int a[N];
void f(int n,int k){
	if(check[n][k]) return;
	check[n][k]=true;
	int i,mp=0,mn=0;
	if(k==1){
		for(i=n;i>=1;i--){
			mp=max(mp,0)+a[i];
			mn=min(mn,0)+a[i];
			if(i==n){
				dpp[n][k]=mp;
				dpn[n][k]=-mn;
			}
			else{
				dpp[n][k]=max(dpp[n][k],mp);
				dpn[n][k]=max(dpn[n][k],-mn);
			}
		}
		return;
	}
	for(i=n;i>=k;i--){
		mp=max(mp,0)+a[i];
		mn=min(mn,0)+a[i];
		f(i-1,k-1);
		if(i==n){
			dpp[n][k]=max(dpn[i-1][k-1]+mp*2,dpp[i-1][k-1]);
			dpn[n][k]=max(dpp[i-1][k-1]-mn*2,dpn[i-1][k-1]);
		}
		else{
			dpp[n][k]=max(dpp[n][k],max(dpn[i-1][k-1]+mp*2,dpp[i-1][k-1]));
			dpn[n][k]=max(dpn[n][k],max(dpp[i-1][k-1]-mn*2,dpn[i-1][k-1]));
		}
	}
}
int main(){
	int n,k,i,mp=0,mn=0,ans;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=n;i>=k;i--){
		mp=max(mp,0)+a[i];
		mn=min(mn,0)+a[i];
		f(i-1,k-1);
		if(i==n){
			ans=max(dpn[i-1][k-1]+mp,dpp[i-1][k-1]-mn);
		}
		else{
			ans=max(ans,max(mp+dpn[i-1][k-1],dpp[i-1][k-1]-mn));
		}
	}
	printf("%d\n",ans);
	return 0;
}
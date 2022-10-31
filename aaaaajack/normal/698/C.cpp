#include<bits/stdc++.h>
using namespace std;
bool del[20];
double p[20];
double pb[1<<20],sm[1<<20],ans[1<<20];
bool pos[1<<20];
int cnt[1<<20];
int main(){
	int n,k,m,tt=0;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%lf",&p[i]);
		if(p[i]>1e-5) tt++;
	}
	k=min(k,tt);
	pb[0]=1;
	sm[0]=1;
	pos[0]=true;
	for(int i=0;i<(1<<n);i++){
		if(!pos[i]) continue;
		if(cnt[i]==k){
			for(int j=0;j<n;j++){
				if(i&(1<<j)) ans[j]+=pb[i];
			}
		}
		for(int j=0;j<n;j++){
			if(i&(1<<j)||p[j]<1e-6) continue;
			pos[i|1<<j]=true;
			sm[i|1<<j]=sm[i]-p[j];
			cnt[i|1<<j]=cnt[i]+1;
			pb[i|1<<j]+=pb[i]*p[j]/sm[i];
		}
	}
	for(int i=0;i<n;i++) printf("%.8f ",ans[i]);
	puts("");
	return 0;
}
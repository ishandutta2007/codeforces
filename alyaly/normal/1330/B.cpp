#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int T,n,a[200003],h[200003],ffl,np,nq,ans,ans1,ans2;
signed main(){
	cin>>T;
	while(T--){
		ffl=ans=ans1=ans2=np=nq=0;
		memset(h,0,sizeof(h));
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			h[a[i]]++;
			if(h[a[i]]>2){
				if(!ffl) printf("0\n");
				ffl=1;
			}
		}
		if(ffl) continue;
		for(int i=1;i<=n;i++){
			if(h[i]<h[i+1]){
				printf("0\n");
				ffl=1;
				break;
			}else if(h[i]==2&&h[i+1]!=2){
				np=i;
			}else if(h[i]==1&&h[i+1]!=1){
				nq=i;
			}
		}
		if(ffl) continue;
		if(np==0) ffl=1,printf("0\n");
		if(ffl) continue;
		if(nq==0) nq=np;
		memset(h,0,sizeof(h));
		for(int i=1;i<=n;i++){
			h[a[i]]++;
			if(i==np){
				bool nfl=1;
				for(int j=1;j<=n;j++) if((j<=np&&h[j]!=1)||(j>np&&h[j]!=0)){
					nfl=0;break;
				}
				if(nfl) ans1=1;
			}
			if(i==nq&&np!=nq){
				bool nfl=1;
				for(int j=1;j<=n;j++) if((j<=nq&&h[j]!=1)||(j>nq&&h[j]!=0)){
					nfl=0;break;
				}
				if(nfl) ans2=1;
			}
		}
		if(ans1) ans++;
		if(ans2) ans++;
		printf("%d\n",ans);
		if(ans1) printf("%d %d\n",np,nq);
		if(ans2) printf("%d %d\n",nq,np);
	}
	return 0;
}
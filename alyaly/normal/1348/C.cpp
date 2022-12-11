#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int T,n,K,g[257],ng,pg[257];
char a[100001],nn;
string ans;
signed main(){
	cin>>T;
	while(T--){
		nn=0;
		memset(g,0,sizeof(g));
		memset(pg,0,sizeof(pg));
		cin>>n>>K;
		ng=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(!g[a[i]]){
				pg[++ng]=a[i];
			}
			g[a[i]]++;
		}
		sort(a+1,a+n+1);
		sort(pg+1,pg+ng+1);
		bool ffl=0;
		for(int i=2;i<=K;i++){
			if(a[i]!=a[i-1]){
				ffl=1;
				nn=max(nn,a[i]);
			}
		}
		if(ffl) printf("%c\n",nn);
		if(!ffl){
			if(ng==1){
				for(int i=1;i<=g[pg[1]]/K+(g[pg[1]]%K>0);i++){
					printf("%c",pg[1]);
				}
				printf("\n");
			}else if(ng==2){
				if(g[pg[1]]==K){
					for(int i=1;i<=g[pg[1]]/K;i++){
						printf("%c",pg[1]);
					}
					for(int i=1;i<=g[pg[2]]/K+(g[pg[2]]%K>0);i++){
						printf("%c",pg[2]);
					}
					printf("\n");
				}else{
					for(int i=K;i<=n;i++) printf("%c",a[i]);printf("\n");
				}
			}else{
				for(int i=K;i<=n;i++) printf("%c",a[i]);printf("\n");
			}
		}
		
	}
	return 0;
}
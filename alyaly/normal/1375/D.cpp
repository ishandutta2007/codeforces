#include<bits/stdc++.h>
using namespace std;
int qread(){int nans=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')nans=nans*10+c-'0',c=getchar();return nans;}
int T,n,a[2001],h[2001],fl[2001],ans,pans[2001];
int calmex(){
	memset(h,0,sizeof(h));
	for(int i=1;i<=n;i++) h[a[i]]++;
	for(int i=0;i<=n;i++) if(!h[i]) return i;
}
signed main(){
	cin>>T;
	while(T--){
		ans=0;
		cin>>n;for(int i=1;i<=n;i++) cin>>a[i];
		int nt=calmex();
		while(nt<n){
			a[nt+1]=nt;pans[++ans]=nt+1;
			nt=calmex();
		}
		for(int i=1;i<=n;i++){
			int nfl=0;
			if(a[i]==i-1) continue;
			for(int j=i+1;j<=n;j++){
				if(a[j]==i-1){nfl=1;
					pans[++ans]=j;a[j]=calmex();pans[++ans]=i;a[i]=i-1;break;
				}
			}
			if(!nfl){
				pans[++ans]=i;a[i]=i-1;
			}
		}
		printf("%d\n",ans);for(int i=1;i<=ans;i++) printf("%d ",pans[i]);printf("\n");
	}
	return 0;
}
/*

*/
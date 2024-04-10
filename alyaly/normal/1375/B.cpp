#include<bits/stdc++.h>
using namespace std;
int qread(){int nans=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')nans=nans*10+c-'0',c=getchar();return nans;}
int T,n,m,a[1001][1001],ffl,p[1001][1001];
signed main(){
	cin>>T;
	while(T--){
		cin>>n>>m;for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
		ffl=0;
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) p[i-1][j]++,p[i+1][j]++,p[i][j-1]++,p[i][j+1]++;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++) if(a[i][j]>p[i][j]){
				printf("NO\n");ffl=1;break;
			}
			if(ffl) break;
		}
		if(!ffl){printf("YES\n");
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++) printf("%d ",p[i][j]);printf("\n");
			}
			
		}for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) p[i-1][j]--,p[i+1][j]--,p[i][j-1]--,p[i][j+1]--;
	}
	return 0;
}
/*

*/
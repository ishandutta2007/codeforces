#include<bits/stdc++.h>
#include<algorithm>
#define int long long
using namespace std;
int n,m,h[1001],l[1001],mih,mil,mxh,mxl,ans,ffl;
int mx[7]={0,1,-1,0,0},my[7]={0,0,0,1,-1};
char c[1001][1001];
bool fl[1001][1001];
void dfs(int x,int y){
	fl[x][y]=1;
	h[y]++;
	l[x]++;
	mih=min(mih,y);
	mxh=max(mxh,y);
	mil=min(mil,x);
	mxl=max(mxl,x);
	for(int i=1;i<=4;i++){
		if(c[x+mx[i]][y+my[i]]=='#'&&!fl[x+mx[i]][y+my[i]]){
			dfs(x+mx[i],y+my[i]);
		}
	}
	return;
}
signed main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>c[i][j];
			if(c[i][j]=='#'){
				h[i]++;
				l[j]++;
			}
		}
	}
	bool hfl=0,lfl=0;
	for(int i=1;i<=n;i++){
		if(!h[i]){
			hfl=1;
		}
	}
	for(int i=1;i<=m;i++){
		if(!l[i]){
			lfl=1;
		}
	}
	if((int)hfl+(int)lfl==1){
		printf("-1\n");
		return 0;
	}
	for(int i=1;i<=n;i++){
		bool nfl=0;
		for(int j=1;j<=m;j++){
			if(c[i][j]=='#'){
				if(nfl&&c[i][j-1]!='#'){
					ffl=1;
					break;
				}
				nfl=1;
			}
		}
		if(ffl) break;
	}
	for(int i=1;i<=m;i++){
		bool nfl=0;
		for(int j=1;j<=n;j++){
			if(c[j][i]=='#'){
				if(nfl&&c[j-1][i]!='#'){
					ffl=1;
					break;
				}
				nfl=1;
			}
		}
		if(ffl) break;
	}
	if(ffl){
		printf("-1\n");
		return 0;
	}
	for(int i=0;i<=n;i++) fl[i][0]=fl[i][m+1]=1;
	for(int j=0;j<=m;j++) fl[0][j]=fl[n+1][j]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(c[i][j]=='#'&&!fl[i][j]){
				ans++;
				dfs(i,j);
				
			}
		}
	}
	if(ffl) printf("-1\n");
	else printf("%d\n",ans);
	return 0;
}
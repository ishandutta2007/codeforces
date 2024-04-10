#include<bits/stdc++.h>
#include<vector>
#pragma GCC optimize(2)
using namespace std;
int a[2003],dp[2003][2003];
string sdp[2][2001];
int n,K,ans[2003];
vector<pair<int,int> > bi[257];
string s,sn[11]={"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
string tostr(int x){
	string nans;
	for(int i=6;i>=0;i--){
		if(x&(1<<i)) nans+='1';
		else nans+='0';
	}
	return nans;
}
int tonb(string x){
	int nans=0;
	for(int i=0;i<=6;i++){
		if(x[6-i]=='1') nans+=(1<<i);
	}
	return nans;
}
void chk(int x,int y,int ty){
	bool nfl=1;
	int nans=0;
	for(int i=0;i<=6;i++){
		if((x&(1<<i))&&!(y&(1<<i))){
			nfl=0;
			return;
		}else if(!(x&(1<<i))&&(y&(1<<i))){
			nans++;
		}
	}
	bi[x].push_back(make_pair(ty,nans));
	return;
}
void ycl(){
	for(int i=0;i<=127;i++){
		for(int j=0;j<=9;j++){
			chk(i,tonb(sn[j]),j);
		}
	}
	return;
}
signed main(){
	ycl();
	cin>>n>>K;
	for(int i=1;i<=n;i++){
		cin>>s;
		a[i]=tonb(s);
//		for(int j=0;j<=9;j++){
//			if(s==sn[j]){
//				a[i]=j;
//				break;
//			}
//		}
	}
	for(int i=0;i<=n+1;i++) for(int j=0;j<=K;j++) dp[i][j]=-1;
	dp[n+1][0]=0;
//	sdp[0][0]="";
//	string nans;
	for(int i=n;i>=1;i--){
		for(int j=0;j<=K;j++){
//			if(i==2&&j==6){
//				printf("x");
//			}
			for(int k=0;k<bi[a[i]].size();k++){
				if(j-bi[a[i]][k].second>=0&&dp[i+1][j-bi[a[i]][k].second]!=-1&&(dp[i][j]==-1||bi[a[i]][k].first>bi[a[i]][dp[i][j]].first)){
					dp[i][j]=k;
				}
			}
		}
//		for(int j=0;j<=K;j++){
////			sdp[0][j]=sdp[1][j];
////			sdp[1][j].clear();
//			dp[0][j]=dp[1][j];
//			dp[1][j]=-1;
//		}
	}
	if(dp[1][K]==-1) printf("-1\n");
	else{
//		cout<<sdp[0][K]<<endl;
		int nx=1,ny=K;
		while(nx<=n){
			ans[nx]=bi[a[nx]][dp[nx][ny]].first;
			int ni=bi[a[nx]][dp[nx][ny]].second;
			ny-=ni;
			nx++;
		}
		for(int i=1;i<=n;i++) printf("%d",ans[i]);printf("\n");
	}
	return 0;
}
/*

*/
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fz(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define ffe(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
template<typename T> void read(T &x){
	x=0;char c=getchar();T neg=1;
	while(!isdigit(c)){if(c=='-') neg=-1;c=getchar();}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	x*=neg;
}
const int X=15;
const int Y=51;
const int Z=85;
const int MAXN=256;
string dp[11][MAXN+5][3];
void upd(string &x,string y){
	if(x.empty()) x=y;
	else if(x.size()>y.size()) x=y;
	else if(x.size()==y.size()&&x>y) x=y;
}
int main(){
	dp[0][X][2]="x";dp[0][Y][2]="y";dp[0][Z][2]="z";
	for(int i=0;i<10;i++){
		for(int j=0;j<MAXN;j++){
			for(int o=0;o<3;o++) if(!dp[i][j][o].empty()) upd(dp[i+1][j][o],dp[i][j][o]);
			for(int o=0;o<2;o++) if(!dp[i][j][o].empty()) upd(dp[i+1][j][2],"("+dp[i][j][o]+")");
			if(!dp[i][j][2].empty()) upd(dp[i+1][255-j][2],"!"+dp[i][j][2]);
		}
		for(int j=0;j<MAXN;j++) for(int k=0;k<MAXN;k++){
			for(int o=0;o<3;o++) for(int p=1;p<3;p++) if(!dp[i][j][o].empty()&&!dp[i][k][p].empty())
				upd(dp[i+1][j|k][0],dp[i][j][o]+"|"+dp[i][k][p]);
            for(int o=1;o<3;o++) if(!dp[i][j][o].empty()&&!dp[i][k][2].empty())
            	upd(dp[i+1][j&k][1],dp[i][j][o]+"&"+dp[i][k][2]);
		}
	}
	int qu;scanf("%d",&qu);
	while(qu--){
		char opt[10];scanf("%s",opt+1);int msk=0;
		for(int i=1;i<=8;i++) msk=(msk<<1)|(opt[i]^48); 
		string ans;upd(ans,dp[10][msk][0]);upd(ans,dp[10][msk][1]);upd(ans,dp[10][msk][2]);
		cout<<ans<<endl;
	}
	return 0;
}
// xtqqwq
#include<bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template<typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
template<typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
bool can[2][25][365],vis[25][365];

bool dfs(int x,int y){
	if(x==20) return true;
	if(!can[0][x+1][y]&&!vis[x+1][y]){
		vis[x+1][y]=1;
		if(dfs(x+1,y)) return true;
	}
	if(x&&!can[0][x][y]&&!vis[x-1][y]){
		vis[x-1][y]=1;
		if(dfs(x-1,y)) return true;
	}
	if(!can[1][x][(y+1)%360]&&!vis[x][(y+1)%360]){
		vis[x][(y+1)%360]=1;
		if(dfs(x,(y+1)%360)) return true;
	}
	int ty=y-1;
	if(ty<0) ty+=360;
	if(!can[1][x][y]&&!vis[x][ty]){
		vis[x][ty]=1;
		if(dfs(x,ty)) return true;
	}
	return false;
}

void solve(){
	n=readint();
	char str[5]; int x,y,z;
	for(int i=0;i<=20;i++) for(int j=0;j<360;j++) can[0][i][j]=can[1][i][j]=0;
	for(int i=1;i<=n;i++){
		scanf("%s",str); x=readint(); y=readint(); z=readint();
		if(str[0]=='C'){
			if(y<z){
				for(int j=y;j<z;j++) can[0][x][j]=1;
			}
			else{
				for(int j=y;j<360;j++) can[0][x][j]=1;
				for(int j=0;j<z;j++) can[0][x][j]=1;
			}
		}
		else{
			for(int j=x;j<y;j++) can[1][j][z]=1;
		}
	}
	for(int i=0;i<=21;i++) for(int j=0;j<360;j++) vis[i][j]=0;
	vis[0][0]=1;
	if(dfs(0,0)) printf("YES\n");
	else printf("NO\n");
}

int main(){
	int T=readint();
	while(T--) solve();
	return 0;
}
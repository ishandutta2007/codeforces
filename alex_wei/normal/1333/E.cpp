/*
	Templates start.
	Powered by c++11.
	Author : Alex_Wei.
*/

//#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

// IO templates.

char buf[1<<21],*p1=buf,*p2=buf,obuf[1<<23],*O=obuf;
#ifdef __WIN64
	#define gc getchar()
#else
	#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
#endif
#define pc(x) (*O++=x)
#define flush() fwrite(obuf,O-obuf,1,stdout)

inline int read(){
	int x=0,sign=0; char s=getchar();
	while(!isdigit(s))sign|=s=='-',s=getchar();
	while(isdigit(s))x=(x<<1)+(x<<3)+(s-'0'),s=getchar();
	return sign?-x:x;
}
void print(int x) {if(x>9)print(x/10); pc(x%10+'0');}

#define ll long long
#define pii pair <int,int>
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(),x.end()
#define sor(x) sort(all(x))
#define rev(x) reverse(all(x))
#define mem(x,v) memset(x,v,sizeof(x))

/*
	Templates end.
	Please give me more points.
*/

int mt[3][3]={{1,2,4},{5,3,8},{9,6,7}};

void rot(){
	int a[3][3];
	for(int i=0;i<3;i++)for(int j=0;j<3;j++)
		a[i][j]=mt[j][2-i];
	for(int i=0;i<3;i++)for(int j=0;j<3;j++)
		mt[i][j]=a[i][j];
}

int n,vis[505][505],ans[505][505];

int main(){
	cin>>n;
	if(n<3)puts("-1"),exit(0);
	if(n&1)rot();
	else rot(),rot(),rot();
	int x=n,y=1,cnt=0;
	for(int i=0;i<=n+1;i++)
		for(int j=0;j<=n+1;j++)
			if(!i||!j||i>n||j>n)
				vis[i][j]=1;
	for(int i=1;i<=n-3;i++){
		int dir=0;
		while(1){
			vis[x][y]=1,ans[x][y]=++cnt;
			if(i&1){
				if(dir){
					if(y<n)y++;
					else{
						x++;
						break;
					}
				}
				else{
					if(!vis[x-1][y])x--;
					else dir=1,y++;
				}
			}
			else{
				if(dir){
					if(x<n)x++;
					else{
						y++;
						break;
					}
				}
				else{
					if(!vis[x][y-1])y--;
					else dir=1,x++;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(ans[i][j])cout<<ans[i][j]<<" ";
			else cout<<n*n-9+mt[i+2-n][j+2-n]<<" ";
		}
		puts("");
	}
	return 0;
}
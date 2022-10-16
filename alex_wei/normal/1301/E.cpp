#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
 
char buf[1<<23],*p1=buf,*p2=buf,obuf[1<<23],*O=obuf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
#define putchar(x) (*O++=x)
#define flush() fwrite(obuf,O-obuf,1,stdout)
inline int read(){
	int x=0,sign=0; char s=getchar();
	while(!isdigit(s))sign|=s=='-',s=getchar();
	while(isdigit(s))x=(x<<1)+(x<<3)+(s-'0'),s=getchar();
	return sign?-x:x;
}
void print(int x){
    if(x>9)print(x/10);
    putchar(x%10+'0');
}
 
constexpr int N=505,SQ=N*N;
int n,m,q,sq[4][N][N];
int pd[N*N*N>>1];
char mp[N][N];
int cal(int id,int x,int y,int xx,int yy){
	return sq[id][xx][yy]-sq[id][x-1][yy]-sq[id][xx][y-1]+sq[id][x-1][y-1];
}
int pos(int a,int b,int c){return a*SQ+b*N+c;}
int calc2(int sz,int x,int y,int xx,int yy){
	return pd[pos(sz,xx,yy)]-pd[pos(sz,x-1,yy)]-pd[pos(sz,xx,y-1)]+pd[pos(sz,x-1,y-1)];
}
int main(){
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
		mp[i][j]=getchar();
		while(mp[i][j]<'B'||mp[i][j]>'Z')mp[i][j]=getchar();
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
		for(int k=0;k<4;k++)sq[k][i][j]=sq[k][i-1][j]+sq[k][i][j-1]-sq[k][i-1][j-1];
		if(mp[i][j]=='R')sq[0][i][j]++;
		if(mp[i][j]=='G')sq[1][i][j]++;
		if(mp[i][j]=='B')sq[2][i][j]++;
		if(mp[i][j]=='Y')sq[3][i][j]++;
	}
	for(int i=2;i<=min(n,m);i+=2)for(int j=1;j<=n;j++)for(int k=1;k<=m;k++){
		int z=i>>1;
		pd[pos(z,j,k)]+=pd[pos(z,j-1,k)]+pd[pos(z,j,k-1)]-pd[pos(z,j-1,k-1)];
		if(j>n-i+1||k>m-i+1)continue;
		int sz=i*i>>2;
		int a=cal(0,j,k,j+z-1,k+z-1);
		int b=cal(3,j+z,k,j+i-1,k+z-1);
		int c=cal(1,j,k+z,j+z-1,k+i-1);
		int d=cal(2,j+z,k+z,j+i-1,k+i-1);
		pd[pos(z,j,k)]+=a==sz&&b==sz&&c==sz&&d==sz;
	}
	for(int i=1;i<=q;i++){
		int aa=read(),bb=read(),cc=read(),dd=read();
		int sz=min(cc-aa+1,dd-bb+1);
		int l=0,r=(sz-(sz&1))/2;
		while(l<r){
			int m=(l+r>>1)+1;
			if(calc2(m,aa,bb,cc-(m<<1)+1,dd-(m<<1)+1))l=m;
			else r=m-1;
		}
		print(l*l<<2),putchar('\n');
	}
	flush();
    return 0;
}
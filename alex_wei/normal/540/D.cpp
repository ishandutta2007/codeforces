#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair <int,int>
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(),x.end()
#define sor(x) sort(all(x))
#define rev(x) reverse(all(x))
#define mem(x,v) memset(x,v,sizeof(x))

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
void print(int x){
	if(x>9)print(x/10);
	pc(x%10+'0');
}

const int N=105;

int r,s,p;
double f[N][N][N];

int main(){
	cin>>r>>s>>p;
	f[r][s][p]=1;
	for(int i=r;~i;i--)for(int j=s;~j;j--)for(int k=p;~k;k--){
		double rs=i*j,rp=i*k,sp=j*k,tot=rs+rp+sp;
		if(!tot)continue;
		if(i)f[i-1][j][k]+=f[i][j][k]*rp/tot;
		if(j)f[i][j-1][k]+=f[i][j][k]*rs/tot;
		if(k)f[i][j][k-1]+=f[i][j][k]*sp/tot;
	}
	double ar=0,as=0,ap=0;
	for(int i=1;i<N;i++)ar+=f[i][0][0],as+=f[0][i][0],ap+=f[0][0][i];
	printf("%.12lf %.12lf %.12lf",ar,as,ap); 
	return 0;
}
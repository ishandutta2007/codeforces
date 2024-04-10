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

const int N=2e3+5;
const int inf=0x3f3f3f3f;

int n,k,f[N][10],pd[N][N],pre[N][N];
string s[N],mp[10]={"1110111","0010010","1011101",
"1011011","0111010","1101011","1101111","1010010",
"1111111","1111011"};

void solve(){
	cin>>n>>k;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		int tmp=inf;
		for(int j=0;j<10;j++){
			int pd=0,c=0;
			for(int k=0;k<8;k++){
				if(s[i][k]=='1'&&mp[j][k]=='0'){
					pd=1;
					break;
				}
				if(s[i][k]=='0'&&mp[j][k]=='1')c++;
			}
			if(!pd)tmp=min(tmp,c);
			f[i][j]=pd?inf:c;
		}
		if(tmp==inf)puts("-1"),exit(0);
		ans+=tmp;
	}
	if(ans>k)puts("-1"),exit(0);
	pd[n+1][0]=1;
	for(int i=n;i;i--){
		for(int j=k;~j;j--){
			for(int l=9;~l;l--)
				if(j>=f[i][l]&&pd[i+1][j-f[i][l]]){
					pd[i][j]=1,pre[i][j]=l;
					break;
				}
		}
	}
	if(!pd[1][k])puts("-1");
	else{
		int pos=pre[1][k];
		for(int i=1;i<=n;i++)
			k-=f[i][pos],cout<<pos,pos=pre[i+1][k];
	}
}

int main(){
	int t=1;
//	cin>>t;
	while(t--)solve();
	
	return 0;
}
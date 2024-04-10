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

const ll mod=998244353;
const ll N=3e3+5;

ll v[N][N],ans;
string s,t;

bool check(int l,int r){
	if(r<t.size())return s[l]==t[r];
	return 1;
}

void solve(){
	cin>>s>>t;
	for(int i=0;i<s.size();i++)v[i][i]=check(0,i);
	if(t.size()==1)ans=v[0][0];
	for(int i=1;i<s.size();i++){
		int x=0,y=i-1;
		while(y<s.size()){
			if(x&&check(i,x-1))v[x-1][y]=(v[x-1][y]+v[x][y])%mod;
			if(y<s.size()-1&&check(i,y+1))v[x][y+1]=(v[x][y+1]+v[x][y])%mod;
			x++,y++;
		}
		if(i>=t.size()-1)ans=(ans+v[0][i])%mod;
	}
	cout<<ans*2%mod<<endl;
}

int main(){
	int testcase=1;
//	cin>>testcase;
	while(testcase--)solve();
	
	return 0;
}
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

const int N=2e5+5;
const int inf=0x3f3f3f3f;

vector <int> ans;
void solve(){
	string s; int n,k;
	cin>>n>>k>>s; sort(s.begin(),s.end());
	if(k==1){for(int i=0;i<n;i++)cout<<s[i]; puts(""); return;}
	if(s[0]==s[n-1]){
		int l=(n-1)/k+1;
		for(int i=0;i<l;i++)cout<<s[0];
		puts(""); return;
	}
	int m=0,p=0;
	for(int i=0;i<k;i++)if(s[i]-'a'+1>m)m=s[i]-'a'+1,p=i;
	if(p)cout<<s[k-1]<<endl;
	else{
		if(s[k-1]==s[k]||s[n-1]!=s[k]){
			for(int i=k-1;i<n;i++)cout<<s[i];
		}
		else{
			cout<<s[k-1];
			int len=(n-1)/k;
			while(len--)cout<<s[k];
		}
		puts("");
	}
}

int main(){
	int t=1;
	cin>>t;
	while(t--)solve();

	return 0;
}
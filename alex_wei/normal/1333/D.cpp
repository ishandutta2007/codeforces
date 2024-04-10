/*
	Templates start.
	Powered by c++11.
	Author : Alex_Wei.
*/

#pragma GCC optimize(3)

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

const int N=3e3+5;

vector <int> p[N];
int n,k;
string s;

bool check(){
	for(int i=1;i<s.size();i++)
		if(s[i-1]=='R'&&s[i]=='L')
			return true;
	return false; 
}

void solve(){
	cin>>n>>k>>s;
	int cnt=0,tot=0;
	while(check()){
		cnt++;
		for(int i=1;i<s.size();i++)
			if(s[i-1]=='R'&&s[i]=='L')
				p[cnt].pb(i),swap(s[i-1],s[i]),tot++,i++;
	}
	if(k<cnt||tot<k)puts("-1"),exit(0);
	int tmp=cnt;
	for(int i=1;i<=tmp;i++){
		if(cnt==k){
			cout<<p[i].size()<<" ";
			for(int j:p[i])printf("%d ",j);
			puts("");
			continue;
		}
		for(int j=0;j<p[i].size();j++){
			if(cnt<k){
				cnt++;
				printf("1 %d\n",p[i][j]);
				if(j==p[i].size()-1)cnt--;
			}
			else{
				cout<<p[i].size()-j<<" ";
				for(;j<p[i].size();j++)printf("%d ",p[i][j]);
				puts("");
				break;
			}
		}
	}
}

int main(){
	int testcase=1;
	while(testcase--)solve();
	 
	return 0;
}
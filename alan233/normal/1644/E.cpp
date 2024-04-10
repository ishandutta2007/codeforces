// Author: wlzhouzhuan
#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,l,r) for(int i=(l);i>=(r);i--)
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define mset(s,t) memset(s,t,sizeof(s))
#define mcpy(s,t) memcpy(s,t,sizeof(t))
#define SZ(x) ((int)x.size())
#define pb push_back
#define eb emplace_back
#define fir first
#define sec second

template<class T1,class T2>bool ckmax(T1 &a,T2 b){if(a<b)return a=b,1;else return 0;}
template<class T1,class T2>bool ckmin(T1 &a,T2 b){if(a>b)return a=b,1;else return 0;}

inline int read(){
	int x=0,f=0;char ch=getchar();
	while(!isdigit(ch))f|=ch=='-',ch=getchar();
	while(isdigit(ch))x=10*x+ch-'0',ch=getchar();
	return f?-x:x;
}
template<typename T>void print(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>=10)print(x/10);
	putchar(x%10+'0');
}
template<typename T>void print(T x,char ch){
	print(x),putchar(ch);
}

const int N=200005;

char a[N];
int n,len;

void solve(){
	scanf("%d%s",&n,a+1);
	len=strlen(a+1);
	bool allD=1,allR=1;
	rep(i,1,len)allD&=a[i]=='D',allR&=a[i]=='R';
	if(allD||allR)return print(n,'\n'),void();
	if(a[1]=='R'){
		rep(i,1,len)a[i]=a[i]=='R'?'D':'R';
	}
	ll ans=1ll*n*n;
	{
		int high=count(a+1,a+len+1,'D'),now=0;
		// printf("high=%d\n",high);
		rep(i,1,len){
			if(a[i]=='D')now++;
			if(a[i]=='D'&&i<len&&a[i+1]=='R')/*printf("jian %d\n",high-now),*/ans-=high-now;
			if(a[i]=='R'&&i<len&&a[i+1]=='R')/*printf("jian %d\n",high-now),*/ans-=high-now;
		}
	}
	{
		int now=0,ii=1;
		while(a[ii]=='D')ii++;
		ans-=1ll*(ii-1)*(n-1);
		rep(i,ii,len){
			if(a[i]=='D')now++;
			if(a[i]=='R')ans-=now;
			// if(a[i]=='D'&&i>1&&a[i-1]=='R')ans-=now;
		}
	}
	print(ans,'\n');
}

int main(){
	// freopen("data.in","r",stdin);
	int T=read();
	// T=15;
	while(T--)solve();
	return 0;
}
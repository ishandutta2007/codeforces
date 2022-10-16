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

ll sum[100005],cnt[100005],ans;
int n,m;

int main(){
	n=read(),m=read();
	vector a(n+1,vector<int> (m+1));
	rep(i,1,n)
		rep(j,1,m)
			a[i][j]=read();
	rep(i,1,n){
		rep(j,1,m){
			ans+=sum[a[i][j]]-cnt[a[i][j]]*i;
			sum[a[i][j]]+=i,cnt[a[i][j]]++;
		}
	}
	mset(sum,0),mset(cnt,0);
	rep(j,1,m){
		rep(i,1,n){
			ans+=sum[a[i][j]]-cnt[a[i][j]]*j;
			sum[a[i][j]]+=j,cnt[a[i][j]]++;
		}
	}
	print(-ans,'\n');
	return 0;
}
// Author: wlzhouzhuan
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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

const int N=100005;
const int inf=2e9+5;
const int B=23333;

struct node{
	int d[5],val;
	friend bool operator < (const node&x,const node&y){
		return x.val<y.val;
	}
}a[N];

bitset<B> now;
int n,m;

int main(){
	n=read(),m=read();
	rep(i,0,n-1){
		rep(j,0,m-1)a[i].d[j]=read();
		a[i].val=read();
	}
	sort(a,a+n);
	int ans=inf;
	for(int l=0,r=B-1;l<=n;l+=B,r+=B){
		ckmin(r,n-1);
		unordered_map<int,bitset<B>> mp;
		rep(i,l,r){
			rep(j,0,m-1)
				mp[a[i].d[j]].set(i-l);
		}
		rep(i,0,n-1){
			if(a[0].val+a[i].val>=ans)break;
			now.set();
			int pos=0,ok=1;
			rep(j,0,m-1){
				if(mp.count(a[i].d[j]))now&=~mp[a[i].d[j]];
				pos=now._Find_first();
				if(l+pos>r){
					ok=0;break;
				}
			}
			if(ok&&l+pos<=r){
				// printf("i=%d,pos=%d\n",i,i+pos);
				ckmin(ans,a[i].val+a[l+pos].val);
			}
		}
	}
	if(ans==inf)puts("-1");
	else print(ans,'\n');
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>inline void MAX(T &x,T y){if(y>x)x=y;}
template<class T>inline void MIN(T &x,T y){if(y<x)x=y;}
template<class T>inline void rd(T &x){
	x=0;char o,f=1;
	while(o=getchar(),o<48)if(o==45)f=-f;
	do x=(x<<3)+(x<<1)+(o^48);
	while(o=getchar(),o>47);
	x*=f;
}
template<class T>inline void print(T x,int op=1){
	static int top,stk[105];
	if(x<0)x=-x,putchar('-');
	if(x==0)putchar('0');
	while(x)stk[++top]=x%10,x/=10;
	while(top)putchar(stk[top--]+'0');
	if(~op)putchar(" \n"[op]);
}
const int M=1e5+5;
int cas,n,m,cnt[26];
char A[M],B[M];

signed main(){
#ifndef ONLINE_JUDGE
	freopen("jiedai.in","r",stdin);
#endif
	rd(cas);
	while(cas--){
		scanf("%s%s",A+1,B+1);
		n=strlen(A+1);
		m=strlen(B+1);
		for(int i=0;i<26;i++)cnt[i]=0;
		for(int i=1;i<=m;i++)cnt[B[i]-'A']++;
		int now=m;
		for(int i=n;i>=1;i--){
			if(cnt[A[i]-'A']==0)continue;
			cnt[A[i]-'A']--;
			if(A[i]==B[now])now--;
		}
		puts(now==0?"YES":"NO");
	}
	return (0-0);
}
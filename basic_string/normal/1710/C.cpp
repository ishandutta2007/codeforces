#include<bits/stdc++.h>
using namespace std;
char c[200009];
const int P=998244353;
int F[2][2][2][2][2][2],G[2][2][2][2][2][2];
int main(){ios::sync_with_stdio(0);cin.tie(0);
	auto f=F,g=G;
	int n,i,j;
	cin>>(c+1),n=strlen(c+1);
	f[0][0][0][1][1][1]=1;
	for(i=1;i<=n;++i){
		swap(f,g),memset(f,0,sizeof F);
	if(c[i]=='1'){
		for(int a0=0;a0<2;++a0)
		for(int a1=0;a1<2;++a1)
		for(int a2=0;a2<2;++a2)
		for(int b0=0;b0<2;++b0)
		for(int b1=0;b1<2;++b1)
		for(int b2=0;b2<2;++b2)if(j=g[a0][a1][a2][b0][b1][b2]){
			for(int e0=0;e0<2;++e0)
			for(int e1=0;e1<2;++e1)
			for(int e2=0;e2<2;++e2){
				int c0=a0,c1=a1,c2=a2;
				if(e0!=e2){
					if(e0==e1)c2=1;
					else c0=1;
				}else if(e0!=e1)c1=1;
				(f[c0][c1][c2][b0&e0][b1&e1][b2&e2]+=j)%=P;
			}
		}
	}else{
		for(int a0=0;a0<2;++a0)
		for(int a1=0;a1<2;++a1)
		for(int a2=0;a2<2;++a2)
		for(int b0=0;b0<2;++b0)
		for(int b1=0;b1<2;++b1)
		for(int b2=0;b2<2;++b2)if(j=g[a0][a1][a2][b0][b1][b2]){
			
			for(int e0=0;e0<2;++e0)
			for(int e1=0;e1<2;++e1)
			for(int e2=0;e2<2;++e2){
				int c0=a0,c1=a1,c2=a2;
				if(e0!=e2){
					if(e0==e1)c2=1;
					else c0=1;
				}else if(e0!=e1)c1=1;
				if((b0&&e0)||(b1&&e1)||(b2&&e2))continue;
				(f[c0][c1][c2][b0][b1][b2]+=j)%=P;
			}
		}
	}
}
int ans=0;
for(int b0=0;b0<2;++b0)
		for(int b1=0;b1<2;++b1)
		for(int b2=0;b2<2;++b2)(ans+=f[1][1][1][b0][b1][b2])%=P;
		cout<<ans;
}
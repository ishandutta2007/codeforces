#include<bits/stdc++.h>
using namespace std;
enum{N=500009};
int n,m,k;
char s[N],t[N];
struct P{
	int p[N],mn[N];
	void wk(){
		int i,j;
		for(i=2,j=0,memset(mn,9,N*4);i<=m;++i){
			while(j&&t[j+1]!=t[i])j=p[j];
			if(t[j+1]==t[i])p[i]=++j;
		}
		for(i=1,j=0;i<=n;++i){
			while(j&&t[j+1]!=s[i])j=p[j];
			if(t[j+1]==s[i])++j;
			if(i>=k)mn[j]=min(mn[j],i);
			if(j==m){
				if(i<k)cout<<"Yes\n1 "<<k+1,exit(0);
				if(i-m>n-k)cout<<"Yes\n"<<n-k-k+1<<' '<<n-k+1,exit(0);
			}
		}
		for(i=m;i;--i)mn[p[i]]=min(mn[p[i]],mn[i]);
	}
}A,B;
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int i;
	cin>>n>>m>>k>>s+1>>t+1,A.wk();
	reverse(s+1,s+n+1),reverse(t+1,t+m+1),B.wk();
	for(i=0;i<=m&&i<=k;++i)if(m-i<=k&&A.mn[i]+B.mn[m-i]<=n)return cout<<"Yes\n"<<A.mn[i]-k+1<<' '<<n-B.mn[m-i]+1,0;
	cout<<"No";
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool chmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool chmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=5010;
int cnt,m,n,t_case;
string s[maxn],t;
int main(){
	cin>>n>>m>>t;
	for(ri i=min(n,m);i;--i){
		++cnt;
		for(ri j=1,k=1;k<=m;++k){
			s[cnt]+=t[j-1];
			if(j==i)j=1;
			else ++j;
		}
	}
	sort(s+1,s+cnt+1);
	cout<<s[1];
	return 0;
}
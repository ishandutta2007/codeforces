/*
	Powered by C++11.
	Author : Alex_Wei.
*/

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair <int,int>;

#define fi first
#define se second
#define mpi make_pair
#define pb emplace_back
#define mcpy(x,y) memcpy(x,y,sizeof(y))

const int L=2e6+5;
const int N=1e5+5;
const int mod=1e9+7;

void add(ll &x,int y){
	x+=y; if(x>=mod)x-=mod;
}

ull hs1[L],hs2[L],p[L];
ull q1(int l,int r){
	return hs1[r]-hs1[l-1]*p[r-l+1];
} ull q2(int l,int r){
	return hs2[r]-hs2[l-1]*p[r-l+1];
}

int n,q,len,mxlen;
ll f[N][26],pw[N],iv[N],ans[N];
char s[L],t[N];
string qs[N];
vector <pii> qu[L];

int main(){
	scanf("%d%d%s%s",&n,&q,s+1,t+1),pw[0]=p[0]=iv[0]=1;
	for(int i=1;i<=n;i++)pw[i]=pw[i-1]*2%mod,iv[i]=iv[i-1]*(mod+1>>1)%mod;
	for(int i=1;i<L;i++)p[i]=p[i-1]*131;
	for(int i=n;i;i--){
		for(int j=0;j<26;j++)f[i][j]=f[i+1][j];
		add(f[i][t[i]-'a'],pw[n-i]);
	} for(int i=1;i<=q;i++){
		int id; cin>>id>>qs[i],mxlen=max(mxlen,(int)qs[i].size());
		qu[qs[i].size()].pb(mpi(i,id));
	} int pre=0,pos=0; len=strlen(s+1);
	while(1){
		for(int i=1;i<=len;i++)hs1[i]=hs1[i-1]*131+s[i];
		for(int l=pre+1;l<=len;l++)for(pii it:qu[l]){
			string t=qs[it.fi]; int id=it.fi,k=it.se,slen=t.size();
			if(k<pos)continue;
			for(int i=1;i<=slen;i++)hs2[i]=hs2[i-1]*131+t[i-1];
			ull ap=0,hs=hs2[slen];
			for(int i=slen;i<=len;i++)ap+=q1(i-slen+1,i)==hs;
			ans[id]=ap*pw[k-pos]%mod;
			for(int i=1;i<=slen;i++){
				int l=i-1,r=slen-i,it=t[i-1]-'a';
				if(q1(len-l+1,len)==q2(1,l)&&q1(1,r)==q2(slen-r+1,slen))
					add(ans[id],(f[pos+1][it]-f[k+1][it]+mod)*iv[n-k]%mod);
			} 
		} if(len>=mxlen)break;
		for(int i=1;i<=len;i++)s[len+i+1]=s[i];
		s[len+1]=t[++pos],pre=len,len=(len<<1)+1; 
	} for(int i=1;i<=q;i++)cout<<ans[i]<<"\n";
	return 0;
}
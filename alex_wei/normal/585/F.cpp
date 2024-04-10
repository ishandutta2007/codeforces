#include <bits/stdc++.h>
using namespace std;
//
#define db double
#define ll long long
#define ld long double
#define ull unsigned long long

#define pii pair <int,int>
#define fi first
#define se second
#define pb push_back
#define mem(x,v,s) memset(x,v,sizeof(x[0])*(s))
#define cpy(x,y,s) memcpy(x,y,sizeof(x[0])*(s))

const int N=5e4+5;
const ll mod=1e9+7;
void add(ll &x,ll y){x=(x+y)%mod;}

int node,son[N][10],fa[N],ed[N];
void ins(string s){
	int p=0;
	for(char it:s){
		if(!son[p][it-'0'])son[p][it-'0']=++node;
		p=son[p][it-'0'];
	} ed[p]=1;
}
void build(){
	queue <int> q;
	for(int i=0;i<10;i++)if(son[0][i])q.push(son[0][i]);
	while(!q.empty()){
		int t=q.front(); q.pop();
		for(int i=0;i<10;i++)
			if(son[t][i])fa[son[t][i]]=son[fa[t]][i],q.push(son[t][i]);
			else son[t][i]=son[fa[t]][i];
		ed[t]|=ed[fa[t]];
	}
}

string s,x,y;
ll n,d,len,f[N>>9][N][2];
int dg[N],le;
ll calc(string c){
	for(int i=0;i<d;i++)dg[i]=c[i]-'0';
	mem(f,0,N>>9),f[0][0][1]=1;
	for(int i=0;i<d;i++){
		int sumd=0;
		for(int j=0;j<=node;j++){
			if(!ed[j])for(int k=0;k<10;k++){
				if(i==0&&k==0)continue;
				if(ed[son[j][k]])continue;
				add(f[i+1][son[j][k]][0],f[i][j][0]);
				if(k<dg[i])add(f[i+1][son[j][k]][0],f[i][j][1]);
				else if(k==dg[i])add(f[i+1][son[j][k]][1],f[i][j][1]);
			} sumd+=f[i][j][0]+f[i][j][1];
		}
	}
	ll ans=0;
	for(int i=0;i<=node;i++)if(!ed[i])
		add(ans,f[d][i][0]),add(ans,f[d][i][1]);
	return ans;
	
}
ll tonum(string s){
	ll res=0;
	for(int i=0;i<s.size();i++)res=res*10%mod+s[i]-'0';
	return res;
}
bool run(string s){
	int p=0;
	for(char it:s){
		p=son[p][it-'0'];
		if(ed[p])return 1;
	} return 0;
}
int main(){
	cin>>s>>x>>y;
	n=s.size(),d=x.size(),len=d>>1;
	for(int i=0;i<n;i++)if(i+len<=n)ins(s.substr(i,len));
	build(); ll num=tonum(y)-tonum(x)-calc(y)+calc(x)+mod*2;
	cout<<(num+run(x))%mod<<endl;
	return 0;
}
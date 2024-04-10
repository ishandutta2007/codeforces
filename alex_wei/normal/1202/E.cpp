/*
	Powered by C++11.
	Author : Alex_Wei.
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(),x.end()
#define rev(x) reverse(all(x))

const int N=2e5+5;
const int S=26;

struct ACAM{
	int cnt,f[N],son[N][S],ed[N];
	void ins(string s){
		int p=0;
		for(char it:s){
			if(!son[p][it-'a'])son[p][it-'a']=++cnt;
			p=son[p][it-'a'];
		} ed[p]++;
	} void build(){
		queue <int> q;
		for(int i=0;i<26;i++)if(son[0][i])q.push(son[0][i]);
		while(!q.empty()){
			int t=q.front(); q.pop();
			for(int i=0;i<26;i++)
				if(son[t][i])f[son[t][i]]=son[f[t]][i],q.push(son[t][i]);
				else son[t][i]=son[f[t]][i];
			ed[t]+=ed[f[t]];
		}
	}
}a,b;

ll n,ans,s[N];
string t;

int main(){
	cin>>t>>n;
	for(int i=1;i<=n;i++){
		string s; cin>>s;
		a.ins(s),rev(s),b.ins(s);
	} a.build(),b.build();
	for(int i=1,p=0;i<=t.size();i++)
		p=a.son[p][t[i-1]-'a'],s[i]=a.ed[p];
	for(int i=t.size(),p=0;i;i--)
		p=b.son[p][t[i-1]-'a'],ans+=s[i-1]*b.ed[p];
	cout<<ans<<endl;
	return 0;
}
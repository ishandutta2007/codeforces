/*
Criteria:
1.read the problem carefully; WRITE DOWN SPECIAL CONSTRAINTS when the problem is long;
2.consider special situations/constraints to get observations;
3.think of everything throughout before coding;
4.return to the initial list of notifications after coding.

CONSTRAINTS:

OBSERVATIONS:

OTHER NOTIFICATIONS:

THINK CAREFULLY AND CODE DETERMINEDLY!
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,las[300100];
ll s[2][300100];
map<ll,int>mp[3];
vector<pair<int,int> >u,v,w;
bool cmp(pair<int,int>&u,pair<int,int>&v){
	if(u.first==v.first)return u.second>v.second;
	return u.first<v.first;
}
int ju[300100],jv[300100];
int U[300100],V[300100];
map<pair<int,int>,int>pm;
int f[300100];
void chmx(int&x,int y){if(x<y)x=y;}
int calc(int p,int q){
	if(p==-1||q==-1)return 0;
	if(pm.find(make_pair(p,q))!=pm.end())return pm[make_pair(p,q)];
	int&x=pm[make_pair(p,q)];x=f[min(u[p].first,v[q].first)-1]+2;
	if(u[p].first<v[q].first){
		if(jv[q]==-1||v[jv[q]].second<u[p].first)return x;
		chmx(x,calc(p,jv[q])+1);
	}
	if(u[p].first>v[q].first){
		if(ju[p]==-1||u[ju[p]].second<v[q].first)return x;
		chmx(x,calc(ju[p],q)+1);
	}
	return x;
}
int main(){
	scanf("%d",&n);
	for(int _=0;_<2;_++)for(int i=1;i<=n;i++)scanf("%lld",&s[_][i]),s[_][i]+=s[_][i-1];
	mp[0][0]=mp[1][0]=mp[2][0]=0;
	memset(las,-1,sizeof(las));
	for(int i=1;i<=n;i++){
		if(mp[0].find(s[0][i])!=mp[0].end())u.emplace_back(mp[0][s[0][i]]+1,i);
		if(mp[1].find(s[1][i])!=mp[1].end())v.emplace_back(mp[1][s[1][i]]+1,i);
		if(mp[2].find(s[0][i]+s[1][i])!=mp[2].end())las[i]=mp[2][s[0][i]+s[1][i]];
		mp[0][s[0][i]]=i;
		mp[1][s[1][i]]=i;
		mp[2][s[0][i]+s[1][i]]=i;
	}
	// for(auto x:u)printf("[%d,%d]",x.first,x.second);puts("");
	// for(auto x:v)printf("[%d,%d]",x.first,x.second);puts("");
	sort(u.begin(),u.end(),cmp);for(auto x:u){
		while(!w.empty()&&w.back().second>=x.second)w.pop_back();
		w.push_back(x);
	}u=w,w.clear();
	sort(v.begin(),v.end(),cmp);for(auto x:v){
		while(!w.empty()&&w.back().second>=x.second)w.pop_back();
		w.push_back(x);
	}v=w,w.clear();
	memset(U,-1,sizeof(U));
	for(int i=0,j=-1;i<u.size();i++){
		while(u[j+1].second<u[i].first)j++;
		ju[i]=j,U[u[i].second]=i;
	}
	for(int i=1;i<=n;i++)if(U[i]==-1)U[i]=U[i-1];
	memset(V,-1,sizeof(V));
	for(int i=0,j=-1;i<v.size();i++){
		while(v[j+1].second<v[i].first)j++;
		jv[i]=j,V[v[i].second]=i;
	}
	for(int i=1;i<=n;i++)if(V[i]==-1)V[i]=V[i-1];
	// for(auto x:u)printf("[%d,%d]",x.first,x.second);puts("");
	// for(auto x:v)printf("[%d,%d]",x.first,x.second);puts("");
	for(int i=1;i<=n;i++){
		// printf("FUFU:%d,%d\n",U[i],V[i]);
		f[i]=f[i-1];
		if(las[i]!=-1)chmx(f[i],f[las[i]]+1);
		if(U[i]!=-1)chmx(f[i],f[u[U[i]].first-1]+1);
		if(V[i]!=-1)chmx(f[i],f[v[V[i]].first-1]+1);
		chmx(f[i],calc(U[i],V[i]));
		// printf("%d:%d\n",i,f[i]);
	}
	printf("%d\n",f[n]);
	return 0;
}
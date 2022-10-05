#include<bits/stdc++.h>
using namespace std;
using ui=unsigned;
const ui N=1e5+3,inf=4e9;
set<pair<ui,ui>>s[N];
set<tuple<ui,ui,ui>>a;
map<pair<ui,ui>,ui>mp;
void add(ui x){
	ui i=0,y,j;
	for(auto o=s[x].begin();o!=s[x].end()&&i<3;++o,++i){
		j=0;
		for(auto u=s[y=o->second].begin();u!=s[y].end()&&j<3;++u,++j)if(u->second==x){
			a.emplace(o->first,x,y);
			break;
		}
	}
}
void del(ui x){
	ui i=0;
	for(auto o=s[x].begin();o!=s[x].end()&&i<3;++o,++i)a.erase(make_tuple(o->first,x,o->second));
}
void add(ui x,ui y,ui z){del(x),mp[{x,y}]=z,s[x].emplace(z,y);}
void ad(ui x,ui y,ui z){add(x,y,z),add(y,x,z),add(x),add(y);}
void del(ui x,ui y){del(x),s[x].erase({mp[{x,y}],y});}
void de(ui x,ui y){del(x,y),del(y,x),add(x),add(y);}
ui get(ui x){
	if(s[x].size()<3)return inf;
	ui i=0,w=0;
	for(auto o=s[x].begin();i<3;++o,++i)w+=o->first;
	return w;
}
ui g1(ui x,ui y){
	if(s[x].size()<2||s[y].size()<2)return inf;
	auto o1=++s[x].begin(),o2=++s[y].begin();
	if(o1->second!=o2->second)return o1->first+o2->first;
	ui w=inf;
	if(s[x].size()>2)w=next(o1)->first+o2->first;
	if(s[y].size()>2)w=min(w,o1->first+next(o2)->first);
	return w;
}
ui g2(ui x,ui y,ui z){
	ui u,v,w;
	for(auto o:a)if(tie(w,u,v)=o,u!=x&&u!=y&&v!=x&&v!=y)return w+z;
	return inf;
}
void cal(){
	ui z,x,y;
	tie(z,x,y)=*a.begin(),cout<<min(get(x),min(get(y),min(g1(x,y),g2(x,y,z))))<<'\n';
}
int main(){ios::sync_with_stdio(0),cin.tie(0);
	ui m,q,i,j,k;
	for(cin>>i>>m;m--;)cin>>i>>j>>k,ad(i,j,k);
	for(cin>>q;cal(),q--;)if(cin>>i>>j>>k,i)cin>>i,ad(j,k,i);else de(j,k);
	return 0;
}
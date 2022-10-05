#include<bits/stdc++.h>
using namespace std;
using ll=long long;
struct P{
	int x,y;
	bool operator==(P a)const{return x==a.x&&y==a.y;}
	bool operator<(P a)const{return x<a.x||(x==a.x&&y<a.y);}
	bool operator>(P a)const{return x>a.x||(x==a.x&&y>a.y);}
	P operator-(P a)const{return{x-a.x,y-a.y};}
	ll operator*(P a)const{return x*1ll*a.y-y*1ll*a.x;}
}p;
set<P>dn;
set<P,greater<P>>up;
template<class T>bool qry(T&s){
	auto nx=s.lower_bound(p);
	if(nx==end(s))return 0;
	if(nx==begin(s))return p==*begin(s);
	auto pr=prev(nx);
	return(p-*pr)*(*nx-*pr)<=0;
}
template<class T>void ins(T&s){
	if(qry(s))return;
	auto now=s.insert(p).first;
	if(now!=begin(s)){
		auto u=prev(now);
		while(u!=begin(s)){
			auto v=prev(u);
			if((*u-*v)*(*now-*v)>0)break;
			s.erase(u),u=v;
		}
	}
	if(now!=--end(s)){
		auto u=next(now);
		while(u!=--end(s)){
			auto v=next(u);
			if((*u-*now)*(*v-*now)>0)break;
			s.erase(u),u=v;
		}
	}
}
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int q,t;
	for(cin>>q;q--;)if(cin>>t>>p.x>>p.y,t==1)ins(dn),ins(up);
	else if(qry(dn)&&qry(up))cout<<"YES\n";else cout<<"NO\n";
}
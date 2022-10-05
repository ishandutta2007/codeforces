#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3;
string s[N],u[N],v[N];
multiset<string>st;
bool wk(){
	int n,i,j,k;
	bool f=0;
	cin>>n;
	for(i=1;i<=n;++i){
		cin>>s[i];u[i]=v[i]=s[i];
		if(s[i].size()==1)f=1;
		if(s[i].size()==2){
			if(s[i][0]==s[i][1])f=1;
		}
		if(s[i].size()==3){
			if(s[i][0]==s[i][2])f=1;
			u[i]=s[i][1],u[i]=u[i]+s[i][2];
			v[i]=s[i][0],v[i]=v[i]+s[i][1];
		}
	}
	if(f)return 1;
	st.clear();
	for(i=1;i<=n;++i)st.insert(s[i]);
	string s2;
	for(i=1;i<=n;++i){
		st.erase(st.find(s[i]));
		s2=s[i];
		reverse(begin(s2),end(s2));
		if(st.count(s2))return 1;
	}
	st.clear();
	for(i=1;i<=n;++i)st.insert(u[i]);
	for(i=1;i<=n;++i){
		st.erase(st.find(u[i]));
		s2=s[i];
		reverse(begin(s2),end(s2));
		if(st.count(s2))return 1;
	}
	st.clear();
	for(i=1;i<=n;++i)st.insert(s[i]);

	for(i=1;i<=n;++i){
		st.erase(st.find(s[i]));
		s2=v[i];
		reverse(begin(s2),end(s2));
		if(st.count(s2))return 1;
	}
	return 0;
}
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,n,i,j,k;
	cin>>T;
	for(;T--;){
		if(wk())cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
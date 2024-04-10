#include<bits/stdc++.h>
using namespace std;

const int maxn=1000111;
const int mod=1e9+7;
int qpow(int x,int y){
	int ret=1;
	while(y){
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;
		y>>=1;
	}
	return ret;
}

int n,p,a[maxn];
struct number{
	set<pair<int,int>>st;
	void add(int pos){
		while(true){
			auto it=st.lower_bound(make_pair(pos,0));
			if(it!=st.end()&&(*it)==make_pair(pos,p-1)){
				auto it2=it;
				it++;
				st.erase(it2);
				pos++;
			}
			else break;
		}
		auto it=st.lower_bound(make_pair(pos,0));
		if(it==st.end()||it->first!=pos)st.insert(make_pair(pos,1));
		else{
			int t=it->second+1;
			st.erase(it);
			st.insert(make_pair(pos,t));
		}
	}
	pair<int,int> high(){
		if(st.size()==0)return make_pair(-1,-1);
		else return *st.rbegin();
	}
	void pop(){st.erase(*st.rbegin());}
};

bool smaller(number &a, number &b){
	while(a.st.size()&&a.high()==b.high()){
		a.pop();
		b.pop();
	}
	if(a.st.size()||b.st.size())return a.high()<b.high();
	return false;
}
void solve(){
	scanf("%d%d",&n,&p);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	if(p==1)
	{
		printf("%d\n",n%2);
		return;
	}
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	
	number d1,d2;
	int v1=0,v2=0,ans;
	for(int i=1;i<=n;i++){
		if(smaller(d1,d2)){
			d1.add(a[i]);
			v1+=qpow(p,a[i]);
			if(v1>=mod)v1-=mod;
		}
		else{
			d2.add(a[i]);
			v2+=qpow(p,a[i]);
			if(v2>=mod)v2-=mod;
		}
	}
	if(smaller(d1,d2))ans=(v2-v1+mod)%mod;
	else ans=(v1-v2+mod)%mod;
	printf("%d\n",ans);
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--)solve();
	return 0;
}
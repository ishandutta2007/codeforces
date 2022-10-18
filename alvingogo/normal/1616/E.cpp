#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define cd complex<double>
#define p_q priority_queue
using namespace std;

int n;
vector<queue<int> > q(26);
string s,t;
struct BIT{
	int nx;
	vector<int> bt;
	void init(int nn){
		nx=nn;
		bt.resize(nx+1);
	}
	void update(int x,int y){
		for(;x<=nx;x+=(x&-x)){
			bt[x]+=y;
		}
	}
	int query(int x){
		int ans=0;
		for(;x>0;x-=(x&-x)){
			ans+=bt[x];
		}
		return ans;
	}
};
BIT bt;
long long f(int x){
	if(x>=n){
		return 1e18;
	}
	long long ans=1e17;
	for(char c='a';c<t[x];c++){
		if(q[c-'a'].empty()){
			continue;
		}
		ans=min(ans,(long long)(bt.query(q[c-'a'].front())-1));
	}
	if(!q[t[x]-'a'].empty()){
		int y=bt.query(q[t[x]-'a'].front());
		bt.update(q[t[x]-'a'].front(),-1);
		q[t[x]-'a'].pop();
		ans=min(ans,y-1+f(x+1));
	}
	return ans;
}
int main(){
	AquA;
	int tq;
	cin >> tq;
	while(tq--){
		for(int i=0;i<26;i++){
			while(!q[i].empty()){
				q[i].pop();
			}
		}
		cin >> n >> s >> t;
		for(int i=0;i<n;i++){
			q[s[i]-'a'].push(i+1);
		}
		bt.init(0);
		bt.init(n);
		for(int i=0;i<n;i++){
			bt.update(i+1,1);
		}
		long long h=f(0);
		if(h>9e16){
			cout << -1 << "\n";
		}
		else{
			cout << h << "\n";
		}
	}
	return 0;
}
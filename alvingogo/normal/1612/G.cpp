#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

const int mod=1e9+7;
const int inv2=(mod+1)/2;
void add(int& x,int y){
	x+=y;
	x-=mod*(x>=mod);
	x+=mod*(x<0);
}
int mul(int x,int y){
	return 1ll*x*y%mod;
}
vector<int> fra(1e6+7);
void init(){
	fra[0]=1;
	for(int i=1;i<1e6+7;i++){
		fra[i]=mul(fra[i-1],i);
	}
}
int main(){
    AquA;
	init();
	int m;
	cin >> m;
	vector<int> v(1e6+1);
	int sum=0;
	for(int i=0;i<m;i++){
		int c;
		cin >> c;
		v[c]++;
		add(sum,c);
	}
	int ans=0,cod=1,l=0,r=(sum-1+mod)%mod;
	for(int i=1e6;i>=1;i--){
		add(ans,mul(mul(v[i],mul((2*l%mod+v[i]-1)%mod,inv2)),-(i-1)));
		add(ans,mul(mul(v[i],mul((2*r%mod+mod-v[i]+1)%mod,inv2)),i-1));
		add(l,v[i]);
		add(r,-v[i]);
		cod=mul(cod,fra[v[i]]);
		if(i>=2){
			v[i-2]+=v[i];
			cod=mul(cod,fra[v[i]]);
		}
	}
	cout << ans << " " << cod << "\n";
	return 0;
}
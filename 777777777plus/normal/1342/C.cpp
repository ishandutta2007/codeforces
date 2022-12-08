#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e2+5;

int T;
int a,b,g,w[N*N];
int Q;
ll l[N],r[N],cnt;

ll Solve(ll n){
	ll ret=cnt*(n/g);
	for(int i=1;i<=(n%g);++i)ret+=w[i];
	return ret;
}

int main(){
	cin>>T;
	while(T--){
		cin>>a>>b>>Q;
		g=a*b/__gcd(a,b);
		cnt=0;
		for(int i=1;i<=g;++i){
			w[i]=(((i%a)%b)!=((i%b)%a));
			cnt+=w[i];
		}
		for(int i=1;i<=Q;++i){
			cin>>l[i]>>r[i];
		}
		for(int i=1;i<=Q;++i){
			cout<<Solve(r[i])-Solve(l[i]-1)<<" ";
		}
		cout<<endl;
	}
}
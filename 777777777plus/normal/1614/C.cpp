#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
const ll mod = 1e9+7;

int T;
int n,m;
int l[N],r[N],x[N],id[N];

int main(){
	cin>>T;
	while(T--){
		cin>>n>>m;
		ll w=0;
		for(int i=1;i<=m;++i){
			cin>>l[i]>>r[i]>>x[i];
			id[i]=i;
			w|=x[i];
		}
		w%=mod;
		for(int i=1;i<n;++i)w=w*2%mod;
		cout<<w<<endl;
	}
	
}
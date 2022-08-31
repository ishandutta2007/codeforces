#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
ll INF = 1e18;
const int N = 5e+5 + 5;

ll p[N],sz[N];
ll n,m,k,x,u,v,ans,ct;
string s;
vector <pair<ll,ll>> rem,add;


void make(){
	for(int i = 1; i <= n; i++){
		p[i] = i;
		sz[i] = 1;
	}
}

int find(ll x){
	return (p[x] == x)? x: p[x] = find(p[x]);
}

void merge(ll x, ll y){
	ll a = find(x);
	ll b = find(y);
	if(sz[a] > sz[b]) swap(a,b);
	p[a] = b;
	sz[b] += sz[a];
}
int main(){
    cin>>n;
    make();

    for(int i = 1; i < n; i++){
        cin>>u>>v;
        if(find(u) != find(v)) merge(u,v);
        else rem.push_back({u,v});
    }

    for(int i = 1; i <= n; i++){
        if(find(1) != find(i)){
        	merge(1,i);
        	add.push_back({1,i});
        }
    }

    m = rem.size();
    cout<<m<<endl;
    for(int i = 0; i < m; i++){
    	printf("%lld %lld %lld %lld\n",rem[i].first,rem[i].second,add[i].first,add[i].second);
    }
}
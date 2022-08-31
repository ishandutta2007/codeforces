#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld; 
using namespace std;
const ll   N  =  3e+5+5;

#define fastio ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);

ll n,m,u,v,vis[N];
set <ll> adj[N];
vector <ll> fact;

void facto(ll n){
	fact.push_back(1);
    for (int i = 2; i <= sqrt(n); i++){   
        if(n % i == 0){
        	fact.push_back(i);
        	fact.push_back(n/i);
        }
    }
}

int main(){
	fastio;
	cin>>n>>m;
	for(int i = 1; i <= m; i++){
        cin>>u>>v;
        u--,v--;
    	adj[u].insert(v);
    	adj[v].insert(u);
    }

    facto(n);
    int flag;

    for(auto it : fact){
    	flag = 1;
    	for(int i = 0; i < n; i++){
    		for(auto it1 : adj[i]){
    			if(adj[(i+it)%n].find((it+it1)%n) == adj[(i+it)%n].end()){
	    			flag = 0;
	    			break;
	    		}
    		}
    		if(flag == 0) break;
    	}
    	if(flag == 1) break;
    }

    if(flag == 0) cout<<"No"<<endl;
    else cout<<"Yes"<<endl;

}
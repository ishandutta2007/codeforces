#pragma optimization_level 3
#pragma GCC optimize("Ofast")   //Comment optimisations for an interatcive problem - use endl
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>

using namespace std;
 
#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;
#define  x                     first                 
#define  y                     second
#define  endl                  "\n"

const ll   N     =  1e+6+5;
const ll   MAX   =  1e17;
const ll   mod   =  1e+7+3;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n,m,a[N],ans = 0, ct = 0,pre[N];
vll v[N],p;

int main() {
	fill_n(pre,0,N);
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>a[i];
		for(int j = 0; j < a[i]; j++){ cin>>m;v[i].push_back(m);}
	}
	for(int i = 0; i < n; i++){
		int flag = 1;
		for(int j = 1; j < a[i]; j++){
			if(v[i][j] > v[i][j-1]){
				ct++;
				flag = 0;
				break;
			}
		}
		if(flag == 1){
			pre[v[i][0]] += 1;
			p.push_back(v[i][a[i]-1]);
		}
	}
	for(int i = N-2; i >= 0; i--){
		pre[i] += pre[i+1];
	}
	ans = (ct*n*2)-(ct*ct);
	//cout<<ans<<endl;
	for(auto it : p){
		ans += pre[it+1];
		//cout<<it<<" "<<pre[it+1]<<endl;
	}
	cout<<ans<<endl;
}
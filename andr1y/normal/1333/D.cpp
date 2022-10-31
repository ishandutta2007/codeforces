//password1488
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+228;
char a[N];
vector<ll> ek[N];
signed main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	ll n, k;
	cin >> n >> k;
	for(ll i = 1;i<=n;i++){
	    cin >> a[i];
	}
	ll Q = 0, ss = 0;
	for(;Q<n;Q++){
	    bool o1 = 0;
	    for(ll i = 1;i<n;i++){
	        if(a[i] == 'R' && a[i+1] == 'L'){
	            ek[Q].push_back(i);
	            swap(a[i], a[i+1]);
	            i++;ss++;
	            o1 = 1;
	            continue;
	        }
	    }
	    if(!o1){
	        break;
	    }
	}
	if(Q>k || ss<k){
	    cout << "-1\n";
	    return 0;
	}
	ll nd = k-Q;
	for(ll i = 0;i<Q;i++){
	    for(ll j = 0;j<ek[i].size();j++){
	        if(nd == 0){
	            cout << ek[i].size()-j << ' ';
	            while(j<ek[i].size()) cout << ek[i][j++] << ' ';
	            cout<<'\n';
	        }else{
	            cout << 1 << ' ' << ek[i][j] << '\n';
	            if(ek[i].size()-j-1) nd--;
	        }
	    }
	}
}
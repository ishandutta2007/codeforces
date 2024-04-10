#include<bits/stdc++.h>
//#include<atcoder/dsu>
using namespace std;
//using namespace atcoder;

void solve(){
	int n;
    cin >> n;
    vector<long long> V(n);
    for(int i = 0; i < n; i++) cin >> V[i];
    long long mi = 0;
    long long tot = 0;
    for(long long i = 1; i <= n; i++){
        tot += V[i - 1];
        long long x = (tot + i - 1) / i;
        mi = max(mi, x);
    }
    int q;
    cin >> q;
    while(q--){
        long long t;
        cin >> t;
        if(t < mi) cout << "-1\n";
        else cout << (tot + t - 1LL) / t << "\n";
    }

    
}

int main(){	
	cin.tie(0)->sync_with_stdio(0);
    int t;
    t = 1;
    // cin >> t;
    while(t--) solve();
}
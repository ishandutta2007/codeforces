#include<bits/stdc++.h>
//#include<atcoder/dsu>
using namespace std;
//using namespace atcoder;

void solve(){
	long long n, m;
    cin >> n >> m;
    long long ans;
    ans = (1 + m) * m / 2;
    ans += m * (1 + n) * n / 2;
    ans -= m;
    cout << ans << "\n";
}

int main(){	
	cin.tie(0)->sync_with_stdio(0);
    int t;
    t = 1;
    cin >> t;
    while(t--) solve();
}
#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) (int(s.size()))
#define bit(n, k) (((n)>>(k))&1)

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int maxn = 1e5 + 10;

pii normal(int a, int b){
    int g = __gcd(abs(a), abs(b));
    a/= g, b/= g;
    return {a, b};
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(), cout.tie();

    int q;
    cin >> q;
    while(q--){
	int n;
	cin >> n;
	map<pii, int> mp;
	ll ans = 0;
	for(int i = 0; i < n; i++){
	    int a, b, c, d;
	    cin >> a >> b >> c >> d;	    
	    mp[normal(a-c, b-d)]++;
	    ans+= mp[normal(c-a, d-b)];
	}
	cout << ans << "\n";
    }
}
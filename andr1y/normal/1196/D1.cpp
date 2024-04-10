#include <bits/stdc++.h>
#define ld long double
#define ll long long
#define ull unsigned ll
#define pll pair<ll, ll>
#define itr(a) begin(a), end(a)
#define pb push_back
#define x first
#define y second
#define endl '\n'
#define FAST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FILES(namein, nameout) freopen(namein, "r", stdin); freopen(nameout, "w", stdout);
#define M 1000000007
#define N 200000
#define INF 101111111111111
using namespace std;
char x[] = {'R', 'G', 'B'};
int main(){
    FAST;
    ll Q;
    cin >> Q;
    while(Q--){
    	ll n, k;
    	cin >> n >> k;
    	string s;
    	cin >> s;
    	//cerr << n << " " << k << " " << s << endl;
    	ll res = k;
    	for(ll i = 0;i<n-k+1;i++){
    		for(ll C = 0;C<3;C++){
    			ll tr = 0;
    			for(ll j = i;j<i+k;j++){
    				char mbn = x[((j-i+C)%3)];
    				//cerr << "i: "<< i << " C: " << C << " j: " << j << " mbn: " << mbn << endl;
    				if(mbn != s[j]) tr++;
    			}
    			res = min(res, tr);
    		}
    	}
    	cout << res << endl;
    }
}
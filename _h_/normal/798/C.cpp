#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define rrep(i,a,b) for(int i = b; i --> (a);)
#define all(v) v.begin(),v.end()
#define trav(x,v) for(auto &x : v)
#define sz(v) (int)(v).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, d = 0, x, ans = 0, l = 0;
    cin >> n;
    rep(_,0,n){
        cin >> x;
        d = __gcd(d, x);
        if(x&1){
            ++l;
        } else {
            ans += l/2;
            if(l&1) ans += 2;
            l = 0;
        }
    }
    ans += l/2;
    if(l&1) ans += 2;
    if(d > 1) ans = 0;
    cout << "YES\n" << ans << endl;
}
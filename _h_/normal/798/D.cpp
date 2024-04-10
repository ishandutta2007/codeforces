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
	
	int n;
    cin >> n;
    vi a(n), b(n);
    ll A = 0, B = 0;
    trav(x, a) cin >> x;
    trav(x, a) A += x;
    trav(x, b) cin >> x;
    trav(x, b) B += x;
    int k = n/2 + 1;
    ll x = 0, y = 0;
    rep(i,0,k) x += a[i], y += b[i];
    for(int i = 0; ; ++i){
        if(2*x > A && 2*y > B){
            cout << k << endl;
            rep(t,0,k) cout << (i+t)%n+1 << ' ';
            cout << endl;
            return 0;
        }
        x += a[(i+k)%n]-a[i], y += b[(i+k)%n]-b[i];        
    }
}
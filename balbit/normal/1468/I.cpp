//
//

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ii,ll>
#define fi first
#define se second
#define endl '\n'
#define debug(x) cout << #x << " is " << x << endl

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

ll n;

ll find(ll dx1,ll dy1,ll dx2,ll dy2){
	if (dx1==0 && dy1==0) return 0;
	if (dx1==0) return dy1;
	if (dx2==0) return dy2; 
	
	ll temp=dx1*dx2/__gcd(dx1,dx2);
	dy1*=temp/dx1,dy2*=temp/dx2;
	dx1=dx2=temp;
	dx1-=dx2,dy1-=dy2;
	return dy1;
}

ll gcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

bool find_any_solution(ll a, ll b, ll c, ll &x0, ll &y0, ll &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	ll a,b,c,d;
	cin>>a>>b>>c>>d;
	
	ll C=abs(find(a,b,c,d)),R=abs(find(b,a,d,c));
	
	//cout<<R<<" "<<C<<endl;
	
	if (R*C==0){
		cout<<"NO"<<endl;
		return 0;
	}
	
	vector<ii> v;
	rep(x,1,R){
		ll t1,t2,t3;
		if (find_any_solution(a,c,x,t1,t2,t3)){
			//cout<<"debug: "<<x<<" "<<b*t1+d*t2<<endl;
			R=x;
			break;
		}
	}
	
	//cout<<R<<" "<<C<<endl;
	if (R*C!=n){
		cout<<"NO";
		return 0;
	}
	
	cout<<"YES"<<endl;
	rep(x,0,n) cout<<x/C<<" "<<x%C<<endl;
}
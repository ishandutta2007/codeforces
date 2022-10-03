#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN=100 * 1000 + 10;

ll d, k, a, b, t, ans;

ll f(ll dist){
	ll out=b*dist;
	if (dist<k) out=min(out, t+a*dist);
	else out=min(out, t+a*k+f(dist-k));
	return out;
}

ll ff(ll dist){
	ll x=min(a*k+t, k*b);
	return min(dist/k*x + f(dist%k), dist*b);
}


int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>d>>k>>a>>b>>t;
	
	ans=min(ff(d), d*b);
	if (d<k) ans=min(ans, d*a);
	else ans=min(ans, k*a + ff(d-k));
	
	cout<<ans<<endl;
	
	return 0;
}
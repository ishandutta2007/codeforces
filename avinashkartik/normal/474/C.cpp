/***************************************** SHORT - TEMPLATE *********************************************/
#pragma optimization_level 3
#include<bits/stdc++.h>
using namespace std;

#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define  foo(i,a,n)     for(ll i = (a); i <= n; i++)
#define  frr(i,a,n)     for(ll i = (a); i >= n; i--)
#define  all(x)         (x).begin(),(x).end()
#define  newl           cout<<"\n"
#define  pb             push_back
#define  s              second
#define  f              first
#define  ll             long long
#define  vll            vector<ll>
#define  pll            pair<ll,ll>
#define  MOD            1000000007
#define  INF            LLONG_MAX
#define  N              100008

/***************************************** FUNCTIONS / DECLARATIONS **************************************/
ll t=1;
ll x[5],y[5],a[5],b[5];
ll ans = INF;
vector<pll> pts[5];
multiset<pll> curr;

vector<pll> get_rotations(ll x, ll y, ll a, ll b){
	vector<pll> temp;
	temp.pb({x-a,y-b}); 
	temp.pb({-temp.back().s,temp.back().f});
	temp.pb({-temp.back().s,temp.back().f});
	temp.pb({-temp.back().s,temp.back().f});
	foo(i,0,3)temp[i].f+=a,temp[i].s+=b;
	return temp;
} 

ll distSq(pll p, pll q) { 
	return (p.f - q.f)*(p.f - q.f) + (p.s - q.s)*(p.s - q.s); 
} 
  
bool isSquare(pll p1, pll p2, pll p3, pll p4) { 
	ll d2 = distSq(p1, p2);
 	ll d3 = distSq(p1, p3);
	ll d4 = distSq(p1, p4);
  
	if (d2 == d3 && 2 * d2 == d4 && 2 * distSq(p2, p4) == distSq(p2, p3) && d2*d3!=0) return true; 
	if (d3 == d4 && 2 * d3 == d2 && 2 * distSq(p3, p2) == distSq(p3, p4) && d3*d4!=0) return true; 
	if (d2 == d4 && 2 * d2 == d3 && 2 * distSq(p2, p3) == distSq(p2, p4) && d2*d4!=0) return true; 
    
   return false; 
} 

void solve(ll ind, ll moves){
	if(ind==5){
		vector<pll> chk;
		
		for(auto it: curr)chk.pb(it);
		pll p1 = chk[0], p2 = chk[1], p3 = chk[2], p4 = chk[3];
		if(isSquare(p1,p2,p3,p4)){
			ans = min(ans, moves);
		}
		return;
	}
	
	vector<pll> choice = pts[ind];
	foo(i,0,3){
		curr.insert(choice[i]);
		solve(ind+1, moves+i);
		auto it=curr.lower_bound(choice[i]);
		curr.erase(it); 
	}
}
/***************************************** MAIN FUNCTION - DRIVER *************************************************/
void MAIN(){
	ans=INF; curr.clear();
	foo(i,1,4) cin>>x[i]>>y[i]>>a[i]>>b[i];
	foo(i,1,4) pts[i]=get_rotations(x[i], y[i], a[i], b[i]);
	
	solve(1,0);
	if(ans==INF)cout<<-1;
	else cout<<ans;
	newl;
}

int main(){
	fastio;cin>>t;
	while(t--){
		MAIN();
	}
	#ifndef ONLINE_JUDGE
	cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
}
#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


ll dist(pair<ll, ll> a, pair<ll, ll> b){
	return abs(a.first - b.first) + abs(a.second - b.second);
}

bool inord(ll a, ll b, ll c){
	if(c >= b && b >= a) return true;
	if(b >= a && a>=c ) return true;
	if(a>=c && c>=b) return true;
	return false;
}

int main(){
	ll n;
	cin >> n;
	pair<ll, ll> mxx;
	pair<ll, ll> mxy;
	pair<ll, ll> mnx;
	pair<ll, ll> mny;
	ll mxxi=0, mxyi=0, mnxi=0, mnyi=0;
	vector<pair<ll, ll>> v;
	for(ll i=0; i<n; i++){
		ll x, y;
		cin >> x >> y;
		pair<ll, ll> p = make_pair(x, y);
		v.push_back(p);
		if(i == 0){
			mxx = mxy = mnx = mny = p;
		}
		if(x > mxx.first){
			mxx = p;
			mxxi=i;
		}
		if(x < mnx.first){
			mnx = p;
			mnxi=i;
		}
		if(y < mny.second){
			mny = p;
			mnyi=i;
		}
		if(y > mxy.second){
			mxy = p;
			mxyi=i;
		}
	}
	ll bestthree = 0;
	for(ll i=0; i<n; i++){
		
		bestthree = max(bestthree, dist(mxy, mxx) + dist(mxy, v[i]) + dist(mxx, v[i]));
		bestthree = max(bestthree, dist(mny, mxx) + dist(mny, v[i]) + dist(mxx, v[i]));
		bestthree = max(bestthree, dist(mxy, mnx) + dist(mxy, v[i]) + dist(mnx, v[i]));
		bestthree = max(bestthree, dist(mny, mnx) + dist(mny, v[i]) + dist(mnx, v[i]));
	}
	ll bestfour = dist(mny, mnx) +dist(mxy, mnx) +dist(mny, mxx) +dist(mxy, mxx);
	cout << bestthree;
	for(ll i=4; i<=n; i++){
		cout << " " << bestfour;
	}
	cout << endl;
	
}
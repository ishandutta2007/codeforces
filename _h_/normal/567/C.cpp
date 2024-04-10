#include <iostream>
#include <vector>
#include <random>
#include <set>
#include <map> 
#include <algorithm>
#include <queue>
using namespace std;
#define rep(i,a,b) for(int i = int(a); i < (b); ++i)
#define rrep(i,a,b) for(int i = (int)(b)-1; i >= (a); --i)
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
const ll inf = 1e15;
int main(){
	int n;
	long long k;
	cin >> n >> k;
	vector<ll> as(n);
	rep(i,0,n)
		cin >> as[i];
	vi an1(n), an2(n);
	map<ll,int> m1, m2;
	rep(i,0,n){
		an1[i] = m1[as[i]];
		++m1[as[i]*k];
	}
	rrep(i,0,n){
		an2[i] = m2[as[i]];
		if(as[i]%k == 0)
			++m2[as[i]/k];
	}
	ll ans = 0;
	rep(i,0,n)
		ans += (ll)an1[i]*an2[i];
	cout << ans << endl;
}
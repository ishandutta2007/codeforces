#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <bitset>
#include <random>
#include <cassert>
#include <cstdio>
#include <cstring>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> int(a);)
#define allof(v) v.begin(),v.end()
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef vector<bool> vb;
typedef long double ld;
const ll md = 1e9+7;
int main(){
	cin.sync_with_stdio(false);
	ll n,m;
	cin >> n >> m;
	vl s(n+1);
	ll sub = 0;
	s[0] = 1;
	rep(i,1,n+1){
		sub = sub * (m-1);
		if(i >= 2) sub += s[i-2];
		sub %= md;
		s[i] = (2*m*s[i-1] - m*sub)%md;
	}
	cout << (s[n]+md)%md << endl;
}
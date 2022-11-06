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
#include <complex>
#include <functional>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> int(a);)
#define all(v) v.begin(),v.end()
#define trav(x, v) for(auto &x : v)
#define sz(v) int((v).size())
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef long double ld;

bool isPrime(ll n){
	for(ll p = 2; p*p <= n; ++p)
		if(n%p == 0) return 0;
	return 1;
}

int solve(){
	int n;
	cin >> n;
	if(isPrime(n)) return 1;
	if(isPrime(n-2) || n%2==0) return 2;
	return 3;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << solve() << endl;
}
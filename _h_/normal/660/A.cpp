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

int main(){
	cin.sync_with_stdio(false);
	int n;
	cin >> n;
	vi a(n);
	rep(i,0,n) cin >> a[i];
	int k = 0;
	rep(i,1,n) k += __gcd(a[i-1],a[i]) > 1;
	cout << k << endl;
	rep(i,0,n){
		cout << a[i] << ' ';
		if(i+1 < n && __gcd(a[i],a[i+1]) > 1) cout << 1 << ' ';
	}
	cout << endl;
}
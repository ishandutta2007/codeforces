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
#include <functional>
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
	cin.sync_with_stdio(0);
	int n,d,h;
	cin >> n >> d >> h;
	if((d == 1 && n > 2) || 2*h < d){
		cout << -1 << endl;
		return 0;
	}
	vi a(n-1), b(n-1);
	int ix = 0;
	rep(i,0,d){
		a[ix] = i+1;
		b[ix++] = i+2;
	}
	int mi = 1 + d/2;
	rep(i,d+2,n+1){
		a[ix] = mi;
		b[ix++] = i;
	}
	rep(i,0,n-1){
		if(a[i] == 1){
			a[i] = h+1;
		} else if(a[i] == h+1){
			a[i] = 1;
		}
		if(b[i] == 1){
			b[i] = h+1;
		} else if(b[i] == h+1){
			b[i] = 1;
		}
	}
	rep(i,0,n-1){
		cout << a[i] << ' ' << b[i] << endl;
	}
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <stack>
#include <queue>
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
const ll inf = 1LL<<60;
const ll md = 1e9+7;
const ld eps = 1e-14;
const ld pi = acos(-1);

int fem(int n){
	int ans = 0;
	while(n%5 == 0){
		n /= 5;
		++ans;
	}
	return ans;
}

int main(){
	int m;
	cin >> m;
	int z = 0;
	int a=-1,b;
	for(int i = 1; ; ++i){
		z += fem(i);
		if(z >= m && a == -1) a = i;
		if(z > m){
			b = i;
			break;
		}
	}
	cout << b-a << endl;
	rep(i,a,b) cout << i << ' ';
	cout << endl;
}
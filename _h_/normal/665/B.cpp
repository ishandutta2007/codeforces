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
	cin.sync_with_stdio(0);
	int n,m,k;
	cin >> n >> m >> k;
	vi p(k);
	rep(i,0,k) cin >> p[i];
	int t = 0;
	rep(i,0,n) rep(j,0,m){
		int a;
		cin >> a;
		int c = 0;
		while(p[c] != a) ++c;
		rrep(i,0,c) p[i+1] = p[i];
		p[0] = a;
		t += c+1;
	}
	cout << t << endl;
}
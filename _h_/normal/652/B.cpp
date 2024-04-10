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
	vi as(n);
	for(int &a : as) cin >> a;
	sort(allof(as));
	vi ans(n);
	rep(i,0,1+(n-1)/2) ans[2*i] = as[i];
	rep(i,0,n/2) ans[2*i+1] = as[n-i-1];
	for(int a : ans) cout << a << ' ';
	cout << endl;
}
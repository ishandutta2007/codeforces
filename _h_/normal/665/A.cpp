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
	int a,ta,b,tb,h,m;
	char c;
	cin >> a >> ta >> b >> tb >> h >>c>> m;
	m += 60*(h-5);
	int ans = 0;
	for(int i = 0; i < 19*60; i += b){
		if(i < m+ta && i+tb > m) ++ans;
	}
	cout << ans << endl;
}
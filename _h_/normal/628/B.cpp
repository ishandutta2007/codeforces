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
const ld eps = 1e-14;
const int mx = 3e5+1;
int main(){
	char s[mx];
	scanf("%s",s);
	int n = strlen(s);
	ll ans = (s[0]-'0')%4 == 0;
	rep(i,0,n-1){
		ans += (s[i+1]-'0')%4 == 0;
		if(((s[i+1]-'0')+10*(s[i]-'0'))%4 == 0) ans += i+1;
	}
	cout << ans << endl;
}
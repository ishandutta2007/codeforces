#include <iostream>
#include <cstdio>
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
const ll inf = 1LL<<60;

int main(){
	int n;
	scanf("%d",&n);
	vi ans(2*n);
	for(int i = 1; i < n; i += 2){
		ans[i/2] = i;
		ans[i/2 + n-i] = i;
	}
	for(int i = 2; i < n; i += 2){
		ans[n + i/2] = i;
		ans[n + i/2 + n-i] = i;
	}
	rep(i,0,2*n) if(ans[i] == 0) ans[i] = n;
	rep(i,0,2*n) printf("%d ",ans[i]);
	puts("");
}
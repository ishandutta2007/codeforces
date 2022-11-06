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
#include <string>
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

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	vi cnt(m+1), sak(m+1), a(n);
	rep(i,0,n){
		scanf("%d",&a[i]);
		if(a[i] <= m)
			++cnt[a[i]];
	}
	rep(i,1,m+1){
		for(int j = i; j <= m; j += i)
			sak[j] += cnt[i];
	}
	int ans = -1, k;
	rep(i,1,m+1){
		if(sak[i] > ans){
			ans = sak[i];
			k = i;
		}
	}
	printf("%d %d\n",k,ans);
	rep(i,0,n) if(k%a[i] == 0) printf("%d ",i+1);
	puts("");
}
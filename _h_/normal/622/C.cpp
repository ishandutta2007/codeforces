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
	int n,m;
	scanf("%d%d",&n,&m);
	vi a(n);
	for(int &x : a) scanf("%d",&x);
	vi neq(n);
	neq[n-1] = n+11;
	rrep(i,0,n-1) neq[i] = a[i]==a[i+1] ? neq[i+1] : i+1;
	rep(_,0,m){
		int l,r,x;
		scanf("%d%d%d",&l,&r,&x);
		--l;
		if(a[l] != x){
			printf("%d\n",l+1);
		} else {
			int ans = neq[l];
			if(ans >= r){
				puts("-1");
			} else {
				printf("%d\n",ans+1);
			}
		}
	}
}
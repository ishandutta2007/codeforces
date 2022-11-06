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

int main(){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	vector<pii> row(n,pii(0,0)), col(m,pii(0,0));
	rep(i,0,k){
		int t,r,a;
		scanf("%d%d%d",&t,&r,&a);
		--r;
		if(t == 1){
			row[r] = pii(a,i+1);
		} else {
			col[r] = pii(a,i+1);
		}
	}
	rep(i,0,n){
		rep(j,0,m){
			if(row[i].second < col[j].second)
				printf("%d ",col[j].first);
			else
				printf("%d ",row[i].first);
		}
		puts("");
	}
}
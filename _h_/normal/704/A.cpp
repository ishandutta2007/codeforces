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
#include <complex>
#include <functional>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> int(a);)
#define all(v) v.begin(),v.end()
#define trav(x, v) for(auto &x : v)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long double ld;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n,q;
	cin >> n >> q;
	vi cnt(n+1), read(n+1,-1);
	queue<pii> ko;
	int off = 0;
	int ans = 0;
	rep(i,0,q){
		int t, x;
		cin >> t >> x;
		if(t == 1){
			++cnt[x];
			ko.push(pii(x, i));
			++ans;
		} else if(t == 2){
			ans -= cnt[x];
			cnt[x] = 0;
			read[x] = i;
		} else {
			x -= off;
			if(x < 0){
				goto done;
			}
			off += x;
			rep(_,0,x){
				assert(!ko.empty());
				pii p = ko.front();
				ko.pop();
				int y = p.first;
				if(read[y] < p.second){
					--ans;
					--cnt[y];
				}
			}
		}
		done:
		cout << ans << '\n';
	}
}
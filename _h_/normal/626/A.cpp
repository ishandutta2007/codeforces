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
	map<pii, int> cnt;
	for(int x=0, y=0; ++cnt[pii(x,y)], n--;){
		char c;
		scanf(" %c ", &c);
		switch(c){
			case 'U':
				++y;
				break;
			case 'D':
				--y;
				break;
			case 'L':
				--x;
				break;
			case 'R':
				++x;
				break;
		}
	}
	int ans = 0;
	for(auto p : cnt) ans += p.second*(p.second - 1);
	printf("%d\n", ans/2);
}
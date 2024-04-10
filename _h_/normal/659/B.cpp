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

typedef pair<int,string> P;

int main(){
	cin.sync_with_stdio(0);
	int n,m;
	cin >> n >> m;
	vector<vector<P> > rs(m);
	rep(_,0,n){
		string s;
		int r, sc;
		cin >> s >> r >> sc;
		rs[r-1].pb(P(sc,s));
	}
	rep(i,0,m){
		sort(allof(rs[i]));
		reverse(allof(rs[i]));
		if(rs[i].size() > 2 && rs[i][2].first == rs[i][1].first)
			cout << "?\n";
		else {
			cout << rs[i][0].second << ' ' << rs[i][1].second << endl;
		}
	}

}
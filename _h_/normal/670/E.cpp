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
#include <functional>
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
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n,m,p;
	cin >> n >> m >> p;
	vector<int> match(n);
	string s;
	cin >> s;
	int pos = 0;
	function<void()> rek = [&](){
		int arg = pos-1;
		while(s[pos] == '('){
			++pos;
			rek();
		};
		if(arg == -1) return;
		match[arg] = pos;
		match[pos] = arg;
		++pos;
	};
	rek();
	/*rep(i,0,n)cout<<match[i]+1;
	cout<<endl;
	return 0;*/
	string instr;
	cin >> instr;
	p--;
	set<int> left;
	rep(i,0,n) left.insert(i);
	auto it = left.find(p);
	for(char c : instr){
		if(c == 'R'){
			++it;
		} else if(c == 'L'){
			--it;
		} else {
			p = min(*it, match[*it]);
			int q = match[p];
			auto jt = left.upper_bound(q);
			left.erase(left.find(p), jt);
			it = jt;
			if(it == left.end()) --it;
		}
	}
	for(int i : left) cout << s[i];
	cout << endl;
}
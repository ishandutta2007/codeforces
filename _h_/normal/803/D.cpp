#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define rrep(i,a,b) for(int i = b; i --> (a);)
#define all(v) v.begin(),v.end()
#define trav(x,v) for(auto &x : v)
#define sz(v) (int)(v).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int k;
	cin >> k;
	vi v;
	for(string s; cin >> s;){
		if(sz(v)) v.back()++;
		int pr = 0;
		rep(i,0,sz(s)) if(s[i]=='-'){
			v.push_back(i-pr+1);
			pr = i+1;
		}
		v.push_back(sz(s) - pr);
	}
	int lo = 0, hi = 1e6;
	trav(x, v) lo = max(lo, x-1);
	while(lo+1 < hi){
		int mi = (lo + hi)/2;
		int cur = 0, cnt = 1;
		trav(x, v){
			cur += x;
			if(cur > mi){
				++cnt;
				cur = x;
			}
		}
		if(cnt <= k) hi = mi;
		else lo = mi;
	}
	cout << hi << endl;
}
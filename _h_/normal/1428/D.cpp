#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define all(v) (v).begin(),(v).end()
#define trav(x,v) for(auto &x : v)
#define sz(v) int(v.size())
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

void fail(){
	cout << -1 << endl;
	exit(0);
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int n;
	cin >> n;

	vi a(n);
	trav(x, a) cin >> x;

	stack<pii> st;
	stack<int> ts;

	int cur = n;
	vector<pii> ans;

	rrep(i,1,n+1){
		int c = a[i-1];
		if(c == 0) ;
		else if(c == 1){
			ans.emplace_back(cur, i);
			st.push({cur, i});
			--cur;
		}
		else if(c == 2){
			if(st.empty()) fail();
			pii p = st.top(); st.pop();
			ans.emplace_back(p.first, i);	
			ts.push(i);
		} else if(c == 3){
			if(!ts.empty()){
				int j = ts.top(); ts.pop();
				ans.emplace_back(cur, i);	
				ans.emplace_back(cur, j);	
				--cur;
			} else if(!st.empty()){
				int j = st.top().second; st.pop();
				ans.emplace_back(cur, i);	
				ans.emplace_back(cur, j);	
				--cur;
			} else fail();
			ts.push(i);
		}
	}
	cout << sz(ans) << endl;
	trav(pa, ans) cout << pa.first << " " << pa.second << endl;
}
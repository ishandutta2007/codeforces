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
	
	int n, k;
	cin >> n >> k;

	string s;
	cin >> s;


	stack<int> st;
	vector<bool> alive(n, false);
	int cur = 0;

	rep(i,0,n){
		if(s[i] == '('){
			if(2*cur < k){
				++cur;
				alive[i] = true;
			}
			st.push(i);
		} else {
			int l = st.top(); st.pop();
			alive[i] = alive[l];
		}
	}
	rep(i,0,n) if(alive[i]) cout << s[i];
	cout << endl;
}
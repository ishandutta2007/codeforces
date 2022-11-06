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
	
	string s,t;
	cin >> s >> t;
	sort(all(s)), sort(all(t));
	reverse(all(t));
	int n = sz(t);
	int a = (n+1)/2, b = n/2;
	deque<char> ss(a), tt(b);
	rep(i,0,a) ss[i] = s[i];
	rep(i,0,b) tt[i] = t[i];
	string ans(n, '?');
	int l = 0, r = n-1;
	rep(i,0,n){
		bool bo = ss[0] < tt[0];
		bool ba = i%2;
		if(bo){
			ans[l++] = (ba ? tt : ss)[0];
			(ba ? tt : ss).pop_front();
		} else {
			ans[r--] = (ba ? tt : ss).back();
			(ba ? tt : ss).pop_back();
		}
	}
	cout << ans << endl;
}
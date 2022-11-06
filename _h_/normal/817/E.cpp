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

struct node
{
	int cnt = 0, tv;
	node *lr[2] = {};
	node(int tv) : tv(tv){}

	void upd(int p, int dif){
		cnt += dif;
		if(tv == 0) return;
		int i = bool(p&tv);
		if(lr[i]==0)
			lr[i] = new node(tv/2);
		lr[i]->upd(p,dif);
	}

	int que(int p, int l){
		if(l <= 0) return 0;
		if(l > 2*tv-1) return cnt;
		int ans = 0;
		rep(t,0,2) if(lr[t] != 0){
			int x = (p^(t*tv))&tv;
			ans += lr[t]->que(p, l-x);
		}
		return ans;
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	node r(1<<29);
	int q;
	cin >> q;
	rep(_,0,q){
		int t,p;
		cin >> t >> p;
		if(t == 1){
			r.upd(p,1);
		} else if(t == 2){
			r.upd(p,-1);
		} else {
			int l;
			cin >> l;
			cout << r.que(p,l) << endl;
		}
	}
}
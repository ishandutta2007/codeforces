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

struct expr {
	int val;
	string s;
	int t;
	expr(int val, string s, int t) : val(val), s(s), t(t) {}
};

//F -> T -> E
expr neg(expr e){
	// F -> F
	return expr((~e.val)&255, "!"+e.s, 2);
}

expr och(expr e, expr f){
	// (T,F) -> T
	return expr(e.val & f.val, e.s + "&" + f.s, 1);
}

expr elr(expr e, expr f){
	// (E,T) -> E
	return expr(e.val | f.val, e.s + "|" + f.s, 0);
}

expr paren(expr e){
	//E -> F
	return expr(e.val, "(" + e.s + ")", 2);
}

bool lt(string b, string a){
	assert(b != "-");
	if(a == "-") return true;
	return sz(b)<sz(a) || (sz(a)==sz(b) && b < a);
}

bool comp(expr a, expr b){
	return lt(b.s, a.s);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	vector<vector<string>> ans(3, vector<string>(256,"-"));
	//0 = E, 1 = T, 2 = F;
	vector<expr> myes;
	priority_queue<expr, vector<expr>, function<bool(expr,expr)>> ko(comp);
	
	auto psh = [&](expr e){
		if(lt(e.s, ans[e.t][e.val])){
			ans[e.t][e.val] = e.s;
			ko.push(e);
		}
	};

	psh(expr(1+2+4+8, "x",2));
	psh(expr(1+2+16+32, "y",2));
	psh(expr(1+4+16+64, "z",2));
	while(!ko.empty()){
		expr e = ko.top();
		ko.pop();
		//cout << e.s << endl;
		if(ans[e.t][e.val] == e.s){
			ans[e.t][e.val] = e.s;
			if(e.t > 0) psh(expr(e.val, e.s, e.t-1));
			if(e.t == 2) psh(neg(e));
			if(e.t == 0) psh(paren(e));
			if(e.t == 0) trav(f, myes) if(f.t==1)
				psh(elr(e,f));
			if(e.t == 1) trav(f,myes) if(f.t == 2)
				psh(och(e,f));
			if(e.t == 1) trav(f, myes) if(f.t==0)
				psh(elr(f,e));
			if(e.t == 2) trav(f, myes) if(f.t==1)
				psh(och(f,e));
			myes.push_back(e);
		}
	}

	int n;
	cin >> n;
	rep(i,0,n){
		string s;
		cin >> s;
		int x = 0;
		trav(c, s) x = 2*x + c-'0';
		cout << ans[0][x] << endl;
	}
}
#include <bits/stdc++.h>
#define sz(a) (int)(a).size()
#define all(a) (a).begin(),(a).end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
// head

struct num {
	static const int MA = 1e9+7, MB = 1e9+9;
	int a,b;
	num() {}
	num(int a) : a((a%MA+MA)%MA), b((a%MB+MB)%MB) {}
	num(int a, int b) : a((a%MA+MA)%MA), b((b%MB+MB)%MB) {}
	num operator + (const num x) const { return num(a+x.a,b+x.b); }
	num operator - (const num x) const { return num(a-x.a,b-x.b); }
	num operator * (const num x) const { return num(((ll)a*x.a)%MA,((ll)b*x.b)%MB); }
	bool operator == (const num x) const { return a==x.a&&b==x.b; }
	bool operator < (const num x) const { return a<x.a||a==x.a&&b<x.b; }
};

const int P = max(239,rand());
vector<num> deg;

void CD(int n = 1000000) {
	deg.resize(n+1);
	deg[0] = 1;
	for(int i = 0; i < n; i++)
		deg[i+1] = deg[i] * P;
}

void CH(string &s, vector<num> &h) {
	int n = sz(s);
	h.resize(n+1);
	h[0] = 0;
	for(int i = 0; i < n; i++)
		h[i+1] = h[i] * P + s[i];
}

num SS(vector<num> &h, int l, int r) {
	return h[r+1] - h[l] * deg[r-l+1];
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	CD(); int n, k; cin >> n >> k;
	string s; cin >> s;
	int g; cin >> g;
	map<num,int> hp;
	for(int i = 0; i < g; i++) {
		string s; cin >> s;
		vector<num> h; CH(s,h);
		hp[SS(h,0,sz(s)-1)] = i;
	}
	vector<set<num>> o(k);
	s += s; int m = 2*n*k;
	vector<bool> can(m,true);
	vector<num> h; CH(s,h);
	for(int i = k-1; i < m; i++) {
		num ha = SS(h,i-k+1,i);
		if(i > k-1 && (can[i-k] == false || o[i%k].find(ha) != o[i%k].end())) {
			can[i] = false; continue;
		}
		if(hp.count(ha) == 0) {
			can[i] = false; continue;
		}
		o[i%k].insert(ha);
	}
	for(int i = m/2-1; i < m; i++)
		if(can[i]) {
			cout << "YES\n";
			vector<num> ans;
			for(i -= k-1; i >= 0; i -= k)
				ans.pb(SS(h,i,i+k-1));
			for(i = sz(ans)-1; i >= 0; i--)
				cout << hp[ans[i]]+1 << ' ';
			return 0;
		}
	cout << "NO";
}
#include <bits/stdc++.h>
 
#define sz(a) (int)(a).size()
 
using namespace std;
 
typedef long long ll;
 
struct num {
	static const int MA = 1e9 + 7, MB = 1e9 + 9;
	int a, b;
	num() {}
	num(int x) : a((x%MA + MA) % MA), b((x%MB + MB) % MB) {}
	num(int a, int b) : a((a%MA + MA) % MA), b((b%MB + MB) % MB) {}
	num operator + (const num &x) const { return num((a+x.a)%MA, (b+x.b)%MB); }
	num operator - (const num &x) const { return num((a+MA-x.a)%MA, (b+MB-x.b)%MB); }
	num operator * (const num &x) const { return num(((ll)a*x.a)%MA, ((ll)b*x.b)%MB); }
	bool operator == (const num &x) const { return a==x.a && b==x.b; }
	bool operator < (const num &x) const { return a<x.a||a==x.a&&b<x.b; }
};
 
const int P = max(239, rand());
vector<num> h, deg;
 
num ss(int l, int r) {
	return h[r+1] - h[l] * deg[r-l+1];
}
 
void ch(string &s) {
	int n = sz(s);
	h.resize(n+1);
	h[0] = 0;
	for(int i = 0; i < n; i++)
		h[i+1] = h[i] * P + s[i];
}
 
int main() {
	deg.resize(600001);
	deg[0] = 1;
	for(int i = 0; i < 600000; i++)
		deg[i+1] = deg[i] * P;
	set<num> hs;
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		string s;
		cin >> s;
		ch(s);
		hs.insert(ss(0, sz(s)-1));
	}
	for(int i = 0; i < m; i++) {
		string s;
		cin >> s;
		ch(s);
		bool fl = false;
		for(int j = 0, lim = sz(s); j < lim && !fl; j++)
			for(char c = 'a'; c < 'd'; c++)
				if(c != s[j] && hs.find(ss(0, lim-1) + deg[lim - j - 1] * (c - s[j])) != hs.end())
					fl = true;
		if(fl)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}
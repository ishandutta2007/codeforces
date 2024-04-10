#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s;
	cin >> s;
	reverse(all(s));
	while(s.back()=='0') s.pop_back();
	reverse(all(s));
	int p=s.size();
	rep(i, s.size()) if(s[i]=='.') p=i;
	if(p==s.size()) s+=".";
	while(s.back()=='0') s.pop_back();
	if(p==0) {
		reverse(all(s));
		s.pop_back();
		int l=-1;
		while(s.back()=='0') {
			s.pop_back();
			--l;
		}
		reverse(all(s));
		cout << s[0];
		if(s.size()>1) {
			cout << '.';
			rep(i, s.size()-1) cout << s[i+1];
		}
		cout << 'E' << l << '\n';
		return 0;
	}
	int l=0;
	while(p>1) {
		swap(s[p], s[p-1]);
		--p;
		++l;
	}
	while(s.back()=='0') s.pop_back();
	if(s.back()=='.') s.pop_back();
	cout << s;
	if(l) cout << 'E' << l;
	cout << '\n';
}
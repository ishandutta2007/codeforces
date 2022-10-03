#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps=1e-10;
const ll inf=100000000000000010;
const int mod = 1000 * 1000 * 1000 + 7;
const int MAXN = 200 * 1000 + 10;

int n;

string s, t;

string f(string s){
	int x=s.size();
	if (x%2) return s;
	
	string tmp1=f(s.substr(0, x/2));
	string tmp2=f(s.substr(x/2));
	
	if (tmp1<=tmp2) return tmp1 + tmp2;
	return tmp2 + tmp1;
}

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	getline(cin, s);
	getline(cin, t);
	int n=s.size();
	s=f(s);
	t=f(t);
	if (s==t) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	
	//cerr<<s<<endl<<t<<endl;
	
	return 0;
}
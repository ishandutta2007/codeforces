#include<bits/stdc++.h>

using namespace std;

#define  GODSPEED       ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(15);
#define  f              first
#define  s              second
#define  newl           cout<<"\n";
#define  pb             push_back
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" ";newl;
#define  deb1(a)        cout<<a<<"\n";
#define  deb2(a,b)      cout<<a<<" "<<b<<"\n";
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<"\n";
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
#define  uniq(a)        a.resize(unique(a.begin(), a.end()) - a.begin());
#define  all(a)         a.begin(),a.end()

typedef  long long             ll;
typedef  long double           ld;

const ll   N     =  1e6 + 5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const int  LEVEL =  log2(N) + 1;

string a, s;

void solve() {
	cin >> a >> s;
	reverse(all(a));
	reverse(all(s));
	string b;
	for (int i = 0, j = 0; i < a.size(); i++) {
		if (a[i] > s[j]) {
			if (j == s.size() -1 || s[j + 1] != '1') {
				deb1(-1)
				return;
			}
			b += (10 + s[j] - a[i]) + '0';
			j += 2;
		} else {
			b += (s[j] - a[i]) + '0';
			j++;
		}
		if (i == a.size() - 1 && j != s.size()) a += '0';
	}
	while (b.back() == '0') b.pop_back();
	reverse(all(b));
	deb1(b)
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}
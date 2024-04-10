#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

void inc(vector<int> &a) {
	reverse(all(a));
	a[0]++;
	for(int i = 0, n = sz(a); ; i++)
		if(a[i] > 9) {
			a[i] %= 10;
			if(i == n-1)
				a.pb(0);
			a[i+1]++;
		} else
			break;
	reverse(all(a));
}

int main() {
	ios_base::sync_with_stdio(0);
	int n, t;
	cin >> n >> t;
	vector<int> l, r;
	bool pt = false;
	for(int i = 0; i < n; i++) {
		char c;
		cin >> c;
		if(c == '.')
			pt = true;
		else if(pt)
			r.pb(c - '0');
		else
			l.pb(c - '0');
	}
	int ls = sz(l), rs = sz(r);
	for(int i = 0; i < rs; i++)
		if(r[i] > 4) {
			while(t > 0 && r[i] > 4) {
				t--;
				if(i == 0) {
					inc(l);
					for(int d : l)
						cout << d;
					return 0;
				}
				i--;
				r[i]++;
			}
			while(r[i] == 10) {
				if(i == 0) {
					inc(l);
					for(int d : l)
						cout << d;
					return 0;
				}
				i--;
				r[i]++;
			}
			for(int j = 0; j < ls; j++)
				cout << l[j];
			cout << '.';
			for(int j = 0; j <= i; j++)
				cout << r[j];
			return 0;
		}
	for(int i = 0; i < ls; i++)
		cout << l[i];
	cout << '.';
	for(int i = 0; i < rs; i++)
		cout << r[i];
}
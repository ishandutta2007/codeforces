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


int main() {
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> s(n);
	for(int i = 0; i < n; i++) {
		char c;
		cin >> c;
		s[i] = (c == 'r');
	}

	vector<int> t(n, 0);
	for(int i = 1; i < n; i += 2)
		t[i] = !t[i];
		

	int w = 0, w1 = 0;
	for(int i = 0; i < n; i++)
		if(s[i] != t[i]) {
			if(s[i] == 0) w++;
			else w1++;
		}
	int ans1 = max(w, w1);

	for(int i = 0; i < n; i++)
		t[i] = !t[i];

	w = 0; w1 = 0;
	for(int i = 0; i < n; i++)
		if(s[i] != t[i]) {
			if(s[i] == 0) w++;
			else w1++;
		}
	int ans2 = max(w, w1);

	cout << (min(ans1, ans2));
}
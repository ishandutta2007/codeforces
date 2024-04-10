//By Don4ick 
//#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
typedef unsigned int ui;

#define forn(i, n) for (int i = 1; i <= n; i++)
#define pb push_back
#define all(x) x.begin(), x.end()
#define y1 qewr1234

const double PI = acos(-1.0);
const int DIR = 4;
const int X[] = {1, 0, -1, 0};
const int Y[] = {0, 1, 0, -1};

using namespace std;
string s;
int n;

int ok(vector<char> a, vector<int> v) {
	int mid = v.size()/2;
	if(v[mid] < 2) return 0;
	int l = mid-1;
	int r = mid+1;
	while(l >= 0 && r < (int)a.size()) {
		if(a[l] != a[r]) return 0;
		if(v[l] + v[r] < 3) return 0;
		l--;
		r++;
	}
	return 1;
}

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie();
	//cout.tie();		

	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	cin >> s;
	vector<int> v;
	vector<char> x;
	for(int i = 0; i < (int)s.size(); i++) {
		if(x.size()>0 && x.back() == s[i]) {
			v.back()++;
		} else {
			v.pb(1);
			x.pb(s[i]);
		}
	}
	if(x.size() % 2 == 0) {
		cout<<0<<"\n";
		return 0;	
	}
	if(ok(x, v)) {
	   	cout << v[v.size()/2]+1 << "\n";
	}
	else {
		cout << 0 << "\n";
	}
	return 0;
}
#include <bits/stdc++.h>
 
#define pb push_back
#define ff first
#define ss second
#define sz(a) (int)(a).size()
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b
 
using namespace std;
 
typedef long long ll;
 
int main() {
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	set<string> ts;
	list<string> tl;
	vector<string> tv(n);
	for(int i = 0; i < n; i++)
		cin >> tv[i];
	for(int i = n - 1; i >= 0; --i)
		if(ts.find(tv[i]) == ts.end()) {
			tl.pb(tv[i]);
			ts.insert(tv[i]);
		}
	for(string ts : tl)
		cout << ts << "\n";
}
#include <bits/stdc++.h>
#define sz(x) (int)(x).size()
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
// head

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<char> a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	int ans = 0;
	for(int i = 0; i < n && a[i] == '<'; i++)
		ans++;
	for(int i = n-1; i >= 0 && a[i] == '>'; i--)
		ans++;
	cout << ans;
}
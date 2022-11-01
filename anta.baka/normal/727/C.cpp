#include <bits/stdc++.h>
#define all(a) (a).begin(),(a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
// head

int main() {
//	ios_base::sync_with_stdio(false), cin.tie(NULL);
	int n; cin>>n;
	vector<int> a(n);
	int x, y, z;
	cout << "? 1 2\n"; cout.flush();
	cin >> x;
	cout << "? 2 3\n"; cout.flush();
	cin >> y;
	cout << "? 1 3\n"; cout.flush();
	cin >> z;
	a[1] = (x + y - z) / 2;
	a[0] = x - a[1];
	a[2] = y - a[1];
	for(int i = 3; i < n; i++) {
		cout << "? " << i << ' ' << i+1 << "\n";  cout.flush();
		int x; cin >> x;
		a[i] = x - a[i-1];
	}
	cout << "! ";
	for(int i = 0; i < n; i++)
		cout << a[i] << ' ';
	cout.flush();
}
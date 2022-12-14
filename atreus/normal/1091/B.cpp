#include <bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll,int> pii;

const int maxn = 1e5 + 10;

int X[maxn], Y[maxn], x[maxn], y[maxn];

int main(){
	ios_base::sync_with_stdio(false);	
	int n;
	cin >> n;
	
	for (int i = 1; i <= n; i++)
		cin >> x[i] >> y[i];
	for (int i = 1; i <= n; i++)
		cin >> X[i] >> Y[i];
	sort(x + 1, x + n + 1);
	sort(X + 1, X + n + 1, greater <int> ());
	sort(y + 1, y + n + 1);
	sort(Y + 1, Y + n + 1, greater <int> ());
	cout << x[1] + X[1] << " " << y[1] + Y[1] << endl;
}
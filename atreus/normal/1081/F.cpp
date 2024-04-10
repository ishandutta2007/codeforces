#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, ll> pii;
const int maxn = 1e5 + 100;

int a[maxn];

int ask(int l, int r){
	int x;
	cout << "? " << l << " " << r << endl;
	cin >> x;
	cout << "? " << l << " " << r << endl;
	cin >> x;
	return x;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, t;
	cin >> n >> t;
	int untilnow = 0;
	memset(a, -1, sizeof a);
	for (int i = n; i >= 2; i--){
		for (int j = 1; j <= 20; j++){
			int q = ask(1, i - 1);
			if (q != t){
				if (q == t - untilnow - 1 + (n - i) - untilnow){
					a[i] = 1;
				}
				else{
					a[i] = 0;
				}
				for (int k = 1; k <= 20; k++){
					int p = ask(1, i - 1);
					if (p == t)
						break;
				}
				break;
			}
		}
		if (a[i] == -1){
			if (untilnow >= (n - i + 1) / 2){
				a[i] = 0;
			}
			else{
				a[i] = 1;
			}
		}
		untilnow += a[i];
	}
	if (untilnow == t)
		a[1] = 0;
	else
		a[1] = 1;
	cout << "! ";
	for (int i = 1; i <= n; i++)
		cout << a[i];
	cout << endl;
}
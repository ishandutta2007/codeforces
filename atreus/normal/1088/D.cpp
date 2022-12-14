#include <bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define MP make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int a[5000];

int main(){
	ios_base::sync_with_stdio(false);
	ll c = 0, d = 0;
	int fi;
	cout << "? " << c << " " << d << endl;
	cin >> fi;
	for (int i = 29; i >= 0; i--){
		if (fi == 1){
			cout << "? " << c + (1 << i) << " " << d + (1 << i) << endl;
			int se;
			cin >> se;
			if (se == -1){
				c += (1 << i);
				cout << "? " << c << " " << d << endl;
				cin >> fi;
				continue;
			}
			cout << "? " << c + (1 << i) << " " << d << endl;
			int th;
			cin >> th;
			if (th == -1){
				c += (1 << i);
				d += (1 << i);
			}
		}
		else if (fi == 0){
			cout << "? " << c + (1 << i) << " " << d << endl;
			int se;
			cin >> se;
			if (se == -1){
				c += (1 << i);
				d += (1 << i);
			}
		}
		else{
			cout << "? " << c + (1 << i) << " " << d + (1 << i) << endl;
			int se;
			cin >> se;
			if (se == 1){
				d += (1 << i);
				cout << "? " << c << " " << d << endl;
				cin >> fi;
				continue;
			}
			cout << "? " << c << " " << d + (1 << i) << endl;
			int th;
			cin >> th;
			if (th == 1){
				c += (1 << i);
				d += (1 << i);
			}
	
		}
	}
	cout << "! " << c << " " << d << endl;
}
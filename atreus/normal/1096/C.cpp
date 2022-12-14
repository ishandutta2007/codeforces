#include <bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

const int mod = 998244353;

int angle[200];

int main(){
	ios_base::sync_with_stdio(false);
	memset(angle, -1, sizeof angle);
	for (int i = 3; i <= 500; i++){
		for (int j = 1; j <= i - 1; j++){
			for (int k = j + 1; k <= i - 1; k++){
				if (180 * (k - j) % i != 0)
					continue;
				int ang = 180 * (k - j) / i;
				if (angle[ang] == -1)
					angle[ang] = i;
			}
		}
	}
	int tc;
	cin >> tc;
	for (int i = 1; i <= tc; i++){
		int ang;
		cin >> ang;
		cout << angle[ang] << endl;
	}
}
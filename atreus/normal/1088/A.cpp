#include <bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define MP make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int main(){
	ios_base::sync_with_stdio(false);
	int x;
	cin >> x;
	for (int a = 1; a <= x; a++){
		for (int b = 1; b <= a; b++){
			if (a % b != 0)
				continue;
			if (a * b > x and a < x * b)
				return cout << a << " " << b << endl, 0;
		}
	}
	cout << -1 << endl;
}
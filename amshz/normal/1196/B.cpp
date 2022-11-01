#include <bits/stdc++.h>
using namespace std;
typedef long long       ll;
typedef long double     ld;
typedef string          str;
#define all(x)			(x).begin(),(x).end()
#define Sort(x)			sort(all(x))
#define A               first
#define B               second
#define sep             ' '
#define endl            '\n'
#define fast_io         ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int MAX1 = 5e5 + 7;

ll a, b, c, T, d, e, x1, y1, x2, y2, l, r, x, y, z, mid, cnt, flag, num[MAX1], mod = 1e9+7;
vector <ll> vec;

int main(){
	cin >> T;
	for (int k = 0; k < T; ++k){
		cin >> a >> b;
		vec.clear();
		for (int i = 1; i <= a; ++i){
			cin >> x;
			if (x%2 == 1)	vec.push_back(i);
		}
		if (vec.size() < b || vec.size()%2 != b%2){
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		for (int i = vec.size()-b; i < vec.size()-1; ++i)	cout << vec[i] << sep;
		cout << a;
		cout << endl;
	}
    return 0;
}
/*                          now or never                         */
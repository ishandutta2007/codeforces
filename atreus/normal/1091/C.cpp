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

ll f(int n, int x){
	int k = n / x;
	return 1ll * x * k * (k - 1) / 2 + k;
}

int main(){
	ios_base::sync_with_stdio(false);	
	int n;
	cin >> n;
	set <ll> s;
	for (int i = 1; 1ll * i * i <= n; i++){
		if (n % i == 0){
			s.insert(f(n, i));
			if (i * i != n)
				s.insert(f(n, n / i));
		}
	}
	for (auto it : s)
		cout << it << " ";
}
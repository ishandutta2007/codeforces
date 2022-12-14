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
	int n, k;
	cin >> n >> k;
	set <int> s;
	for (int i = 1; i <= n; i++){
		int x;
		cin >> x;
		s.insert(x);
	}
	int lazy = 0;
	while (!s.empty() and k){
		int x = *s.begin();
		s.erase(x);
		k --;
		cout << x - lazy << endl;
		lazy = x;
	}
	while (k --){
		cout << 0 << endl;
	}
}
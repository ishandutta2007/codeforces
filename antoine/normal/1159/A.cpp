#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);


	int curr=0, res=0;

	int n;
	cin >> n;
	while(n--) {
		char c;
		cin >> c;
		if(c=='-')
			res=min(res, --curr);
		else
			++curr;
	}
	cout << curr-res;
	return 0;
}
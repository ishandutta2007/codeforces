#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
typedef complex<ld> point;
const int maxn = 1000 + 5;

ll a[5], b[5];

void ask(ll y){
	cout << y << endl;
	int idx;
	cin >> idx;
	if (idx == 0)
		exit(0);
	a[idx] += y;
	b[1] = a[1], b[2] = a[2], b[3] = a[3];
	sort(b+1, b+4);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> a[1] >> a[2] >> a[3];
	cout << "First" << endl;
	b[1] = a[1], b[2] = a[2], b[3] = a[3];
	sort(b+1, b+4);
	ask(b[3]-b[1] + b[3]-b[2]);
	if (b[2] - b[1] == b[3] - b[2])
		ask(b[2]-b[1]);
	ask(b[3]-b[1] + b[3]-b[2]);
	ask(b[2]-b[1]);
}
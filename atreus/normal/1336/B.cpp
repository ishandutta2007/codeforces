#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
const ll inf = (ll)3e19;

ll diff(ll a, ll b){
	return (a-b) * (a-b);
}

ll solve(vector<int> &a, vector<int> &b, vector<int> &c){
	int ptb = 0, ptc = 0;
	ll ret = inf;
	for (int i = 0; i < (int)a.size(); i++){
		while (ptb < (int)b.size() - 1 and b[ptb+1] <= a[i])
			ptb ++;
		while (ptc < (int)c.size() - 1 and c[ptc] < a[i])
			ptc ++;
		ret = min(ret, diff(a[i], b[ptb]) + diff(a[i], c[ptc]) + diff(b[ptb], c[ptc]));
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc --){
		int a, b, c;
		cin >> a >> b >> c;
		vector<int> A(a), B(b), C(c);
		for (int i = 0; i < a; i++)
			cin >> A[i];
		for (int i = 0; i < b; i++)
			cin >> B[i];
		for (int i = 0; i < c; i++)
			cin >> C[i];
		sort(A.begin(), A.end());
		sort(B.begin(), B.end());
		sort(C.begin(), C.end());
		cout << min({solve(A,B,C), solve(A,C,B), solve(B,A,C), solve(B,C,A), solve(C,A,B), solve(C,B,A)}) << '\n';
	}
}
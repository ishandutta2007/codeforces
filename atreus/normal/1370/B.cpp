#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 300 + 10;
const int mod = 998244353;

ll dp[maxn][maxn][maxn];
int a[maxn], pre[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc --){
		int n;
		cin >> n;
		vector<int> A, B;
		for (int i = 1; i <= 2*n; i++){
			int x;
			cin >> x;
			if (x & 1)
				A.push_back(i);
			else
				B.push_back(i);
		}
		int cnt = 0;
		for (int i = 1; i < A.size() and cnt < n-1; i += 2, cnt ++)
			cout << A[i] << " " << A[i-1] << '\n';
		for (int i = 1; i < B.size() and cnt < n-1; i += 2, cnt ++)
			cout << B[i] << " " << B[i-1] << '\n';
	}
}
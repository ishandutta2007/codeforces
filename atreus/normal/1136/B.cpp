#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef long double ld;
 
const int maxn = 500 + 10;

int a[maxn][maxn], b[maxn][maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	int pos = min((k - 1) + (n - 1), (n - k) + (n - 1));
	int stones = n + 1;
	cout << pos + stones + n << endl;
}
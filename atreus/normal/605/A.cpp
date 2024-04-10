#include <iostream>
#include <stack>

using namespace std;


const int maxn = 1e5 + 500;
int a[maxn], dp[maxn], lef[maxn];
stack <int> s;

int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int k = 0;
	for (int i = 0; i < n; i++){
		dp[a[i]] = dp[a[i] - 1] + 1;
		k = max(k, dp[a[i]]);
	}
	cout << n - k << endl;
}
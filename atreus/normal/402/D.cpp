#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <map>
#include <cmath>


using namespace std;

const int maxn = 5e3 + 100;
map <int, int> dp;
unordered_map <int, bool> mark, bady;
int gcdd[maxn], a[maxn];

int _gcd(int x, int y){
	if (x < y)
		swap (x, y);

	if (x % y == 0)
		return y;
	return _gcd(x % y, y);
}

int f(int n){
	if (n == 1)
		return 0;
	if (mark[n])
		return dp[n];
	mark[n] = 1;
	bool isprime = true;
	for (int i = 2; i <= sqrt(n); i++)
		if (n % i == 0){
			dp[n] = f(n / i);
			if (bady[i] == 1)
				dp[n] --;
			else
				dp[n] ++;
			isprime = false;
			break;
		}
	if (isprime == true){
		if (bady[n])
			dp[n] = -1;
		else
			dp[n] = 1;
	}
	return dp[n];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int j = 0; j < m; j++){
		int badprime;
		cin >> badprime;
		bady[badprime] = 1;
	}
	gcdd[0] = a[0];
	for (int i = 1; i < n; i++)
		gcdd[i] = _gcd(gcdd[i - 1], a[i]);
	for (int i = n - 1; i >= 0; i--){
//		cout << i << " " << gcdd[i] << " " << f(gcdd[i]) << endl;
		if (f(gcdd[i]) < 0){
			for (int j = 0; j <= i; j++){
				a[j] /= gcdd[i];
				gcdd[j] /= gcdd[i];
			}
		}
	}
	int k = 0;
	for (int i = 0; i < n; i++)
		k += f(a[i]);
	cout << k << endl;
}
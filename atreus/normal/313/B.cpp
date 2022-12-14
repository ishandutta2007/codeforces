#include <iostream>
#include <vector>
#include <stdio.h>
#include <time.h>
#include <set>
#include <unordered_map>
#include <unordered_set>
#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;

int dp[200000];

int main(){
	string s, a;
	cin >> a;
	s = '0' + a;
	for (int i = 1; i < s.size(); i++)
		dp[i] = dp[i - 1] + (s[i] == s[i - 1]);
	int q;
	cin >> q;
	for (int i = 0; i < q; i++){
		int l, r;
		cin >> l >> r;
		cout << dp[r] - dp[l] << endl;
	}
}
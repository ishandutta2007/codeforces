/*
 *      Author: arsijo;
 */

#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin);
#define output freopen("output.txt", "w", stdout);
#define io input; output;
#define ll long long
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));
#define ld double
#define MAX 500
#define si short int

int main() {

	//io;

	int sum, n;
	cin >> sum >> n;

	vector<int> v;

	int res = 0;
	for(int i = n; i > 0; i--){
		if(res + (i & -i) <= sum){
			res += (i & -i);
			v.push_back(i);
		}
	}

	if(res < sum){
		cout << "-1";
	}else{
		cout << v.size() << "\n";
		for(int i = 0; i < v.size(); i++)
			cout << v[i] << " ";
	}

}
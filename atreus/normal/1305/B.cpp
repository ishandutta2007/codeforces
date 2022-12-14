#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
const int mod = 1e9 + 7;
const int maxn = 2e5 + 10;

int par[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	int n = s.size();
	bool answer = 0, baz = 0;
	for (int i = 0; i < n; i++){
		baz |= (s[i] == '(');
		answer |= (baz and (s[i] == ')'));
	}
	if (answer == 0){
		cout << 0 << endl;
		return 0;
	}
	for (int i = n - 1; i >= 0; i--)
		par[i] = par[i + 1] + (s[i] == ')');
	int cnt = 0;
	for (int i = 0; i < n; i++){
		if (s[i] == '(')
			cnt ++;
		if (cnt == par[i + 1]){
			cout << 1 << '\n';
			cout << 2 * cnt << '\n';
			for (int j = 0; j <= i; j++)
				if (s[j] == '(')
					cout << j + 1 << " ";
			for (int j = i + 1; j < n; j++)
				if (s[j] == ')')
					cout << j + 1 << " ";
			return 0;
		}
	}
	cout << 0 << endl;
}
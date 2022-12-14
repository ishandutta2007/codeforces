#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t --){
		int n;
		cin >> n;
		string s;
		cin >> s;
		int a = 0, b = 0;
		for (int i = 0; i < n; i++){
			if (s[i] == '<')
				a ++;
			if (s[i] == '>')
				b ++;
		}
		if (a == 0 or b == 0){
			cout << n << '\n';
			continue;
		}
		int cnt = 0;
		for (int i = 0; i < n; i++)
			if (s[i] == '-' or s[(i+1)%n] == '-')
				cnt ++;
		cout << cnt << '\n';
	}
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 1e5 + 5;

int main(){
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int f = -1;
	for (int i = k; i < n; i++){
		if (s[i] != s[i - k]){
			f = i;
			break;
		}
	}
	if (f == -1){
		cout << n << endl << s << endl;
		return 0;
	}
	if (s[f] < s[f - k]){
		for (int i = f; i < n; i++)
			s[i] = s[i - k];
		cout << n << endl << s << endl;
		return 0;
	}
	for (int i = min(k - 1, f - 1); i >= 0; i--){
		if (s[i] == '9')
			continue;
		int me = (int)(s[i] - '0');
		me ++;
		s[i] = (char)(me + '0');
		for (int j = i + 1; j < k; j++)
			s[j] = '0';
		for (int j = k; j < n; j++)
			s[j] = s[j - k];
		cout << n << endl << s << endl;
		return 0;
	}
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 1e6 + 10;

int f[maxn];

string get(string a, string &b){
	string s;
	if (a.size() < b.size())
		s = a + "#" + b.substr(b.size() - a.size(), a.size());
	else
		s = a + "#" + b;
	f[0] = f[1] = 0;
	int n = s.size();
	int k = 0;
	for (int i = 1; i < n; i++){
		while (k > 0 and s[i] != s[k])
			k = f[k];
		k += (s[i] == s[k]);
		f[i + 1] = k;
	}
	if (f[n] == a.size())
		return "";
	return a.substr(f[n], a.size() - f[n]);
}

string s[maxn];

int main(){
	ios_base::sync_with_stdio (false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	string untilnow = s[0];
	for (int i = 1; i < n; i++){
		string t = get(s[i], untilnow);
		untilnow += t;
	}
	cout << untilnow << endl;
}
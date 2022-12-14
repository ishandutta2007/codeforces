#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1000 + 5;
const int mod = 1e9 + 7;

bool check(string s){
	int n = s.size();
	string t = "abacaba";
	int cnt = 0;
	for (int i = 0; i < n-6; i++)
		if (s.substr(i,7) == t)
			cnt ++;
	return cnt == 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc --){
		string s, t = "abacaba";
		int n;
		cin >> n >> s;
		bool flag = 0;
		for (int i = 0; i < n-6; i++){
			int x = 0;
			for (int j = i; j < i+7; j++)
				if (s[j] == t[j-i] or s[j] == '?')
					x ++;
			if (x == 7){
				string me = s;
				for (int j = i; j < i+7; j++)
					me[j] = t[j-i];
				for (int i = 0; i < n; i++)
					if (me[i] == '?')
						me[i] = 'z';
				if (check(me)){
					cout << "YES\n";
					cout << me << '\n';
					flag = 1;
					break;
				}
			}
		}
		if (!flag)
			cout << "NO\n";
	}
}
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 2000 + 7;

int cnt[29];

char diff(string &a, string &b){
	memset(cnt, 0, sizeof cnt);
	for (auto it : a)
		cnt[(int)(it - 'a')] ++;
	for (auto it : b)
		cnt[(int)(it - 'a')] --;
	for (int i = 0; i < 26; i++)
		if (cnt[i])
			return (char)(i + 'a');
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	if (n == 1){
		cout << "? 1 1" << endl;
		string a;
		cin >> a;
		cout << "! " << a << endl;
		return 0;
	}
	cout << "? " << 1 << " " << n << endl;
	multiset<string> s;
	for (int i = 1; i <= n * (n + 1) / 2; i++){
		string a;
		cin >> a;
		sort(a.begin(), a.end());
		s.insert(a);
	}
	cout << "? " << 2 << " " << n << endl;
	for (int i = 1; i <= n * (n - 1) / 2; i++){
		string a;
		cin >> a;
		sort(a.begin(), a.end());
		s.erase(s.find(a));
	}
	string ans = "";
	for (int i = 1; i <= n; i++){
		string a = "", b = "";
		for (auto it : s){
			if (it.size() == i)
				a = it;
			if (it.size() == i - 1)
				b = it;
		}
		ans += diff(a, b);
	}
	cout << "! " << ans << endl;
}
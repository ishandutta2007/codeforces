#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int maxn = 5e5 + 10;

int cnt[2], f[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	string s, t;
	cin >> s >> t;
	if (t.size() > s.size())
		return cout << s << endl, 0;
	for (int i = 0; i < s.size(); i++){
		if (s[i] == '1')
			cnt[1] ++;
		else
			cnt[0] ++;
	}
	f[0] = 0, f[1] = 0;
	int k = 0;
	for (int i = 1; i < t.size(); i++){
		while (k != 0 and t[k] != t[i])
			k = f[k];
		k += (t[k] == t[i]);
		f[i + 1] = k;
	}
	int idx = 0;
	for (int _ = 0; _ < s.size(); _++){
		if (t[idx] == '1'){
			if (cnt[1]){
				cout << 1;
				idx ++;
				if (idx == t.size())
					idx = f[idx];
				cnt[1] --;
			}
			else{
				cout << 0;
				cnt[0] --;
			}
		}
		else{
			if (cnt[0]){
				cout << 0;
				idx ++;
				if (idx == t.size())
					idx = f[idx];
				cnt[0] --;
			}
			else{
				cout << 1;
				cnt[1] --;
			}
		}
	}
	cout << endl;
}
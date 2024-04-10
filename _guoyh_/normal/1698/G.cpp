# include <bits/stdc++.h>
using namespace std;
typedef __int128 ll;
const int MAXS = 36;
int n;
char str[MAXS];
ll p, a;
int pl;
const int LIM = (1 << 18);
map <ll, int> mp;
int main(){
	cin >> str;
	n = strlen(str);
	for (int i = n; i >= 1; i--) str[i] = str[i - 1];
	str[0] = 0;
	while (n >= 1 && str[n] == '0') n--;
	int ds = -1;
	bool flag = false;
	for (int i = 1; i <= n; i++){
		if (str[i] == '1' && !flag){
			ds = i - 1;
			flag = true;
		}
		if (flag) p |= (ll)(str[i] == '1') << (pl++);
	}
	if (ds == -1){
		cout << "-1\n";
		return 0;
	}
	if (pl == 1){
		cout << ds + 1 << ' ' << ds + 2 << '\n';
		return 0;
	}
	a = 1;
	mp[a] = 0;
	for (int i = 1; i <= LIM; i++){
		bool flg = (a >> (pl - 2)) & 1;
		a <<= 1;
		if ((a >> (pl - 1)) & 1) a ^= p;
		if (a == 1){
			cout << ds + 1 << ' ' << ds + i + 1 << '\n';
			return 0;
		}
		if (i < LIM) mp[a] = i;
	}
	ll b = 1;
	for (int i = 1; i <= LIM; i++){
		ll b1 = 0;
		for (int j = 0; j < pl - 1; j++){
			if ((a >> j) & 1) b1 ^= (b << j);
		}
		for (int j = pl - 1; j >= 0; j--){
			if ((b1 >> (j + pl - 1)) & 1) b1 ^= (p << j);
		}
		b = b1;
		if (mp.find(b) != mp.end()){
			cout << ds + 1 << ' ' << ds + 1 + 1ll * LIM * i - mp[b];
			return 0;
		}
	}
	cout << "-1\n";
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".dat", "r", stdin); freopen(x ".sol", "w", stdout);
#define MAX 100000
#define ms(x) memset(x, 0, sizeof(x));
#define input freopen("input.txt", "r", stdin);
#define ll long long
#define ld long double
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const ld E = 1e-9;

int main() {

	sync;

	string s;
	cin >> s;

	int m;
	cin >> m;

	int ar[s.length()];
	ms(ar);

	while(m--){
		int a;
		cin >> a;
		ar[min(a - 1, (int) s.length() - a)]++;
	}

	int ans = 0;

	string st = "";

	for(int i = 0; i < s.length() / 2; i++){
		ans += ar[i];
		if(ans % 2 == 0){
			cout << s[i];
			st = st + s[s.length() - i - 1];
		}else{
			cout << s[s.length() - i - 1];
			st = st + s[i];
		}
	}

	if(s.length() % 2 == 1)
		cout << s[s.length() / 2];

	for(int i = st.length() - 1; i >= 0; i--)
		cout << st[i];


}
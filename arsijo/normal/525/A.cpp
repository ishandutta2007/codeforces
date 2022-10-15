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
	int n;
	cin >> n;
	string s;
	cin >> s;
	map<char, int> m;
	int ans = 0;
	for(int i = 0; i < s.length(); i++){
		if(i % 2 == 0){
			m[s[i]]++;
		}else{
			int a = s[i] - 'A' + 'a';
			char c = (char) a;
			if(m[c] > 0){
				m[c]--;
			}else{
				ans++;
			}
		}
	}

	cout << ans;

}
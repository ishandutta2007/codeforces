#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define ms(x) memset(x, 0, sizeof(x));
#define input freopen("input.txt", "r", stdin);
#define output freopen("output.txt", "w", stdout);
#define ll long long
#define y1 ngsdf
#define ld long double
#define sqr(a) ( (a) * (a) )
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const ld E = 1e-9;
const int MAX = 1e9;

int main() {

	string s;
	cin >> s;
	char ans[s.length()];
	int size = 0;
	for(int i = 0; i < s.length(); i++)
		if(size == 0 || ans[size - 1] != s[i])
			ans[size++] = s[i];
		else
			size--;

	for(int i = 0; i < size; i++)
		cout << ans[i];
}
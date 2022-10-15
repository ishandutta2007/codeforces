#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define MAX 300001
#define ms(x) memset(x, 0, sizeof(x));
#define input freopen("input.txt", "r", stdin);
#define ll long long
#define ld long double
#define sqr(a) ( (a) * (a) )
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const ld E = 1e-9;

int main() {

	string s;
	cin >> s;

	vector<string> v;
	v.push_back("");
	for(int i = 0; i < (int) v.size(); i++){
		if(v[i] == s){
			cout << i;
			return 0;
		}
		v.push_back(v[i] + "4");
		v.push_back(v[i] + "7");
	}

}
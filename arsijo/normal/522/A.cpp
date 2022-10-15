/*
 *      Author: arsijo;
 */

#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
//#define files(x) freopen(x ".dat", "r", stdin); freopen(x ".sol", "w", stdout);
#define input freopen("input.txt", "r", stdin);
#define ll long long
#define ui unsigned int
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));
#define ld long double
#define mod % 1000000007

string reMake(string s){
	string ans = "";
	for(int i = 0; i < s.length(); i++){
		if('A' <= s[i] && s[i] <= 'Z'){
			ans += (s[i] - 'A' + 'a');
		}else{
			ans += s[i];
		}
	}
	return ans;
}

int main() {

	map<string, int> m;

	int ans = 1;

	m.insert(m.begin(), make_pair("polycarp", 1));

	int n;
	cin >> n;

	while(n--){
		string s1, s2, s3;
		cin >> s1 >> s2 >> s3;
		s1 = reMake(s1);
		s3 = reMake(s3);
		m[s1] = m[s3] + 1;
		ans = max(ans, m[s1]);
	}

	cout << ans << endl;

}
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 17;
int n, cnt[7];

int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	while(n--){
		string s;
		cin >> s;
		for(int i = 0; i < 7; i++)
			cnt[i] += s[i] == '1';
	}
	cout << *max_element(cnt, cnt + 7) << '\n';
	return 0;
}
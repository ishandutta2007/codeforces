#include <iostream>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 40;

int main(){
	ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc --){
		int n;
		string s;
		cin >> n >> s;
		int cnt1 = 0, cnt0 = 0;
		for (int i = 1; i < s.size(); i++){
			if (s[i] == '1' and s[i-1] == '1')
				cnt1 ++;
			if (s[i] == '0' and s[i-1] == '0')
				cnt0 ++;
		}
		cout << max(cnt0,cnt1) << '\n';
	}
}
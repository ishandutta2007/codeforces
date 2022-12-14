#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t --){
		string s;
		cin >> s;
		int n = s.size();
		int cnt = 0, now = 0;
		for (int i = n-1; i >= 0; i--){
			if (s[i] == 'A'){
				if (now > 0)
					now --;
				else
					cnt ++;
			}
			else
				now ++;
		}
		cout << cnt + (now&1) << '\n';
	}
}
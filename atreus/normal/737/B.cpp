#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
const int maxn = 2e5 + 10;

int main(){
	ios_base::sync_with_stdio(false);
	int n, a, b, k;
	cin >> n >> a >> b >> k;
	string s;
	cin >> s;
	s += '1';
	int cnt = 0, all = 0;
	for (int i = 0; i <= n; i++){
		if (s[i] == '1'){
			all += cnt / b;
			cnt = 0;
		}
		else
			cnt ++;
	}
	int answer = all - a + 1;
	cout << answer << endl;
	cnt = 0;
	for (int i = 0; i <= n; i++){
		if (s[i] == '1')
			cnt = 0;
		else{
			cnt ++;
			if (cnt % b == 0 and answer > 0){
				cout << i + 1 << " ";
				answer --;
			}
		}
	}
	cout << endl;
}
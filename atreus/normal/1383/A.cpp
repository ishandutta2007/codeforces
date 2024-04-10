#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 20;

int cnt[22][22];

int main(){
	ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc --){
		int n;
		string s, t;
		cin >> n >> s >> t;
		bool found = 0;
		for (int i = 0; i < 20; i++)
			for (int j = i+1; j < 20; j++)
				cnt[i][j] = 0;
		for (int i = 0; i < n; i++){
			int a = (int)s[i] - 'a';
			int b = (int)t[i] - 'a';
			if (b < a){
				found = 1;
				break;
			}
			if (b > a)
				cnt[a][b] ++;
		}
		if (found){
			cout << -1 << '\n';
			continue;
		}
		int answer = 0;
		for (int i = 0; i < 20; i++){
			for (int j = i+1; j < 20; j++){
				if (cnt[i][j] > 0){
					answer ++;
					cnt[i][j] = 0;
					for (int k = j+1; k < 20; k++){
						cnt[j][k] += cnt[i][k];
						cnt[i][k] = 0;
					}
					break;
				}
			}
		}
		cout << answer << '\n';
	}
}
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

const int maxn = 1e3 + 10;

int lng[maxn][maxn];
string s[maxn];

ll get(int t){
	return t * (t + 1) / 2;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	for (int i = 0; i < m; i++)
		lng[0][i] = 1;
	for (int i = 1; i < n; i++)
		for (int j = 0; j < m; j++)
			lng[i][j] = (s[i][j] == s[i - 1][j] ? lng[i - 1][j] + 1 : 1);
	ll answer = 0;
	for (int i = 0; i < n; i++){
		for (int j = i; j < n; j++){
			int len = j - i + 1;
			if (len > i or len > n - j - 1)
				continue;
			int pre = i - 1, nex = j + len, cnt = 0;
			for (int k = 0; k < m; k++){
				if (lng[j][k] == len and lng[pre][k] >= len and lng[nex][k] == len){
					if (k == 0 or (cnt > 0 and s[j][k] == s[j][k - 1] and s[nex][k] == s[nex][k - 1] and s[pre][k] == s[pre][k - 1]))
						cnt ++;
					else{
						answer += get(cnt);
						cnt = 1;
					}
				}
				else{
					answer += get(cnt);
					cnt = 0;
				}
			}
			answer += get(cnt);
		}
	}
	cout << answer << endl;
}
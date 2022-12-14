#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
const int maxn = 2e5 + 10;

int a[maxn], b[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n, s;
	cin >> n >> s;
	bool flag = 0;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		if (i == s and a[i] != 0){
			a[i] = 0;
			flag = 1;
		}
		if (i != s and a[i] == 0)
			a[i] = n;
		b[a[i]] ++;
	}
	int cnt = 0, empty = 0;
	int answer = n;
	for (int i = 0; i <= n; i++){
		if (b[i] == 0)
			empty ++;
		cnt += b[i];
		answer = min(answer, max(n - cnt, empty) + flag);
	}
	cout << answer << endl;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2000 + 10;

map<int, int> occur;
int a[maxn];

int main(){
	ios_base::sync_with_stdio (false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	int answer = n;
	for (int i = 0; i <= n; i++){
		if (occur[a[i]] > 0)
			break;
		answer = min(answer, n - i);
		occur[a[i]] ++;
		for (int j = n; j > i; j--){
			if (occur[a[j]] > 0){
				for (int k = j + 1; k <= n; k++)
					occur[a[k]] --;
				break;
			}
			occur[a[j]] ++;
			answer = min(answer, n - (i + (n - j + 1)));
		}
		if (answer == 0)
			break;
	}
	cout << answer << endl;
}
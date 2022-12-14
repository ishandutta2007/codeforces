/**
 *    author:  Atreus
**/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 2e5 + 10;
int a[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int mx = 0;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		mx = max(mx, a[i]);
	}
	int answer = 0, last = -1;
	for (int i = 1; i <= n; i++){
		if (a[i] == mx){
			if (last == -1)
				last = i;
			answer = max(answer, i - last + 1);
		}
		else
			last = -1;
	}
	cout << answer << endl;
}
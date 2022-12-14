#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 7000 + 10;

ll a[maxn], b[maxn];
bool mark[maxn];

int main(){
	ios_base::sync_with_stdio (false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		cin >> b[i];
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			if (i == j)
				continue;
			if (a[i] == a[j])
				mark[i] = 1;
		}
	}
	ll sum = 0;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			if (mark[j] == 1 and (a[i] & a[j]) == a[i]){
				sum += b[i];
				break;
			}
		}
	}
	cout << sum << endl;
}
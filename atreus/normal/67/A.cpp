#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn = 1000 + 10;
const int inf = 2e9;

int a[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	string s;
	cin >> n >> s;
	for (int i = 0; i < n; i++)
		a[i] = 1;
	bool found = 1;
	while (found){
		found = 0;
		for (int i = 0; i < n - 1; i++){
			if (s[i] == 'R' and a[i] >= a[i+1]){
				a[i+1] = a[i]+1;
				found = 1;
			}
			if (s[i] == 'L' and a[i] <= a[i+1]){
				a[i] = a[i+1]+1;
				found = 1;
			}
			if (s[i] == '=' and a[i] != a[i+1]){
				int t = max(a[i],a[i+1]);
				a[i] = a[i+1] = t;
				found = 1;
			}
		}
	}
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn = 2e5 + 50;
const int mod = 1e9 + 7;

int a[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int v = 29; v >= 0; v--){
		int now = (1 << 30) - 1, cnt = 0;
		for (int i = 0; i < n; i++){
			if (a[i] & (1 << v)){
				now &= a[i];
				cnt ++;
			}
		}
		int mask = (1 << (v+1)) - 1;
		if ((now & mask) == (1 << v)){
			cout << cnt << endl;
			for (int i = 0; i < n; i++)
				if (a[i] & (1 << v))
					cout << a[i] << " ";
			cout << '\n';
			return 0;
		}
	}
	for (int i = 0; i < n; i++)
		cout << a[i] << " \n"[i ==n-1];
}
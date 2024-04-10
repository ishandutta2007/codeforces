#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn = 1000 + 10;
const int inf = 2e9;

int a[maxn], b[maxn];
bool mark[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> b[i];
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			if (mark[j] == false and b[j] == 0){
				mark[j] = true;
				a[i] = j;
				for (int x = j - k; x >= 1; x--)
					b[x] --;
				break;
			}
		}
	}
	for (int i = 1; i <= n; i++)
		cout << a[i] << " \n"[i==n];
}
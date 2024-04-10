#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 10;

int a[maxn];

int main(){
    ios_base::sync_with_stdio(false); 
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		a[i] ^= a[i-1];
	}
	if (n > 60)
		return cout << 1 << endl, 0;
	int answer = -1;
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++)
			for (int k = j+1; k <= n; k++)
				for (int x = k; x <= n; x++)
					if ((a[j]^a[i-1]) > (a[x]^a[k-1])){
						int len = j-i + x-k;
						if (answer == -1 or answer > len)
							answer = len;
					}
	cout << answer << endl;
}
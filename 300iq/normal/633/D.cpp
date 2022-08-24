#include <bits/stdc++.h>
#define int long long

using namespace std;

main() {	
	int n;
	cin>>n;
	map <int, int> count;
map <pair <int, int>, bool> sif;
	vector <int> f(n);
	for (int i = 0; i < n; i++){
		cin >> f[i];
		count[f[i]]++;
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
                        if (sif[{f[i], f[j]}]) continue;
                        sif[{f[i], f[j]}] = 1;
			map <int, int> fib;
			fib[f[i]] = 1;
			fib[f[j]]++;
			int counter = 2;
			int f1 = f[i], f2 = f[j];
			while (true) {
				int f3 = f1 + f2;
				if (fib[f3] >= count[f3]) 
					break;
				fib[f3]++;
				counter++;
				f1 = f2;
				f2 = f3;
			}
			ans = max(ans, counter);
		}
	}
	cout << ans << endl;
}
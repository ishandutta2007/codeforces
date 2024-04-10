#include <bits/stdc++.h>

using namespace std;

char a[55][55];

main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) cin >> a[i][j];
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            if (a[i][j] == '.'){
                a[i][j] = '#';
                if (a[i + 1][j] == '#' || a[i + 2][j] == '#' || a[i + 1][j + 1] == '#' || a[i + 1][j - 1] == '#' || i + 2 > n || j == n || j == 1){
                    cout << "NO" << '\n';
                    return 0;
                }
                a[i + 1][j] = '#';
                a[i + 2][j] = '#';
                a[i + 1][j + 1] = '#';
                a[i + 1][j - 1] = '#';
            }
        }
    }
    cout << "YES" << '\n';
	return 0;
}
#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
        int n, k;
        cin >> n >> k;
        if((n%2 == 0 && k%2 == 1 && k*2 > n) || n < k || (n%2 == 1 && k%2 == 0))
            cout << "NO\n";
        else{
            cout << "YES\n";
            int a = 1;
            if(n%2 == 0 && k%2 == 1)
                a = 2;
            for(int i = 0; i < k-1; ++i)
                cout << a << ' ';
            cout << n-a*(k-1) << '\n';
        }
	}
	return 0;
}
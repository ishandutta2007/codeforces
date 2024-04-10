//In The Name of Allah
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 10;

#define pb push_back

int t, a, b, c;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> t;
    
    while(t--){
    	cin >> a >> b >> c;
    	int ans = 0;
    	for(int i = 0; i <= a; i++){
    		if(2 * i > b) break;
    		ans = max(ans, 3 * i + min(b - 2 * i, c / 2) * 3);
		}
		cout << ans << endl;
	}
    
    return 0;
}
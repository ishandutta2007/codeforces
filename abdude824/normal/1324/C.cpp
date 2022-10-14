#include <bits/stdc++.h>
 
using namespace std;
 
#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair<ll, ll> pll;  

ll n;
vector<ll> m;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
    	string s;
    	cin >> s;
    	vector<int> bad;
    	bad.resize(s.size() + 1, 0);
    	for (int j = 0; j < s.size(); j++)
    		if (s[j] == 'L')
    			bad[j + 1] = bad[j] + 1;
    	int ans = 0;
    	for (int j = 0; j < bad.size(); j++)
    		ans = max(ans, bad[j] + 1);
    	cout << ans << endl;
    }




    return 0;
}
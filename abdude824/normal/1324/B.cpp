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
    	int k;
    	cin >> k;
    	vector<ll> a;
    	a.resize(k);
    	for (int j = 0; j < k; j++)
    		cin >> a[j];
    	bool good = false;
    	for (int j = 0; j < k; j++)
    		for (int u = j + 2; u < k; u++)
    			if (a[j] == a[u])
    				good = true;
    	if (good)
    		cout << "YES" << endl;
    	else
    		cout << "NO" << endl;
    }




    return 0;
}
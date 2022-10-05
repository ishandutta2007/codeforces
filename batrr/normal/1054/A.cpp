#include <bits/stdc++.h>

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)1e5 + 123, inf = 1e9;
const ll INF = 1e18;

int main(){
	ll x, y, z, t1, t2, t3, a, b;
	cin >> x >> y >> z;
	cin >> t1 >> t2 >> t3;
	a = abs(x - y) * t1;
	b = abs(x - y) * t2 + abs(x - z) * t2 + 3 * t3;
	if(a >= b)         
		cout << "YES";
	else
		cout << "NO";	
	return 0;
}
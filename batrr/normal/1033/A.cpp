#include <bits/stdc++.h>

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)1e6 + 123, mod = (int)1e9 + 7, inf = (int)1e9, LOG = 18;

int sgn(int x){
	if(x > 0)
		return 1;
	return -1;
}
int main(){
	int n;
	pii a, b, c;
	cin >> n;          
	cin >> a.f >> a.s;
	cin >> b.f >> b.s;
	cin >> c.f >> c.s;
	b.f -= a.f;
	b.s -= a.s;
	c.f -= a.f;
	c.s -= a.s;
	if(sgn(b.f) == sgn(c.f) && sgn(b.s) == sgn(c.s))
		cout << "YES";
	else
		cout << "NO";
}
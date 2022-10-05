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
	int x;
	cin >> x;
	for(int a = 1; a <= x; a++)
		for(int b = 1; b <= a; b++)
			if(a % b == 0 && a * b > x && a / b < x)
				cout << a << " " << b, exit(0); 
	cout << -1;
	return 0;
}
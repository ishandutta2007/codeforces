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

int n, a[N];
int main(){
	cin >> n;       
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	cout << n + 1 << endl;
	for(int i = n; i >= 1; i--){
		int val = ((i - 1 - a[i]) % n + n) % n;
		for(int j = 1; j <= i; j++)
			a[j] += val;
		cout << 1 << " " << i << " " << val << endl;
	}
	cout << 2 << " " << n << " " << n << endl;
	return 0;
}
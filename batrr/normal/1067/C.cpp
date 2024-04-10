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

int X[4] = {0, 1, 0, -1};
int Y[4] = {1, 0, -1, 0};

int n;

int main () {
	cin >> n;
	cout << 0 << " " << 0 << endl;
	for(int i = 0; i < n - 1; i++)
		cout << X[i % 4] * (i / 4 + 1) << " " << Y[i % 4] * (i / 4 + 1) << endl;
	return 0;
}
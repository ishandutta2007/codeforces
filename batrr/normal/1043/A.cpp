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

ll n, a[110], sum, x, y;
int main(){
	cin >> n;
    for(int i = 0; i < n; i++){
		cin >> a[i];
		sum += a[i];
	}
	sort(a, a + n);
	for(int k = a[n - 1];;k++){
		x = sum;
		y = 1ll * n * k - sum;
		if(x < y){
			cout << k;
			break;
		}
	}
	return 0;
}
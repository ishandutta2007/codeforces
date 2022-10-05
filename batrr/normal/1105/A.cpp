#include <bits/stdc++.h>                                                                                                                                                                                      //YaLoh

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
pii ans = {inf, inf};
int main(){
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 1; i <= 100; i++){
		int cur = 0;
		for(int j = 0; j < n; j++)
			cur += min(min(abs(a[j] - i - 1),abs(a[j] - i + 1)), abs(a[j] - i));
		ans = min(ans,{cur, i});
	}
	cout << ans.s << " " << ans.f;
	return 0;
}
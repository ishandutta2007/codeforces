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

int n, k, ans;
string s;
int main(){
	cin >> n >> k;
	cin >> s;
	for(int j = 0; j < 26; j++){
		int q = 0, cur = 0;
		for(int i = 0; i < n; i++){
			if(s[i] == j + 'a')
				q++;
			else
				q = 0;
			if(q == k)
				q = 0, cur++;
		}
		ans = max(ans, cur);
	}
	cout << ans;
	return 0;
}
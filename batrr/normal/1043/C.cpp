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

int n, cur;
string s;
bool ans[N];
int main(){
	cin >> s;
	n = s.size();
	for(int i = 1; i < n; i++){           
		if(s[i] == 'a' && s[i - 1] == 'a')
			ans[i] = 0;		

		if(s[i] == 'a' && s[i - 1] == 'b')
			ans[i] = 1;		

		if(s[i] == 'b' && s[i - 1] == 'a')
			ans[i] = 1;		

		if(s[i] == 'b' && s[i - 1] == 'b')
			ans[i] = 0;		
	}
	if(s[n - 1] == 'a')
		ans[n] = 1;
	for(int i = 1; i <= n; i++)
		cout << ans[i] << " ";
	return 0;
}
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
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		sort(s.begin(), s.end());
		if(s[0] == s[s.size() - 1])
			s = "-1";
		cout << s << endl;
	}
	return 0;
}
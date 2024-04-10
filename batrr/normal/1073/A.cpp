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
	int n;
	string s;

	cin >> n;
	cin >> s;
	for(int i = 0; i + 1 < n; i++){
		if(s[i] != s[i + 1]){
			cout << "YES" << endl;
			cout << s[i] << s[i + 1] << endl;
			return 0;
		}
	}
	cout << "NO";
	return 0;
}
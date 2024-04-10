#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)						(x).begin(),(x).end()
#define X							first
#define Y							second
#define sep							' '
#define endl						'\n'
#define SZ(x)						ll(x.size())

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int q , n;
string s;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> q;
	while(q--){
		cin >> s; n = SZ(s);
		int first = MOD , last = -1 , cnt = 0;
		int flag0 = 0 , flag1 = 0;
		for(int i = 0 ; i < n ; i++){
			if(s[i] == '0'){
				flag0 = 1;
				first = min(first , i);
				last = max(last , i);
				cnt++;
			}
			else{
				flag1 = 1;
			}
		}
		if(flag0 == 0){
			cout << 0 << endl;
			continue;
		}
		if(last - first + 1 == cnt){
			cout << 1 << endl;
			continue;
		}
		cout << 2 << endl;
	}

    return 0;
}
/*

*/
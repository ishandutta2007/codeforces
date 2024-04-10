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

int q , n , cnt0 , cnt1;
string s , A , B;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> q;
	while(q--){
		cin >> n >> s; cnt0 = cnt1 = 0;
		A = B = "";
		for(int i = 0 ; i < n ; i++){
			if(s[i] == '0')	cnt0++;
			if(s[i] == '1')	cnt1++;
		}
		if(cnt0 % 2 == 1 || s[0] == '0' || s[n - 1] == '0'){
			cout << "NO" << endl;
			continue;
		}
		int cur = 0 , diff = 0;
		for(int i = 0 ; i < n ; i++){
			if(s[i] == '0'){
				if(diff % 2 == 0){
					A.push_back('(');
					B.push_back(')');
				}
				else{
					A.push_back(')');
					B.push_back('(');
				}
				diff++;
			}
			if(s[i] == '1'){
				if(cur < cnt1 / 2){
					A.push_back('(');
					B.push_back('(');
				}
				else{
					A.push_back(')');
					B.push_back(')');
				}
				cur++;
			}
		}
		cout << "YES" << endl << A << endl << B << endl;
	}

    return 0;
}
/*

*/
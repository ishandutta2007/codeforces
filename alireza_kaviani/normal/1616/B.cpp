#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)      (x).begin(),(x).end()
#define X           first
#define Y           second
#define sep         ' '
#define endl        '\n'
#define SZ(x)       ll(x.size())

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int q , n;
string s, B;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> q;
	while(q--){
		cin >> n >> s;
		int ind = n;
		for(int i = 1 ; i < n ; i++){
			if(s[i] > s[i - 1]){
				ind = i;
				break;
			}
		}
		string A = s.substr(0 , 1);
		string B = s.substr(0 , ind);
		string C = B;
		reverse(all(C));
		cout << min(A + A , B + C) << endl;
	}

    return 0;
}
/*

*/
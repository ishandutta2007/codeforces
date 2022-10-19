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

int A;
string s;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	for(int i = 0 ; i < 8 ; i++){
		cin >> s;
		for(int j = 0 ; j < 8 ; j++){
			char c = (s[j] | 32);
			int point = 0;
			if(c == 'q')	point = 9;
			if(c == 'r')	point = 5;
			if(c == 'b')	point = 3;
			if(c == 'n')	point = 3;
			if(c == 'p')	point = 1;
			if(97 <= s[j])	A -= point;
			else	A += point;
			//cout << i << sep << j << sep << A << endl;
		}
	}
	if(A > 0)	return cout << "White" << endl , 0;
	if(A < 0)	return cout << "Black" << endl , 0;
	cout << "Draw" << endl;

    return 0;
}
/*

*/
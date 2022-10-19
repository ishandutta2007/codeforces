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

int n , x , y;
string s;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n >> s;
	for(int i = 0 ; i < n ; i++){
		if(s[i] == 'A')	x++;
		if(s[i] == 'D')	y++;
	}
	if(x > y){
		cout << "Anton" << endl;
	}
	else if(x < y){
		cout << "Danik" << endl;
	}
	else{
		cout << "Friendship" << endl;
	}

    return 0;
}
/*

*/
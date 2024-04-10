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

int n , flag = -1 , pos = -1;
string s , t;

string get(string s){
	while(s.back() == '0')	s.pop_back();
	if(s.back() == '.')	s.pop_back();
	return s;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> s; n = SZ(s);
	for(int i = 0 ; i < n ; i++){
		if(s[i] == '.'){
			pos = i;
			continue;
		}
		if(flag == -1 && s[i] != '0'){
			flag = i;
			t.push_back(s[i]);
			t.push_back('.');
			continue;
		}
		if(flag != -1){
			t.push_back(s[i]);
		}
	}
	if(pos == -1)	pos = n;
	t = get(t); cout << t;
	int E = pos - flag;
	if(E > 0)	E--;
	if(E == 0)	return 0;
	cout << "E" << E << endl;

    return 0;
}
/*

*/
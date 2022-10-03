#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN=1000 * 1000 + 10;

int n, m;
string s, t;

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	cin>>n>>m;
	s="5";
	t="5";
	n-=5;
	while (n>0){
		s="45"+s;
		t="54"+t;
		n-=9;
	}
	cout<</*(char)('0'+n)<<*/s<<endl;
	cout<</*(char)('0'+n)<<*/t<<endl;
	return 0;
}
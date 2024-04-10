#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)
using namespace std;

int inv(int a, int b){
	return a-1 ? b - inv(b%a,a)*b/a : 1;
}

int main(){
	int n,p,q;
	string s;
	cin >> n >> p >> q >> s;
	int d = __gcd(p,q);
	if(n % d != 0){
		puts("-1");
		return 0;
	}
	n /= d, p /= d, q /= d;
	int pp = n*inv(p,q)%q;
	int qq = (n-p*pp)/q;
	if(qq < 0){
		puts("-1");
		return 0;
	}
	p *= d, q *= d;
	cout << pp+qq << endl;
	int pos = 0;
	rep(_,0,pp){
		cout << s.substr(pos,p) << endl;
		pos += p;
	}
	rep(_,0,qq){
		cout << s.substr(pos,q) << endl;
		pos += q;
	}
}
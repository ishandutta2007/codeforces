#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN=100 * 1000 + 10;

ll s, x, a, ans=1;

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>s>>x;
	a=s-x;
	int f=2*(s==x);
	if (s<x || a%2 || ((a/2) & x)){
		cout<<0<<endl;
		return 0;
	}
	a/=2;
	for (; x; x/=2,a/=2){
		if (x%2) ans*=2;
	}
	cout<<ans-f<<endl;
	return 0;
}
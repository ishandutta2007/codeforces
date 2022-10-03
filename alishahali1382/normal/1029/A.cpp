#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN=1000 * 1000 + 10;

ll n, k, res, tmp;
string s;

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	cin>>n>>k;
	cin>>s;
	for (int i=1; i<n; i++){
		if (s.substr(0, i)==s.substr(n-i, i)) res=i;
	}
	string ss=s.substr(0, n-res);
	for (int i=0; i<k-1; i++){
		cout<<ss;
	}
	cout<<s<<endl;
	//cout<<res<<endl;
		
	
	return 0;
}
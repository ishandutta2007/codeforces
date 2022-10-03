#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps=1e-10;
const int inf=1000000000;
const int mod = 998244353;
const int MAXN = 2000010;

int n, l=0, r=inf;
string s, black;

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	cout<<"0 0"<<endl;
	cin>>black;
	for (int i=1; i<n; i++){
		int mid=(l+r)/2;
		cout<<"0 "<<mid<<endl;
		cin>>s;
		if (s==black) l=mid;
		else r=mid;
	}
	if (n<30) cout<<"0 "<<(l+r)/2<<" 1 "<<(l+r)/2<<endl;
	else{
		if (l>3) cout<<"1 "<<l<<" 3 "<<l-1<<endl;
		else cout<<"1 "<<r<<" 3 "<<r+1<<endl;
		
	}
	
	
	return 0;
}
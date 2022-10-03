#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps=1e-10;
const int inf=1000000010;
const int mod = 1000 * 1000 * 1000 + 7;
const int MAXN = 200010;

ll x, y, z, t1, t2, t3;
ll A[MAXN];

string s;

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>x>>y>>z>>t1>>t2>>t3;
	if ((abs(x-z)+abs(x-y))*t2+t3*3<=abs(x-y)*t1) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	/*
	cerr<<(abs(x-z)+abs(x-y))*t2+t3*2<<endl;
	cerr<<abs(x-y)*t1<<endl;
	*/
	return 0;
}
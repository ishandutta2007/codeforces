#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps=1e-10;
const int inf=1000000010;
const int mod = 1000 * 1000 * 1000 + 7;
const int MAXN = 110;

int n, m;
string s;

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	while (n--){
		cin>>s;
		m=s.size();
		if (m<=10){
			cout<<s<<endl;
			continue ;
		}
		cout<<s[0]<<m-2<<s[m-1]<<endl;
	}
	
	return 0;
}
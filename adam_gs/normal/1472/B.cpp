#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n, sum=0, j=0, d=0;	
		cin >> n;
		while(n--) {
			int a;
			cin >> a;
			if(a==1) ++j; else ++d;
		}
		bool ans=false;
		if(j%2==0) {
			ans=true;
			if(j==0) {
				ans=false;
				if(d%2==0) ans=true;
			}
		}
		cout << (ans?"YES":"NO") << '\n';
	}
}
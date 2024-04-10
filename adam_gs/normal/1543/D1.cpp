#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define all(a) a.begin(), a.end()
int xorplus(int a, int b, int k) {
	int pot=1, ans=0;
	while(a || b) {
		ans+=(((a%k)+(b%k))%k)*pot;
		pot*=k; a/=k; b/=k;
	}
	return ans;
} 
int xorminus(int a, int b, int k) {
	int pot=1, ans=0;
	while(a || b) {
		ans+=(((a%k)-(b%k)+k)%k)*pot;
		pot*=k; a/=k; b/=k;
	}
	return ans;
}
void solve() {
	int n, k;
	cin >> n >> k;
	int p=0, np=0;
	rep(i, n) {
	    int pytanie=0;
	    if(i%2==0) {
	        pytanie=xorplus(xorminus(np, p, k), i, k);
	    } else {
	        pytanie=xorminus(xorminus(p, np, k), i, k);
	    }
	    cout << pytanie << endl;
		int a;
		cin >> a;
		if(a) return;
		if(i%2==0) {
		    p=xorplus(p, pytanie, k);
		} else {
		    np=xorplus(np, pytanie, k);
		}
	}
}
int main() {
	int _;
	cin >> _;
	while(_--) solve();
}
#include <iostream>
#include <cstdio>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); i++)

int main(){
	cin.sync_with_stdio(0);
	int n;
	cin >> n;
	int ans = 1, a = 0;
	rep(_,1,n){
		a += 12;
		ans += a;
	}
	cout << ans << endl;
}
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)
#define rrep(i,a,b) for(int i = (b); i--> int(a);)

int c[10] = {6,2,5,5,4,5,6,3,7,6};

int cost(int a){
	int ans = 0;
	while(a){
		ans += c[a%10];
		a /= 10;
	}
	return ans;
}

int main(){
	int a,b,ans = 0;
	cin >> a >> b;
	rep(i,a,b+1){
		ans += cost(i);
	}
	cout << ans << endl;
}
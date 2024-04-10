#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#define pb push_back
#define ll long long
#define mp make_pair
#define ff first
#define sc second
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
using namespace std;
ll n, a, b, k = 0, l = 0, x = 0, y = 0, t = 0;
int main () {
	cin >> n;
	for(int i = 0; i<n; i++){
		cin >> a >> b;
		if(a%2 != b%2){
			k += a%2;
			l += b%2;
		}
		else {
			x += a%2;
			y += a%2;
		}	
	}
	x%=2;
	y%=2;
	if((x+k+l+y)%2){
		cout << -1;
		return 0;
	}
	if((x+k)%2 == 0 && (y+l)%2 == 0){
		cout << 0;
		return 0;
	}
	if(x%2 == 0){
		cout << 1;
		return 0;
	}
	if(x%2 == 1){
		if(k == 0 && l == 0){
			cout << -1;
			return 0;
		}
		cout << 1;
		return 0;
	}
    return 0;
}
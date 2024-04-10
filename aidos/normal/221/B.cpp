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
#define pis pair<int, string>
#define psi pair<string, int>
using namespace std;
int check(int n, int m){
	int a[20], b[20];
	for(int i = 0; i<10; i++)
		a[i] = 0;
	while(n > 0) {
		a[n%10] = 1;	
		n/=10;
	}
	while(m > 0){
		if(a[m%10] == 1) return 1;
		m/=10;
	}
	return 0;
}
int main () {
	int n, ans = 0;
	cin >> n;
	for(int i = 1; i*i <=n; i++){
		if(n%i == 0){
			int x = n/i;
			if(x == i) ans += check(n, i);
			else ans += check(n, i) + check(n, x);
		}
	}
	cout << ans;
    return 0;
}
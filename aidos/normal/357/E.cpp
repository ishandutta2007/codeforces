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
int main () {
	int n, k = 0, c[10], t = 0;
	c[0]= c[1]=c[2]=c[3]=c[4] = 0;
	cin >> n;
	for(int i = 0; i<n; i++){
		scanf("%d", &k);
		c[k]++;
	}
	t = c[1] + 2*c[2] +3*c[3] +4*c[4];
	if(t < 3 || t == 5){
		cout << -1;
		return 0;
	}
	if(c[1] == c[2]){
		cout << c[1];
	}
	else if(c[1] < c[2]){
		int ans = c[1];
		c[2] -= c[1];
		c[3] += c[1];
		c[1] = 0;
		ans += c[2] / 3 * 2;
		c[2] %= 3;
		if(c[2] == 1 && c[4] > 0) ans ++;
		else if(c[2])ans += 2;
		cout << ans;
	}
	else {
		int ans = c[2];
		c[1] -= c[2];
		c[3] += c[2];
		c[2] = 0;
		c[3] += c[1]/3;
		ans += c[1]/3*2;
		c[1] %= 3;
		if(c[1] == 1){
			if(c[3] > 0) ans ++;
			else ans += 2;
		}
		else if(c[1] == 2){
			if(c[3] > 1) ans += 2;
			else ans += 2;
		}
		cout << ans;
	}
    return 0;
}
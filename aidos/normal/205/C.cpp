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
ll f(ll a){
	if(a == 0) return 0;
	vector < int > v;
	ll x = a, ans = 18;
	while(x){
		v.pb(x%10);
		x/=10;
	}
	if(v.size() == 1) return v[0];
	if(v.size() == 2){
		if(v[0] < v[1]) return v[1] + 8;
		return v[1] + 9;
	}
	int vs = v.size();
	ll pow10[30];
	pow10[0] = 1;
	for(int i = 1; i<19;i++)
		pow10[i] = 10ll*pow10[i-1];
	for(int i = 3; i<vs; i++){
		ans += pow10[i-2] * 9ll;
	}
	for(int i = 0; i<19; i++){
		if(pow10[i] == a){
			return ans;
		}
	}
	if(v[0] < v[vs-1]){
		a -= v[0] + 1;
		v.clear();
		x = a;
		while(x){
			v.pb(x%10);
			x/=10;
		}
	}
	ans += pow10[vs-2] * 1ll * (v[vs-1] - 1);
	a /= 10;
	int g = 0;
	for(int i = 1; i<19; i++){
		if(a >= pow10[i]) g=i;
		else break;
	}
	return ans + a%pow10[g] + 1;
}
int main () {
	ll a, b;
	cin >> a >> b;
	cout << f(b)-f(a-1) <<endl;
    return 0;
}
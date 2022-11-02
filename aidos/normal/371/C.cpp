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
ll a = 0, b = 0, c = 0, na, nb, nc, pa, pb, pc, r, tl = 0, tr, ans = 0;
bool check(ll x){
	ll aa = x * 1ll * a, bb = x*1ll*b, cc = x*1ll*c;
	if(aa < na) aa = 0;
	else aa -= na;
	if(bb < nb) bb = 0;
	else bb -= nb;
	if(cc < nc) cc=0;
	else cc-=nc;
	ll get = aa * 1ll*pa + bb * 1ll*pb + pc *1ll* cc;
	if(get <= r) return 1;
	return 0;
}
int main () {
	string s;
	cin >> s;
	for(int i = 0; i<s.size(); i++)
		if(s[i] == 'B') a++;
		else if(s[i] == 'S') b++;
		else c++;
	cin >> na >> nb >> nc >> pa >> pb >> pc >> r;
	tr = r+10000;
	while(tl <= tr){
		ll mid = (tl+tr)>>1;
		if(check(mid)){
			ans = mid;
			tl = mid+1;
		}
		else tr = mid-1;
	}
	cout << ans;
    return 0;
}
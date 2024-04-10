// Son
#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

const ll Mod = 1000000007LL;
const int N = 1e6 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

int n, mxl, sm;
int ans = Mod;
int ask(int w){
	cout << "? " << w << endl;
	int res;
	cin >> res;
	if(res)
		ans = min(ans, w * res);
	return res;
}

int FindMax(){ // 11
	int L = 0, R = 2000 + 1;
	int mid;
	while(L + 1 < R){
		mid = (L + R) >> 1;
		if(ask(mid) != 0) R = mid;
		else L = mid;
	}
	return R;
}
int FindSum(){ // 22
	int L = mxl - 1, R = n * mxl + 1;
	int mid;
	while(L + 1 < R){
		mid = (L + R) >> 1;
		if(ask(mid + (n - 1)) == 1) R = mid;
		else L = mid;
	}
	return R;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	mxl = FindMax();
	sm = FindSum();

	int po = 2, ch = n - 2;
	while(po <= ch){
		if( ask((sm + ch) / po) <= po) ch --;
		else po ++;
	}

	cout << "! " << ans << endl;
	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> int(a);)
#define allof(v) v.begin(),v.end()
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<vi> M;
const int inf = 2e9;
const ll md = 1e9+7;

int main(){
	int n;
	cin >> n;
	vi a(n);
	for(int &aa : a) cin >> aa;
	sort(allof(a)); reverse(allof(a));
	ll ans = 0;
	rep(i,0,n){
		if(a[i] == 0) break;
		ans += a[i];
		if(i < n-1) a[i+1] = min(a[i+1], a[i]-1);
	}
	cout << ans << endl;
}
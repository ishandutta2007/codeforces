#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <stack>
#include <queue>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> int(a);)
#define allof(v) v.begin(),v.end()
#define pb push_back
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pii;
const int inf = 2e9;

ll f(ll x){
	return x*(x-1)/2;
}

int main(){
    int n;
    vector<int> di(2001), id(2001);
    cin >> n;
    rep(_,0,n){
    	int x,y;
    	cin >> x >> y;
    	di[x+y]++;
    	id[x-y + 1000]++;
    }
    ll ans = 0;
    rep(i,0,2001){
    	ans += f(di[i]) + f(id[i]);
    }
    cout << ans << endl;
}
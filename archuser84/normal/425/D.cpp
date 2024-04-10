///
///    Hashire sori yo 
///    Kaze no you ni  
///    Tsukimihara wo  
///    PADORU PADORU   
///

#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
#define LoopR(x,l,r) for(ll x = ll(r)-1; x >= ll(l); --x)
#define Kill(x) exit((cout << (x) << '\n', 0))
typedef long long ll;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
using namespace std;

const int N = 100'010;
const int S = 310;
vector<int> a[N], b[N];
int n;

bool check1(int x, int y1, int y2){
	return 0 <= x && x < N && binary_search(a[x].begin(), a[x].end(), y1) && binary_search(a[x].begin(), a[x].end(), y2);
}
bool check2(int y, int x1, int x2){
	return 0 <= y && y < N && binary_search(b[y].begin(), b[y].end(), x1) && binary_search(b[y].begin(), b[y].end(), x2);
}

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n;
	Loop(i,0,n){
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
	}
	Loop(i,0,N) sort(a[i].begin(), a[i].end());
	ll ans = 0;
	Loop(k,0,N){
		if(a[k].size() < S){
			Loop(i,0,a[k].size()) Loop(j,i+1,a[k].size()){
				ans += check1(k+a[k][j]-a[k][i], a[k][i], a[k][j]);
				ans += check1(k+a[k][i]-a[k][j], a[k][i], a[k][j]);
			}
			a[k].clear();
		} else {
			for(int y : a[k]) b[y].push_back(k);
		}
	}
	Loop(k,0,N){
		Loop(i,0,b[k].size()) Loop(j,i+1,b[k].size())
			ans += check2(k+b[k][j]-b[k][i], b[k][i], b[k][j]);
	}
	cout << ans << '\n';
}
///
///    Hashire sori yo 
///    Kaze no you ni  
///    Tsukimihara wo  
///    PADORU PADORU   
///

#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
#define LoopR(x,l,r) for(ll x = ll(r)-1; x >= ll(l); --x)
typedef long long ll;
typedef std::pair<int,int> pii;
using namespace std;

const int N = 200'010;
int a[N];
int ans[N];
pii in[N];
int n;

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n;
	Loop(i,0,n){
		int x, y;
		cin >> x >> y;
		--x; --y;
		a[x] = y; a[y] = x;
		in[i] = {x, y};
	}
	Loop(i,0,2*n){
		int j = i;
		while(!ans[j]){
			ans[j] = 1;
			ans[j^1] = 2;
			j = a[j^1];
		}
	}
	Loop(i,0,n) cout << ans[in[i].first] << ' ' << ans[in[i].second] << '\n';
}
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
using namespace std;

const int N = 2010;
int a[N], b[N], c[N];
int n;

int fans = 0;
vector<pii> ans;

void sswap(int x, int y){
	fans += abs(x - y);
	swap(a[x], a[y]);
	ans.emplace_back(x, y);
}

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n;
	Loop(i,0,n) cin >> a[i], a[i]--;
	Loop(i,0,n) cin >> b[i], b[i]--;
	Loop(i,0,n) c[b[i]] = i;
	Loop(i,0,n) a[i] = c[a[i]];
	vector<int> padoru;
	Loop(i,0,n) padoru.push_back(i);
	Loop(_,0,n){
		int i, j;
		for(i = 0; a[padoru[i]] > padoru[i]; ++i){}
		for(j = i; a[padoru[j]] != padoru[j]; --j)
			sswap(padoru[j-1], padoru[j]);
		padoru.erase(padoru.begin()+j);
	}
	cout << fans << '\n' << ans.size() << '\n';
	for(auto [i, j] : ans) cout << i+1<<' '<<j+1 << '\n';
}

//
// 2 4 1 3
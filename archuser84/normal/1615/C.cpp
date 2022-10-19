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
string a, b;

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n >> a >> b;
		int cnt[2][2] = {};
		Loop(i,0,n){
			cnt[a[i]-'0'][b[i]-'0']++;
		}
		int ans = 1e9;
		if(cnt[0][1] == cnt[1][0]) ans = min(ans, cnt[1][0]+cnt[0][1]);
		if(cnt[0][0]+1 == cnt[1][1]) ans = min(ans, cnt[0][0]+cnt[1][1]);
		cout << (ans==1e9?-1:ans) << '\n';
	}
}
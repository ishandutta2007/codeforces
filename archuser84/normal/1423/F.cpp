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

const int N = 200'010;
ll sum;
pair<ll,ll> muda[N];

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	ll n, k;
	cin >> n >> k;
	Loop(i,0,k){
		ll a, b;
		cin >> a >> b;
		sum += b;
		muda[i] = {a,b};
	}
	if(sum > n) Kill(-1);
	if(sum < n) Kill(1);
	if(k==1) Kill(n&1?1:-1);
	sort(muda,muda+k);
	ll n2 = n*(n+1)/2, sum2 = 0;
	Loop(i,0,k) sum2 += muda[i].first*muda[i].second;
	ll lst = n+1;
	LoopR(i,0,k)
	{
		sum2 += sum*(lst-muda[i].first);
		sum2 -= n*muda[i].second;
		lst = muda[i].first;
		if(n2>=sum2 && (n2-sum2)%sum == 0 && (n2-sum2)/sum <= (i? muda[i].first-muda[i-1].first-1: muda[0].first-muda[k-1].first-1+n)) Kill(1);
	}
	Kill(-1);
}
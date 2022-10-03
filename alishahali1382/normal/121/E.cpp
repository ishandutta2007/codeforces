#include <bits/stdc++.h>
#if defined(__GNUC__)
#pragma GCC optimize ("Ofast")
#endif
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 100010, SQ=320;

bool islucky(int x){
	for (; x; x/=10) if (x%10!=7 && x%10!=4) return 0;
	return 1;
}

int n, m, k, u, v, x, y, t, l, r, ans;
int A[MAXN];
bool lucky[MAXN];
vector<int> vec;
int cnt[SQ][10001];
int lazy[SQ];
string type;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i=1; i<10000; i++) if (lucky[i]=islucky(i)) vec.pb(i);
	cin>>n>>m;
	for (int i=1; i<=n; i++) cin>>A[i], cnt[i/SQ][A[i]]++;
	while (m--){
		cin>>type>>l>>r;
		r++;
		if (type=="add"){
			cin>>x;
			while (l<r){
				if (l%SQ==0 && l+SQ<r){
					lazy[l/SQ]+=x;
					l+=SQ;
				}
				else{
					cnt[l/SQ][A[l]]--;
					cnt[l/SQ][A[l]+=x]++;
					l++;
				}
			}
			continue ;
		}
		ans=0;
		while (l<r){
			if (l%SQ==0 && l+SQ<r){
				for (int x:vec) if (x-lazy[l/SQ]>=0) ans+=cnt[l/SQ][x-lazy[l/SQ]];
				l+=SQ;
			}
			else{
				ans+=lucky[A[l]+lazy[l/SQ]];
				l++;
			}
		}
		cout<<ans<<'\n'; 
	}
	
	return 0;
}
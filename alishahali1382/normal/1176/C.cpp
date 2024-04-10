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
const int MAXN = 100010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int cnt[6];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	while (n--){
		cin>>x;
		if (x==4) cnt[0]++;
		else if (x==8){
			if (cnt[0]) cnt[0]--, cnt[1]++;
			else ans++;
		}
		else if (x==15){
			if (cnt[1]) cnt[1]--, cnt[2]++;
			else ans++;
		}
		else if (x==16){
			if (cnt[2]) cnt[2]--, cnt[3]++;
			else ans++;
		}
		else if (x==23){
			if (cnt[3]) cnt[3]--, cnt[4]++;
			else ans++;
		}
		else if (x==42){
			if (cnt[4]) cnt[4]--;
			else ans++;
		}
	}
	for (int i=0; i<5; i++) ans+=(i+1)*cnt[i];
	cout<<ans<<'\n';
	
	return 0;
}
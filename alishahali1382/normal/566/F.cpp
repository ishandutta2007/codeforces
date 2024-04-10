#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps=1e-10;
const int inf=1000000010;
const int mod = 1000 * 1000 * 1000 + 7;
const int MAXN = 1000010;

int n, ans, tmp;
int cnt[MAXN];
int dp[MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=0; i<n; i++){
        cin>>tmp;
        cnt[tmp]++;
	}
	for (int i=1000000; i; i--){
        dp[i]=cnt[i];
        for (int j=2*i; j<=1000000; j+=i){
            dp[i]=max(dp[i], dp[j]+cnt[i]);
        }
        ans=max(ans, dp[i]);
	}

	cout<<ans<<endl;

	return 0;
}
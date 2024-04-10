#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps=1e-16;
const ld inf=1e18+100;
const int mod = 1000 * 1000 * 1000;
const int MAXN = 1000010;

ll n, a, ans;
ll cnt[40000];
ll A[4010];
ll ps[4010];
string s;

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>a>>s;
	n=s.size();
	for (int i=0; i<n; i++) A[i]=s[i]-'0';
	for (int i=1; i<=n; i++) ps[i]=ps[i-1]+A[i-1];
	
	for (int i=0; i<=n; i++){
		for (int j=i+1; j<=n; j++) cnt[ps[j]-ps[i]]++;
	}
	for (int i=1; i<=40000; i++) if (!(a%i) && a/i<=40000 && a) ans+=cnt[i]*cnt[a/i];
	if (!a) ans=n*(n+1)/2*cnt[0]*2-cnt[0]*cnt[0];
	cout<<ans<<endl;
	
	//for (int i=0; i<=7; i++) cerr<<cnt[i]<<' ';cerr<<endl;
	
	return 0;
}
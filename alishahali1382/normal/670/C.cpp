#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps=1e-10;
const int inf=1000000010;
const int mod = 1000 * 1000 * 1000 + 7;
const int MAXN = 300010;

int n, m, ans;
int a[MAXN], b[MAXN], c[MAXN];

map<int, int> mp;

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=0; i<n; i++){
		cin>>a[i];
		mp[a[i]]++;
	}
	cin>>m;
	for (int i=0; i<m; i++)cin>>b[i];
	for (int i=0; i<m; i++)cin>>c[i];	
	
	for (int i=1; i<m; i++){
		if (mp[b[i]]>mp[b[ans]] || (mp[b[i]]==mp[b[ans]] && mp[c[i]]>mp[c[ans]])) ans=i;
	}
	cout<<ans+1<<endl;
	
	return 0;
}
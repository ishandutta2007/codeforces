#include <bits/stdc++.h>
#define ld long double
#define ll long long
#define ull unsigned ll
#define pll pair<ll, ll>
#define itr(a) begin(a), end(a)
#define pb push_back
#define x first
#define y second
#define endl '\n'
#define FAST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FILES(namein, nameout) freopen(namein, "r", stdin); freopen(nameout, "w", stdout);
#define M 1000000007
#define N 200000
#define INF 101111111111111
using namespace std;
ll cnt[26];
int main(){
	FAST;
	ll q;
	cin >> q;
	while(q--){
		ll n;
		cin >> n;
		string s1, s2;
		cin >> s1 >> s2;
		for(ll i =0;i<26;i++) cnt[i] = 0;
		for(ll i = 0;i<n;i++) ++cnt[s1[i]-'a'], cnt[s2[i]-'a']++;
		bool res = 1;
		for(ll i = 0;i<26;i++) res = res & ((cnt[i]&1) == 0);
		if(!res) cout << "No" << endl;
		else{
			vector<pll> swaps;
			cout << "Yes" << endl;
			for(ll i = 0;i<n-1;i++){
				bool sw = 0;
				for(ll j = i+1;j<n;j++){
					if(s1[i] == s1[j]){
						swap(s2[i], s1[j]);
						swaps.pb({j, i});
						sw = 1;
						break;
					}
				}
				if(!sw){
					for(ll j = i;j<n;j++){
						if(s1[i] == s2[j]){
							swap(s2[j], s1[i+1]);
							swaps.pb({i+1, j});
							swap(s2[i], s1[i+1]);
							swaps.pb({i+1, i});
							break;
						}
					}
				}
			}
			cout << swaps.size() << endl;
			for(auto i : swaps) cout << i.x+1 << " " << i.y+1 << endl;
		}
	}
}
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
#define stopit(msg) cout << msg << endl; exit(0);
#define cstopit(msg) cout << msg << endl; continue;
#define astopit(msg) {stopit(msg)}
#define castopit(msg) {cstopit(msg)}
ll cnt1[26], cnt2[26];
int main(){
	FAST;
	ll q;
	cin >> q;
	while(q--){
		ll n;
		cin >> n;
		string s1, s2;
		cin >> s1 >> s2;
		for(ll i =0;i<26;i++) cnt1[i] = 0, cnt2[i] = 0;
		for(ll i =0;i<n;i++){
			cnt1[s1[i]-'a']++;
			cnt2[s2[i]-'a']++;
		}
		bool res = true;
		for(ll i =0;i<26;i++) res = res & (cnt1[i] == cnt2[i]);
		if(!res) castopit("NO");
		for(ll i =0;i<26;i++) if(cnt1[i] > 1) res = 0;
		if(!res) castopit("YES");
		ll in1 = 0, in2 = 0;
		for(ll i = 1;i<n;i++){
			for(ll j = 0;j<i;j++){
				if(s1[j]>s1[i]) ++in1;
				if(s2[j]>s2[i]) ++in2;
			}
		}
		if(in1%2 == in2%2) castopit("YES")
		else castopit("NO")
	}
}
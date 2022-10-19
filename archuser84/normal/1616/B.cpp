    ///
    ///         "People's Dreams.. Never End!!"
    ///
    ///                                   ~Marshall D. Teach
    #include<bits/stdc++.h>
     
    using namespace std;
     
    #define F first
    #define S second 
    #define pb push_back
    #define mk make_pair
    #define endl cout << '\n'
    #define haha cerr << "haha\n"
    #define all(x) x.begin(), x.end()
    #define kill(x) exit((cout << (x) << '\n', 0))
    #define yn(flag) ((flag) ? "YES\n": "NO\n")
    #define smax(x, y) (x) = max((x), (y))
    #define smin(x, y) (x) = min((x), (y))
    typedef long long ll;
    typedef long double ld;
    typedef pair<int, int> pii;
    typedef pair<int, pii> piii;
    typedef pair<ll, ll> pll;
    typedef pair<pll, ll> plll;
    //#pragma GCC optimize("Ofast,unroll-loops")
    //#pragma GCC target("avx2")
    ll const inf = 1'000'000'000'000'000 + 10;
    ll const mod = 1'000'000'000 + 7;
    ll const maxn = 300'000 + 10;
    ll const base = 337;
    ll const sq = 320;
    ll const lg = 25;
    ll const Z = 26;
    ll cnt[150];
     
     
    void Main() {
    	ll n;
    	string s;
    	cin >> n >> s;
    	s = s + char('z'+1);
    	ll x = s[0];
    	ll pnt = 1;
    	while (s[pnt] <= x) {
    		x = s[pnt];
    		++pnt;
    	}
    	if (n > 1 && s[0] == s[1])	{
    		cout << s[0] << s[0];
    		endl;
    		return;
    	}
    	for (ll i = 0; i < pnt; ++i) 
    		cout << s[i];
    	for (ll i = pnt - 1; ~i; --i)
    		cout << s[i];
    	endl;
    	return;
    }
     
    int main() {
    	ios::sync_with_stdio(false), cin.tie(0);
    	ll t = 1;
    	cin >> t;
    	while (t--) 
    		Main();
    }
     
    // check before submiting : 
    // maxn (please check this shit)
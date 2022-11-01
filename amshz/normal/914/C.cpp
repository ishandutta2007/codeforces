#include <bits/stdc++.h>
using namespace std;
typedef long long       ll;
typedef long double     ld;
typedef string          str;
#define all(x)            (x).begin(),(x).end()
#define Sort(x)            sort(all(x))
#define A               first
#define B               second
#define sep             ' '
#define endl            '\n'
#define fast_io         ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
const ll MAX1 = 5e5+7,
         MOD = 1e9+7;
 
ll n, x, ans, dp[1100], ent[1007][1007];
string s;
 
void fill_entekhab(){
    for (int i = 0; i <= 1000; ++i){
        ent[0][i] = 1;
        ent[i][i] = 1;
    }
    for (int i = 1; i < 1000; ++i){
        for (int j = i+1; j <= 1000; ++j){
            ent[i][j] = (ent[i][j-1]+ent[i-1][j-1])%MOD;
        }
    }
}
 
ll tedbi(ll a){
    string t = "";
    ll jav = 0, cnt = 0;
    while (a){
        t += '0'+a%2;
        a /= 2;
    }
    for (int i = 0; i < t.size(); ++i){
        if (t[i] == '1')    ++jav;
    }
    return jav;
}
 
ll javab(ll a){
    ll t = ent[a][s.size()];
    ll ted = 0;
    for (int i=0; i<s.size(); i++){
    	if (s[i] == '1') {
    		ted++;
    		continue;
		}
    	//ted++;
    	if (ted >= a) break;
    	
    	t -= ent[a-ted-1][s.size()-i-1];
	}
	while (t < 0)	t += MOD;
	return t;
}
 
int main(){
    fast_io;
    cin >> s >> n;
    fill_entekhab();
    //cout << s.size() << endl;
    //cout << javab(8) << endl;
    if (n == 0){
        cout << 1;
        return 0;
    }
    if (n == 1){
        cout << s.size()-1;
        return 0;
    }
    dp[1] = 1;
    for (int i = 2; i <= s.size(); ++i){
        dp[i] = dp[tedbi(i)]+1;
        // cout << i << sep << dp[i] << endl;
        if (dp[i] == n){
            // cout << i << endl;
            ans += javab(i);
            ans %= MOD;
        }
    }
    cout << ans;
    return 0;
}
/*                     now or never                         */
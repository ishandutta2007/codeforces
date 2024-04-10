#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x)  cerr << #x << " = " << x << endl
using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld PI = 3.14159265359;

const ll MOD = (ll) 998244353ll;
const ll MAXN = (ll) 2e5 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;

ll pw(ll b, ll p){
	if(p == 0) return 1;
	b %= MOD;
	if(p % 2 == 1) return (b * pw(b, p - 1)) % MOD;
	return pw(b * b, p / 2);
}

vector<ll> a;

ll b[MAXN];
ll po, ii, jj, cnt = 0;
void merg(ll l, ll mid, ll r){
    po = 0;
    ii = l;
    jj = mid + 1;
    while((ii <= mid) and (jj <= r)){
        if(a[ii] > a[jj]){
            b[po] = a[jj];
            jj ++;
            cnt = cnt + (mid - ii + 1);
        } else {
            b[po] = a[ii];
            ii ++;
        }
        po++;
    }
    for(int i = ii; i <= mid; i++){
        b[po] = a[i];
        po++;
    }
    for(int i = jj; i <= r; i++){
        b[po] = a[i];
        po++;
    }
    for(int i = 0;i < po;i++){
        a[l + i] = b[i];
        //cout << b[i] << " ";
    }
    //cout << endl;
}
void merge_sort(ll l, ll r){
    if(l >= r)return ;
    merge_sort(l,(l + r)/2);
    merge_sort((l + r)/2 + 1,r);
    merg(l,(l + r)/2,r);
}




ll p[MAXN];
ll ln[MAXN];
ll rn[MAXN];

ll vis[MAXN];
vector<ll> s;

ll lower(ll x){
	if(s.size() == 0) return 0;
	ll dw = -1;
	ll up = s.size();
	ll mid;
	while(dw + 1 < up){
		mid = (dw + up) / 2;
		if(s[mid] < x) dw = mid;
		else up = mid;
	}
	return dw + 1;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	ll cntn = 0, ans = 0;
	for(int i = 0; i < n; i++){
		cin >> p[i];
		if(p[i] == -1) cntn ++;
		else {
			a.pb(p[i]);
			vis[p[i]] = 1;
		}
		ln[i] = cntn;
	}
	
	ans = ((cntn * (cntn - 1)) % MOD) * pw(4, MOD - 2);
	ans %= MOD;
	debug(ans);
	if(a.size() == 0) a.pb(0);
	merge_sort(0, a.size() - 1);
	ans += cnt;
	ans %= MOD;
	
	for(int i = 1;i<=n;i++) if(vis[i] == 0) s.pb(i);
	if(s.size() > 0) sort(all(s));
	ll lw, pr;
	for(int i = 0;i<n; i++){
		if(s.size() == 0) continue;
		if(p[i] != -1){
			lw = lower(p[i]);
			if((ln[i] == cntn) or (ln[i] == 0)){
				if(ln[i] == cntn) ans += (s.size() - lw);
				else ans += lw;
				ans %= MOD;
				continue;
			}
			
			pr = (s.size() - lw) * (( ln[i] * pw( cntn, MOD - 2) ) % MOD);
			
			pr += (lw * ( ((cntn - ln[i]) * pw(cntn, MOD - 2) ) % MOD));
			
			pr %= MOD;
			pr %= MOD;
			ans += pr;
			
			ans %= MOD;
		}
	}
	
	cout << ans % MOD;
	return 0;
}


/*
5
-1 -1 5 -1 1
                                 ____              ,----..               ,----..
   ,---,                       ,'  , `.           /   /   \             /   /   \
  '  .' \                   ,-+-,.' _ |          /   .     :           /   .     :
 /  ;    '.              ,-+-. ;   , ||         .   /   ;.  \         .   /   ;.  \
:  :       \            ,--.'|'   |  ;|        .   ;   /  ` ;        .   ;   /  ` ;
:  |   /\   \          |   |  ,', |  ':        ;   |  ; \ ; |        ;   |  ; \ ; |
|  :  ' ;.   :         |   | /  | |  ||        |   :  | ; | '        |   :  | ; | '
|  |  ;/  \   \        '   | :  | :  |,        .   |  ' ' ' :        .   |  ' ' ' :
'  :  | \  \ ,'        ;   . |  ; |--'         '   ;  \; /  |        '   ;  \; /  |
|  |  '  '--'          |   : |  | ,             \   \  ',  /          \   \  ',  /
|  :  :                |   : '  |/               ;   :    /            ;   :    /
|  | ,'                ;   | |`-'                 \   \ .'              \   \ .'
`--''                  |   ;/                      `---`                 `---`
                       '---'

*/
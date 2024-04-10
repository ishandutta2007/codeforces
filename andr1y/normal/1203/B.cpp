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
#define N 10005
#define INF 101111111111111
using namespace std;
ll a[N], cnt[N], tu[N], tuc = 0;
main(){
    FAST;
    ll Q;
    cin >> Q;
    while(Q--){
    	ll n;
    	cin >> n;
    	memset(cnt, 0, sizeof(cnt));
    	tuc = 0;
    	for(ll i =0;i<n*4;i++){
    		cin >> a[i];
    		cnt[a[i]]++;
    	}
    	bool can = true;
    	for(ll i =0;i<=10000;i++){
    		if(cnt[i]%2 != 0){
    			can = false;
    			break;
    		}
    		while(cnt[i] > 0){
    			tu[tuc++] = i;
    			cnt[i]-=2;
    		}
    	}
    	if(!can){
    		cout << "NO" << endl;
    		continue;
    	}
    	sort(tu, tu+tuc);
    	map<ll, ll> tuo;
    	for(ll i = 0;i<tuc;i++) tuo[tu[i]]++;
    	for(ll p = 1;p<tuc;p++){
    		ll db = tu[0]*tu[p];
    		map<ll, ll> tux = tuo;
    		tux[tu[0]]--;
    		tux[tu[p]]--;
    		can = true;
    		while(!tux.empty()){
    			pll ks = *(tux.begin());
    			if(ks.y == 0){
    				tux.erase(tux.begin());
    				continue;
    			}
    			if(db%ks.x != 0){
    				can = false;
    				break;
    			}
    			tux[ks.x]--;
    			if(tux[db/ks.x] > 0){
    				tux[db/ks.x]--;
    			}else{
    				can = false;
    				break;
    			}
    		}
    		if(can){
    			break;
    		}
    	}
    	if(can){
    		cout << "YES" << endl;
    	}else{
    		cout << "NO" << endl;
    	}
    }
}
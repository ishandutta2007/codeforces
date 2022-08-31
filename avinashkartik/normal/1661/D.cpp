#include<bits/stdc++.h>

using namespace std;

#define  GODSPEED       ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(15);
#define  f              first
#define  s              second
#define  newl           cout<<"\n";
#define  pb             push_back
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" ";newl;
#define  deb1(a)        cout<<a<<"\n";
#define  deb2(a,b)      cout<<a<<" "<<b<<"\n";
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<"\n";
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
#define  uniq(a)        a.resize(unique(a.begin(), a.end()) - a.begin());
#define  all(a)         a.begin(),a.end()

typedef  long long             ll;
typedef  long double           ld;

const ll   N     =  3e5 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n, k, b[N], ct[N], sub[N];

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> b[i];
    
    ll cnt = 0, subt = 0;
    for (int i = n, j = n - k + 1; i >= 1; i--) {
        ll add = i - j + 1;
        ll ai = cnt * i - subt;
        cnt -= ct[j];
        subt -= sub[j];
        ct[j] += max(0ll, (b[i] - ai + add - 1) / add);
        sub[j] += max(0ll, (b[i] - ai + add - 1) / add) * (j - 1);
        cnt += ct[j] - ct[i];
        subt += sub[j] - sub[i];
        if (j > 1) j--;
    }
    
    deb1(accumulate(ct + 1, ct + n + 1, 0ll))
}

int main() {
	GODSPEED;
	int test = 1;
    // 	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}
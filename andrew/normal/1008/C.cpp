#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define m_p make_pair
#define all(x) x.begin(),x.end()

using namespace std;
typedef long long ll;

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    vector <pll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].fi;
        a[i].se = i + 1;
    }
    ll ans = 0;
    sort(all(a));
    reverse(all(a));
    ll j = 0;
    for(int i = 0; i < n, j < n; i++){
        while(j < n && a[i].fi == a[j].fi)j++;
        if(j == n)break;
        j++;
        ans++;
    }
    cout << ans << "\n";
    return 0;
}
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    ll n, k;
    cin >> n >> k;
    vector<ll> as(n);
    ll zs = 0;
    ll sum = 0;
    for(ll &a : as) {
        cin >> a;
        if(a == 0) {
            zs ++;
        }
        sum += a;
    }
    if(abs(sum) > k * zs) {
        cout << "-1";
        return 0;
    }
    ll res = 0;
    for(ll i = 0; i < n; i ++) {
        ll mnx = 0;
        ll mxx = 0;
        ll x = 0;
        ll csum = sum;
        ll lft = zs;
        for(ll j = 0; j <= i; j ++) {
            if(as[j]) {
                x += as[j];
            } else {
                lft --;
                ll cur = 0;
                if(csum >= lft * k) {
                    cur = lft*k - csum;
                } else if(csum <= - lft * k) {
                    cur = - csum - lft * k;
                } else {
                    cur = min(k,lft*k-csum);
                }
                csum += cur;
                x += cur;
            }
            mnx = min(mnx,x);
            mxx = max(mxx,x);
        }
        for(ll j = i + 1; j < n; j ++) {
            if(as[j]) {
                x += as[j];
            } else {
                lft --;
                ll cur = 0;
                if(csum >= lft * k) {
                    cur = lft*k - csum;
                } else if(csum <= - lft * k) {
                    cur = - csum - lft * k;
                } else {
                    cur = -(min(k,lft*k+csum));
                }
                csum += cur;
                x += cur;
            }
            mnx = min(mnx,x);
            mxx = max(mxx,x);
        }
        res = max(res,mxx-mnx+1);
    }
    for(ll i = 0; i < n; i ++) {
        ll mnx = 0;
        ll mxx = 0;
        ll x = 0;
        ll csum = sum;
        ll lft = zs;
        for(ll j = 0; j <= i; j ++) {
            if(as[j]) {
                x += as[j];
            } else {
                lft --;
                ll cur = 0;
                if(csum >= lft * k) {
                    cur = lft*k - csum;
                } else if(csum <= - lft * k) {
                    cur = - csum - lft * k;
                } else {
                    cur = -(min(k,lft*k+csum));
                }
                csum += cur;
                x += cur;
            }
            mnx = min(mnx,x);
            mxx = max(mxx,x);
        }
        for(ll j = i + 1; j < n; j ++) {
            if(as[j]) {
                x += as[j];
            } else {
                lft --;
                ll cur = 0;
                if(csum >= lft * k) {
                    cur = lft*k - csum;
                } else if(csum <= - lft * k) {
                    cur = - csum - lft * k;
                } else {
                    cur = min(k,lft*k-csum);
                }
                csum += cur;
                x += cur;
            }
            mnx = min(mnx,x);
            mxx = max(mxx,x);
        }
        res = max(res,mxx-mnx+1);
    }
    cout << res;
    return 0;
}
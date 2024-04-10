#include<iostream>
#include<vector>
using namespace std;
typedef long long int ll;
const ll MOD = 1e9+7;

ll mid;
ll s[200000];
ll bs(ll v, ll l, ll r){
    if(l==r) return l;
    if(l+1 == r){
        if(s[r] <= v) return r;
        return l;
    }
    mid = (l + r) / 2;
    if(s[mid] > v) return bs(v,l,mid);
    else return bs(v,mid,r);
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    ll n,q,att,ak = 0;
    ll ss = 0;
    cin >> n >> q;
    for(int i =0;i<n;i++) cin >> s[i];
    for(int i =0;i<n;i++) ss+=s[i];
    for(int i = 1;i<n;i++) s[i] += s[i-1];
    for(int i =0;i<q;i++){
        cin >> att;
        ak += att;
        if(ak >= ss){
            ak = 0;
            cout << n << endl;
        } else {
            if( ak < s[0]) cout << n << endl;
            else cout << n-bs(ak,0,n)-1 << endl;
        }
    }

    return 0;
}
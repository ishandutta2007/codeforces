#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)      (x).begin(),(x).end()
#define X           first
#define Y           second
#define sep         ' '
//#define endl        '\n'
#define SZ(x)       ll(x.size())

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int q , n;

int query(int l , int r){
    r--;
    cout << "? " << l << sep << r << endl;
    int cnt = 0;
    for(int i = l ; i <= r ; i++){
        int x;
        cin >> x;
        if(l <= x && x <= r){
            cnt++;
        }
    }
    return (cnt & 1);
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> q;
    while(q--){
        cin >> n;
        int l = 1 , r = n + 1;
        while(r - l > 1){
            int mid = l + r >> 1;
            if(query(l , mid))  r = mid;
            else l = mid;
        }
        cout << "! " << l << endl;
    }

    return 0;
}
/*

*/
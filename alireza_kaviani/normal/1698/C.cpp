#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)      (x).begin(),(x).end()
#define X           first
#define Y           second
#define sep         ' '
#define endl        '\n'
#define SZ(x)       ll(x.size())

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

ll q , n , A[MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> q;
    while(q--){
        cin >> n;
        for(int i = 0 ; i < n ; i++){
            cin >> A[i];
        }
        sort(A , A + n);
        vector<ll> vec;
        for(int i = 0 ; i < n ; i++){
            if(i >= 3 && A[i] == A[i - 3]){
                continue;
            }
            vec.push_back(A[i]);
        }
        if(SZ(vec) > 10){
            cout << "NO" << endl;
            continue;
        }
        n = SZ(vec);
        int flag = 1;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < i ; j++){
                for(int k = 0 ; k < j ; k++){
                    ll sum = vec[i] + vec[j] + vec[k];
                    int ind = lower_bound(all(vec) , sum) - vec.begin();
                    if(ind == SZ(vec) || vec[ind] != sum){
                        flag = 0;
                    }
                }
            }
        }
        if(flag){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }

    return 0;
}
/*

*/
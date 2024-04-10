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

int q , n , A[MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> q;
    while(q--){
        cin >> n;
        int cnt0 = 0;
        vector<int> vec;
        for(int i = 0 ; i < n ; i++){
            cin >> A[i];
            vec.push_back(A[i]);
        }
        while(cnt0 + SZ(vec) > 1){
            vector<int> v;
            for(int i = 1 ; i < SZ(vec) ; i++){
                v.push_back(vec[i] - vec[i - 1]);
            }
            if(cnt0 > 0){
                cnt0--;
                if(SZ(vec)){
                    v.push_back(vec[0]);
                }
            }
            sort(all(v));
            vec.clear();
            for(int i : v){
                if(i == 0){
                    cnt0++;
                }
                else{
                    vec.push_back(i);
                }
            }
        }
        cout << (SZ(vec) == 0 ? 0 : vec[0]) << endl;
    }

    return 0;
}
/*

*/
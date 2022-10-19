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

const ll MAXN = (1 << 21) + 20;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

ll n , A[MAXN] , B[MAXN] , C[MAXN];

void get(ll A[]){
    string s;
    cin >> s;
    for(int i = 0 ; i < (1 << n) ; i++){
        A[i] = (ll(s[i] - 48) << (__builtin_popcount(i) * 2));
    }
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < (1 << n) ; j++){
            if(j & (1 << i)){
                A[j] += A[j ^ (1 << i)];
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n;
    get(A);
    get(B);

    for(int i = 0 ; i < (1 << n) ; i++){
        C[i] = A[i] * B[i];
    }
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < (1 << n) ; j++){
            if(j & (1 << i)){
                C[j] -= C[j ^ (1 << i)];
            }
        }
    }
    for(int i = 0 ; i < (1 << n) ; i++){
        C[i] = (C[i] >> (__builtin_popcount(i) * 2));
        cout << (C[i] & 3);
    }


    return 0;
}
/*

*/
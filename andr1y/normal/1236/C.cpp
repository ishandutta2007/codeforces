#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define FAST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define M 1000000007
#define N 305
using namespace std;
ll a[N][N];
main(){
    FAST;
    ll n;
    cin >> n;
    ll next = 0;
    for(ll i = 0;i<n;i++){
        for(ll j = 0;j<n;j++){
            if(i%2 == 1){
                j = n-1-j;
            }
            a[j][i] = ++next;
            if(i%2 == 1){
                j = n-1-j;
            }
        }
    }
    for(ll i =0;i<n;i++){
        for(ll j =0;j<n;j++) cout << a[i][j] << " ";
        cout << endl;
    }
}
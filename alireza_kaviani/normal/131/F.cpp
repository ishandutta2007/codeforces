#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MAXN = 1e3 + 10;
ll n , m , T , ans , A[MAXN][MAXN] , B[MAXN][MAXN] , C[MAXN][MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> T;
    for(ll i = 1 ; i <= n ; i++){
        string s;
        cin >> s;
        for(ll j = 1 ; j <= m ; j++){
            A[i][j] = s[j - 1] - 48;
        }
    }

    for(ll i = 1 ; i <= n ; i++){
        for(ll j = 1 ; j <= m ; j++){
            if(A[i][j] == 1 && A[i - 1][j] == 1 && A[i + 1][j] == 1 && A[i][j + 1] == 1 && A[i][j - 1] == 1)    B[i][j] = 1;
        }
        partial_sum(B[i] , B[i] + MAXN , C[i]);
    }

    for(ll i = 1 ; i <= m ; i++){
        for(ll j = i + 2 ; j <= m ; j++){
            ll cnt = 0 , ind = 2;
            for(ll k = 1 ; k <= n ; k++){
                while(ind <= n && cnt < T){
                    cnt += C[ind][j - 1] - C[ind][i];
                    ind++;
                }
                ans += (n - ind + 1);
                cnt -= C[k + 1][j - 1] - C[k + 1][i];
            }
        }
    }
    cout << ans << endl;
}
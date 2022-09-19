#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const long MOD = (long)1e9 + 7;
ll const MAXN = 100001;

ll mins[30];
ll maxs[30];

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    ll d, sum;
    cin >> d >> sum;
    ll mi = 0;
    ll ma = 0;
    for(int i = 0; i < d; i++){
        cin >> mins[i] >> maxs[i];
        mi += mins[i];
        ma += maxs[i];
    }
    if((mi > sum) or (ma < sum)) cout << "NO";
    else{
        cout << "YES\n";
        for(int i = 0; i < d; i++){
            mi -= mins[i];
            ma -= maxs[i];
            for(int j = mins[i]; j <= maxs[i]; j++){
                if((mi <= sum - j) and (ma >= sum - j)){
                    cout << j << " ";
                    sum -= j;
                    break;
                }
            }
        }
    }

    return 0;
}
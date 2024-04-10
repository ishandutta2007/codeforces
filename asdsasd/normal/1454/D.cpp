#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void){
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll cnt = 1;
        ll num = n;
        ll nn = n;
        for(ll i = 2; i < sqrt(n) + 1; i++){
            if(nn % i == 0){
                ll tmp = 0;
                while(nn % i == 0){
                    nn /= i;
                    tmp++;
                }
                if(tmp > cnt){
                    cnt = tmp;
                    num = i;
                }
            }
        }
        cout << cnt << endl;
        for(ll i = 0; i < cnt - 1; i++){
            cout << num << " ";
            n /= num;
        }
        cout << n << endl;
    }
    return 0;
}
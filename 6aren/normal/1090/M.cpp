#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=1000000+5;
const int MOD=998244353;


int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, k, bef=0, af, cnt=0, maxi=0;
    cin >> n >> k;
    while (n--){
        cin >> af;
        if (af!=bef) cnt++;
        else cnt=1;
        maxi=max(cnt, maxi);
        bef=af;
    }
    cout << maxi;
    return 0;
}
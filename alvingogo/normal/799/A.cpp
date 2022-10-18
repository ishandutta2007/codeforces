#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
#define int long long
using namespace std;

signed main(){
    AquA;
    int n,t,k,d;
    cin >> n >> t >> k >> d;
    int old=t*((n-1)/k);
    if(d<old){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

long long dp[202000];

void solve(){
    int n;
    cin >> n;
    vector<long long> a_s(n);
    for(int i = 0; i < n; i++){
        cin >> a_s[i];
    }
    sort(a_s.begin(), a_s.end(), greater<int>());
    long long alice = 0;
    long long bob = 0;
    bool turn = true;
    for(auto a: a_s){
        if(turn){
            if(a % 2 == 0) alice += a;
            turn = false;
        }
        else{
            if(a % 2 == 1) bob += a;
            turn = true;
        }
    }
    if(alice > bob) cout << "Alice" << endl;
    else if(alice == bob) cout << "Tie" << endl;
    else cout << "Bob" << endl;
}

int main(void){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
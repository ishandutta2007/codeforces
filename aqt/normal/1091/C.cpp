#include <bits/stdc++.h>

using namespace std;

set<long long> ans;
int N;

int main(){
    cin >> N;
    for(long long i = 1; i<=sqrt(N); i++){
        if(N%i == 0){
            ans.insert(N/i*(N-i)/2+N/i);
            long long k = N/i;
            ans.insert(N/k*(N-k)/2+N/k);
        }
    }
    for(long long e : ans){
        cout << e << " ";
    }
}
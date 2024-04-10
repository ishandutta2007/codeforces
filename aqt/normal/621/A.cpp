#include <bits/stdc++.h>

using namespace std;

int N;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    long long maxi = LLONG_MAX, maxiodd1 = LLONG_MAX, sum = 0;
    for(int i = 1; i<=N; i++){
        long long n;
        cin >> n;
        sum += n;
        if(n%2 == 1){
            maxiodd1 = min(maxiodd1, n);
        }
    }
    if(sum%2 == 1){
        cout << sum - maxiodd1 << endl;
    }
    else{
        cout << sum << endl;
    }
}
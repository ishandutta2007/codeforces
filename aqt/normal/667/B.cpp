#include <bits/stdc++.h>

using namespace std;

int N;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    long long maxi = 0, sum = 0;
    for(int i = 1; i<=N; i++){
        long long n;
        cin >> n;
        sum += n;
        maxi = max(maxi, n);
    }
    sum -= maxi;
    maxi -= sum;
    cout << maxi+1 << endl;
}
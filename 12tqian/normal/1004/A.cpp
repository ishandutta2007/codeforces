#include <bits/stdc++.h>
using namespace std;
vector<long long> x;
int main(){
    long long n;
    long long d;
    cin >> n >> d;
    long long maxs = 0;
    long long mins = 1000000000;
    for(long long i = 0 ; i<n; i++){
        long long temp;
        cin >> temp;
        x.emplace_back(temp);
        mins = min(mins, temp);
        maxs = max(maxs, temp);
    }
    long long total = 2;
    for(long long i = 0; i<n-1; i++){
        long long a = x[i];
        long long b = x[i + 1];
        if(((double(a))+b)/2 -a >d){
            total += 2;
        }
        if(((double(a))+b)/2 -a ==d){
            total += 1;
        }
    }
    cout << total;
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<long long> v;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 0; i<N; i++){
        long long n;
        cin >> n;
        v.push_back(n);
    }
    sort(v.begin(), v.end());
    long long gcd = v[1]-v[0];
    for(int i= 1; i<N; i++){
        gcd = __gcd(gcd, v[i]-v[i-1]);
    }
    for(int i = 1; i<=M; i++){
        long long n;
        cin >> n;
        if(gcd%n == 0){
            cout << "YES" << endl;
            cout << v[0] << " " << i << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}
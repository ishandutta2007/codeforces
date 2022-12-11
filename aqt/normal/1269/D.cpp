#include <bits/stdc++.h>

using namespace std;

int N;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    long long b = 0, w = 0;
    for(int i = 1; i<=N; i++){
        int n;
        cin >> n;
        b += n/2, w += n/2;
        b += (n%2 && i%2) ? 1 : 0;
        w += (n%2 && 1-i%2) ? 1 : 0;
    }
    cout << min(b, w) << endl;
}
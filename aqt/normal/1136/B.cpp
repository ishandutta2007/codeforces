#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, K;
    cin >> N >> K;
    int D = 2*min(K-1, N-K) + max(K-1, N-K);
    cout << D + N+1 + N << endl;
}
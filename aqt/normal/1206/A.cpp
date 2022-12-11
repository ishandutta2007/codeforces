#include <bits/stdc++.h>

using namespace std;

int N;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    int maxA = 0, maxB = 0;
    for(int i = 1; i<=N; i++){
        int n;
        cin >> n;
        maxA = max(maxA, n);
    }
    cin >> N;
    for(int i = 1; i<=N; i++){
        int n;
        cin >> n;
        maxB = max(maxB, n);
    }
    cout << maxA << " " << maxB << endl;
}
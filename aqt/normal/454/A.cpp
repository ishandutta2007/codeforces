#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N;
    for(int r = 1; r<=N; r++){
        int n = min(r*2-1, (N-r+1)*2-1);
        for(int c = 1; c<=N/2-n/2; c++){
            cout << '*';
        }
        for(int c = 1; c<=n; c++){
            cout << 'D';
        }
        for(int c = 1; c<=N/2-n/2; c++){
            cout << '*';
        }
        cout << endl;
    }
}
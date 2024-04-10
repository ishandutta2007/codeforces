#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    while(true){
        int T = N;
        int S = 0;
        while(T){
            S += T%10;
            T/=10;
        }
        if(S%4 == 0){
            cout << N << endl;
            return 0;
        }
        else{
            N++;
        }
    }
}
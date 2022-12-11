#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, V;
    cin >> N >> V;
    int tot = 0;
    if(V >= N-1){
        cout << N-1 << endl;
    }
    else{
        int tot = V;
        N -= V;
        N--;
        for(int i = 2; N; i++){
            tot += i;
            N--;
        }
        cout << tot << endl;
    }
}
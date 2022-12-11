#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N;
    int neg = 0, pos = 0;
    for(int i = 1; i<=N; i++){
        int n;
        cin >> n;
        if(n < 0){
            neg++;
        }
        else if(n > 0){
            pos++;
        }
    }
    if((N+1)/2 <= pos){
        cout << 1 << endl;
    }
    else if((N+1)/2 <= neg){
        cout << -1 << endl;
    }
    else {
        cout << 0 << endl;
    }
}
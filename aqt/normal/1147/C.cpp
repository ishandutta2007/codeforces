#include <bits/stdc++.h>

using namespace std;

int main(){
    int cnt = 0;
    int N, mini = INT_MAX;
    cin >> N;
    for(int i= 1; i<=N; i++){
        int n;
        cin >> n;
        if(n < mini){
            mini = n;
            cnt = 0;
        }
        if(n == mini){
            cnt++;
        }
    }
    if(cnt <= N/2){
        cout << "Alice" << endl;
    }
    else{
        cout << "Bob" << endl;
    }
}
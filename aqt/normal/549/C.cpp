#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, K;
    cin >> N >> K;
    int cnt = 0;
    for(int i = 1; i<=N; i++){
        int n;
        cin >> n;
        cnt += n%2;
    }
    int X = N-K;
    if(!X){
        if(cnt%2){
            cout << "Stannis" << endl;
        }
        else{
            cout << "Daenerys" << endl;
        }
    }
    else{
        if(X/2 >= cnt){
            cout << "Daenerys" << endl;
        }
        else if((X)/2 >= N-cnt && K%2 == 1){
            cout << "Stannis" << endl;
        }
        else if((X)/2 >= N-cnt && K%2 == 0){
            cout << "Daenerys" << endl;
        }
        else if(X%2){
            cout << "Stannis" << endl;
        }
        else{
            cout << "Daenerys" << endl;
        }
    }
}
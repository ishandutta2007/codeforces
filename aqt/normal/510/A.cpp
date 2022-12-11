#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    for(int i = 0; i<N; i++){
        if(i%2){
            if(i%4 == 1){
                for(int i = 1; i<M; i++){
                    cout << '.';
                }
                cout << '#';
            }
            else{
                cout << '#';
                for(int i = 1; i<M; i++){
                    cout << '.';
                }
            }
        }
        else{
            for(int i = 1; i<=M; i++){
                cout << '#';
            }
        }
        cout << endl;
    }
}
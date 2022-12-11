#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N;
    if(N == 1){
        cout << 2 << endl;
        cout << 1 << " " << 1 << endl;
        return 0;
    }
    cout << N+(N)/2 << endl;
    for(int i = 2; i<=N; i+=2){
        printf("%d ", i);
    }
    for(int i = 1; i<=N; i+=2){
        printf("%d ", i);
    }
    for(int i = 2; i<=N; i+=2){
        printf("%d ", i);
    }
}
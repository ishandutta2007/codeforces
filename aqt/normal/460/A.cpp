#include <bits/stdc++.h>

using namespace std;

int N, M;

int main(){
    cin >> N >> M;
    int cnt = 0;
    for(int i = 1; N; i++){
        cnt++;
        N--;
        if(i%M == 0){
            N++;
        }
    }
    cout << cnt << endl;
}
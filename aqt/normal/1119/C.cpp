#include <bits/stdc++.h>

using namespace std;

int N, M;
int a[505][505], b[505][505];

int main(){
    cin >> N >> M;
    for(int i = 1; i<=N; i++){
        for(int j= 1; j<=M; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 1; i<=N; i++){
        for(int j= 1; j<=M; j++){
            cin >> b[i][j];
        }
    }
    bool works = 1;
    for(int i = 1; i<=N; i++){
        int sumA = 0, sumB = 0;
        for(int j = 1; j<=M; j++){
            sumA += a[i][j];
            sumB += b[i][j];
        }
        works &= (sumA%2 == sumB%2);
    }
    for(int j =1; j<=M; j++){
        int sumA = 0, sumB = 0;
        for(int i = 1; i<=N; i++){
            sumA += a[i][j];
            sumB += b[i][j];
        }
        works &= (sumA%2 == sumB%2);
    }
    if(works){
        cout << "YES" << endl;
    }
    else{
        cout << "no" << endl;
    }
}
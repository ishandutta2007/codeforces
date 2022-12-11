#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[25][25];
int perm[25];

bool chk(){
    for(int i = 1; i<=N; i++){
        int cnt = 0;
        for(int j = 1; j<=M; j++){
            cnt += (arr[i][j] != perm[j]);
        }
        if(cnt > 2){
            return 0;
        }
    }
    return 1;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=M; j++){
            cin >> arr[i][j];
        }
    }
    for(int i = 1; i<=M; i++){
        perm[i] = i;
    }
    if(chk()){
        cout << "YES" << endl;
        return 0;
    }
    for(int i = 1; i<=M; i++){
        for(int j = i+1; j<=M; j++){
            swap(perm[i], perm[j]);
            if(chk()){
                cout << "YES" << endl;
                return 0;
            }
            swap(perm[i], perm[j]);
        }
    }
    cout << "NO" << endl;
}
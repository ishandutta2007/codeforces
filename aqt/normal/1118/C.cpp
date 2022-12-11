#include <bits/stdc++.h>

using namespace std;

int fre[1001];
int arr[25][25];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin>> N;
    for(int i = 1; i<=N*N; i++){
        int n;
        cin >> n;
        fre[n]++;
    }
    if(N%2){
        queue<int> qu1, qu2;
        for(int f = 1; f<=1000; ){
            if(!fre[f]){
                f++;
            }
            else if(fre[f]%2 == 1){
                if(arr[(N+1)>>1][(N+1)>>1]){
                    cout << "no" << endl;
                    return 0;
                }
                arr[(N+1)>>1][(N+1)>>1] = f;
                fre[f]--;
            }
            else if(fre[f]%4 == 2){
                qu1.push(f);
                fre[f] -= 2;
            }
            else {
                qu2.push(f);
                fre[f] -= 4;
            }
        }
        for(int i = 1; i<(N+1)>>1; i++){
            if(qu1.empty()){
                qu1.push(qu2.front());
                qu1.push(qu2.front());
                qu2.pop();
            }
            arr[(N+1)>>1][i] = arr[(N+1)>>1][N-i+1] = qu1.front();
            qu1.pop();
        }
        for(int i = 1; i<(N+1)>>1; i++){
            if(qu1.empty()){
                qu1.push(qu2.front());
                qu1.push(qu2.front());
                qu2.pop();
            }
            arr[i][(N+1)>>1] = arr[N-i+1][(N+1)>>1] = qu1.front();
            qu1.pop();
        }
        if(qu1.size()){
            cout << "no" << endl;
            return 0;
        }
        for(int i = 1; i<(N+1)>>1; i++){
            for(int j = 1; j<(N+1)>>1; j++){
                arr[i][j] = arr[N-i+1][j] = arr[i][N-j+1] = arr[N-i+1][N-j+1] = qu2.front();
                qu2.pop();
            }
        }
    }
    else{
        queue<int> qu;
        for(int i = 1; i<=1000; ){
            if(fre[i] == 0){
                i++;
                continue;
            }
            if(fre[i]%4){
                cout << "no" << endl;
                return 0;
            }
            qu.push(i);
            fre[i]-=4;
        }
        for(int i = 1; i<=N/2; i++){
            for(int j =1; j<=N/2; j++){
                arr[i][j] = arr[N-i+1][N-j+1] = arr[N-i+1][j] = arr[i][N-j+1] = qu.front();
                qu.pop();
            }
        }
    }
    cout << "yes" << endl;
    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=N; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
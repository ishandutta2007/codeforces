#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[200005], when[200005];
int val[200005];

int main(){
    cin >> N;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
    }
    cin >> M;
    for(int i = 1; i<=M; i++){
        int c;
        cin >> c;
        if(c == 1){
            int p, v;
            cin >> p >> v;
            arr[p] = v;
            when[p] = i;
        }
        else{
            cin >> val[i];
        }
    }
    for(int i = M; i>=0; i--){
        val[i] = max(val[i], val[i+1]);
    }
    for(int i= 1; i<=N; i++){
        cout << max(arr[i], val[when[i]]) << " ";
    }
}
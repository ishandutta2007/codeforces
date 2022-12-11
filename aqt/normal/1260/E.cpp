#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[1<<18];
priority_queue<int, vector<int>, greater<int>> pq;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> M;
    N = 31 - __builtin_clz(M);
    int idx = 0;
    for(int i = 0; i<1<<N; i++){
        cin >> arr[i];
        if(arr[i] == -1){
            idx = i;
        }
    }
    for(int i = 0; i<=idx; i++){
        arr[i] = 0;
    }
    for(int i = idx; i<1<<N; i++){
        arr[i] = arr[i+1];
    }
    long long tot = 0;
    pq.push(arr[(1<<N)-2]);
    for(int crnt = (1<<N)-2; crnt>=0; ){
        //cout << crnt << endl;
        tot += pq.top();
        pq.pop();
        N--;
        int t = crnt - (1<<N);
        //cout << " " << t << " " << crnt << " " << N << endl;
        do{
            //cout << arr[crnt-1] << endl;
            pq.push(arr[--crnt]);
        }
        while(crnt > t);
    }
    cout << tot << endl;
}
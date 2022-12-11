#include <bits/stdc++.h>

using namespace std;

int N;
int arr[100005][2];

int main(){
    cin >> N;
    for(int i = 1; i<=2*N; i++){
        int n;
        cin >> n;
        if(arr[n][0]){
            arr[n][1] =i;
        }
        else{
            arr[n][0] = i;
        }
    }
    int p1 = 1, p2 = 1;
    long long tot = 0;
    for(int i= 1; i<=N; i++){
        tot += min(abs(p1-arr[i][0]) + abs(p2-arr[i][1]), abs(p1-arr[i][1]) + abs(p2-arr[i][0]));
        p1 = arr[i][0];
        p2 = arr[i][1];
    }
    cout << tot << endl;
}
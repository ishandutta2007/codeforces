#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[1005], nxt[1005];
int t[1005], l[1005], r[1005];

int main(){
    cin >> N >> M;
    for(int i =1 ; i<=N; i++){
        arr[i] = N-i+1;
        nxt[i] = i;
    }
    for(int i =1 ; i<=M; i++){
        cin >> t[i] >> l[i] >> r[i];
        if(t[i]){
            int n = r[i];
            for(int j=l[i]; j<=n; j++){
                n = max(nxt[j], n);
                arr[j] = arr[l[i]];
            }
            for(int j = l[i]; j<=n; j++){
                nxt[j] = n;
            }
        }
    }
    bool ans = 1;
    for(int i= 1; i<=M; i++){
        if(!t[i]){
            bool b = 0;
            for(int j = l[i]; j<r[i]; j++){
                if(arr[j+1] < arr[j]){
                    b = 1;
                }
            }
            ans &= b;
        }
    }
    if(!ans){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    for(int i =1; i<=N; i++){
        cout << arr[i] << " ";
    }
}
#include <bits/stdc++.h>

using namespace std;

int N, M, Q;
int arr[200005];
int l[200005], r[200005];
bool typ[200005];

int main(){
    cin >> N >> M >> Q;
    for(int i= 1; i<=N; i++){
        cin >> arr[i];
    }
    for(int i = 1; i<=M; i++){
        int c;
        cin >> c;
        typ[i] = (c==1);
        cin >> l[i] >> r[i];
    }
    while(Q--){
        int n;
        cin >> n;
        for(int i = M; i>0; i--){
            if(l[i] > n || r[i] < n){
                continue;
            }
            if(typ[i]){
                if(n == l[i]){
                    n = r[i];
                }
                else{
                    n--;
                }
            }
            else{
                int d = n - l[i];
                n = r[i] - d;
            }
        }
        cout << arr[n] << " ";
    }
}
#include <bits/stdc++.h>

using namespace std;

int Q, B = 700, N = 500000;
int sum[705][705];
int arr[500005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> Q;
    while(Q--){
        int t, x, y;
        cin >> t >> x >> y;
        if(t == 1){
            arr[x] += y;
            for(int b = 1; b<=B; b++){
                int blk = x%b;
                sum[b][blk]+=y;
            }
        }
        else{
            if(x <= B){
                cout << sum[x][y] << "\n";
            }
            else{
                int out = 0;
                for(int i = y; i<=N; i+=x){
                    out += arr[i];
                }
                cout << out << "\n";
            }
        }
    }
}
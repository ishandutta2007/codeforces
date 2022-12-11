#include <bits/stdc++.h>

using namespace std;

int N, M, K, X, R;
int arr[1000005];
int req[500005];
int amt[500005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M >> K >> X;
    R = N-K*M+M;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
    }
    for(int i = 1; i<=X; i++){
        int n;
        cin >> n;
        req[n]++;
    }
    int cnt = 500000;
    for(int i = 1; i<=500000; i++){
        if(!req[i]){
            cnt--;
        }
    }
    for(int l = 1, r = 0; r<=N; ){
        while(r < R){
            r++;
            amt[arr[r]]++;
            if(amt[arr[r]] == req[arr[r]]){
                cnt--;
            }
        }
        if(!cnt){
            fill(amt+1, amt+1+500000, 0);
            R -= M;
            cout << R << "\n";
            for(int i = l, c = 0; i<=r && c < R; i++){
                amt[arr[i]]++;
                if(amt[arr[i]] > req[arr[i]]){
                    cout << i << " ";
                    c++;
                }
            }
            return 0;
        }
        int T = r+M;
        while(r < T){
            r++;
            amt[arr[r]]++;
            if(amt[arr[r]] == req[arr[r]]){
                cnt--;
            }
        }
        T = l+M;
        while(l < T){
            amt[arr[l]]--;
            if(amt[arr[l]] == req[arr[l]]-1){
                cnt++;
            }
            l++;
        }
    }
    cout << -1 << endl;
}
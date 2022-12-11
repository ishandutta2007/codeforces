#include <bits/stdc++.h>

using namespace std;

int N;
long long K;
int arr[100005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> K;
    int l = 1, r = N;
    for(int i =1 ; i<=N; i++){
        cin >> arr[i];
    }
    sort(arr+1, arr+1+N);
    while(l <= N && arr[l+1] == arr[1]){
        l++;
    }
    while(r && arr[r-1] == arr[N]){
        r--;
    }
    if(l >= r){
        cout << 0 << "\n";
        return 0;
    }
    long long crntl = arr[1], crntr = arr[N];
    while(l < r && K){
        if(l <= N-r+1){
            if(1LL*(arr[l+1]-crntl)*l > K){
                crntl += K/l;
                break;
            }
            else{
                K -= 1LL*(arr[l+1]-crntl)*l;
                crntl = arr[l+1];
                while(l < r && arr[l+1] == crntl){
                    l++;
                }
            }
        }
        else{
            if(1LL*(crntr-arr[r-1])*(N-r+1) > K){
                crntr -= K/(N-r+1);
                break;
            }
            else{
                K -= 1LL*(crntr-arr[r-1])*(N-r+1);
                crntr = arr[r-1];
                while(l < r && arr[r-1] == crntr){
                    r--;
                }
            }
        }
    }
    cout << crntr-crntl << "\n";
}
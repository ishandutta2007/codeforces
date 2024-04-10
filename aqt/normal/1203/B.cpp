#include <bits/stdc++.h>

using namespace std;

int T;
int fre[10005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        N *= 4;
        int mini = INT_MAX, maxi = 0;
        fill(fre+1, fre+1+10000, 0);
        for(int i =1 ; i<=N; i++){
            int n;
            cin >> n;
            fre[n]++;
            mini = min(mini, n);
            maxi = max(maxi, n);
        }
        bool b = 1;
        for(int l = 1, r = 10000; l<=r; ){
            while(!fre[l] && l <= r){
                l++;
            }
            while(!fre[r] && l <= r){
                r--;
            }
            if(l > r){
                break;
            }
            if(fre[l]%2 == 1 || fre[r]%2 == 1){
                b = 0;
                break;
            }
            if(l * r != mini*maxi){
                b = 0;
                break;
            }
            if(l == r && fre[l]%4 != 0){
                b = 0;
                break;
            }
            if(l == r){
                fre[l] -= 4;
            }
            else{
                fre[l] -= 2;
                fre[r] -= 2;
            }
        }
        if(b){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}
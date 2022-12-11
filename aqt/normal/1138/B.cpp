#include <bits/stdc++.h>

using namespace std;

int N;
int fre[4], t[4];
int arr[5005];
string s;

int main(){
    cin >> N >> s;
    for(int i =1 ; i<=N; i++){
        if(s[i-1] == '1'){
            arr[i]++;
        }
    }
    cin >> s;
    for(int i =1 ; i<=N; i++){
        if(s[i-1] == '1'){
            arr[i]+=2;
        }
        fre[arr[i]]++;
    }
    for(int n = 0; n<=N/2; n++){
        for(int i = 0; i<=min(fre[3], N/2); i++){
            for(int k= 0; k<4; k++){
                t[k] = fre[k];
            }
            t[3] = i;
            if(n-i > t[1] || n-i < 0){
                continue;
            }
            t[1] = n-i;
            if(fre[3]-t[3] + t[2] < n || fre[3]-t[3] > n){
                continue;
            }
            t[2] = fre[2] - (n - fre[3]+t[3]);
            if(fre[0] < N/2-t[3]-t[1]-t[2] || t[3]+t[1]+t[2] > N/2){
                continue;
            }
            t[0] = N/2-t[3]-t[1]-t[2];
            for(int i = 1; i<=N; i++){
                if(t[arr[i]] > 0){
                    t[arr[i]]--;
                    cout << i << " ";
                }
            }
            return 0;
        }
    }
    cout << -1 << endl;
}
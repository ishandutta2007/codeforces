#include <bits/stdc++.h>

using namespace std;

int N;
int arr[1000005];
int fre[1<<22], lst[1<<22];
int R = (1<<21)-1;

void add(int n, int idx){
    if(fre[n] >= 2 || lst[n] == idx){
        return;
    }
    fre[n]++;
    lst[n] = idx;
    for(int b = 0; b<=20; b++){
        if((n>>b)&1){
            add(n^(1<<b), idx);
        }
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i =1; i<=N; i++){
        cin >> arr[i];
    }
    int ans = 0;
    for(int i = N; i; i--){
        bool can = 0;
        int crnt = 0;
        if(fre[0] >= 2){
            can = 1;
        }
        int rev = R ^ arr[i];
        for(int b = 20; b>=0; b--){
            if((rev>>b)&1){
                if(fre[crnt^(1<<b)] >= 2){
                    crnt ^= (1<<b);
                    can = 1;
                }
            }
        }
        if(can){
            ans = max(crnt|arr[i], ans);
        }
        add(arr[i], i);
    }
    cout << ans << "\n";
}
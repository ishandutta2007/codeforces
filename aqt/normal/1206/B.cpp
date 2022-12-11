#include <bits/stdc++.h>

using namespace std;

int N;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    long long cst = 0;
    int neg = 0;
    bool zero = 0;
    for(int i= 1; i<=N; i++){
        int n;
        cin >> n;
        if(!n){
            zero = 1;
        }
        if(n >= 0){
            cst += abs(1 - n);
        }
        else{
            cst += abs(-1 - n);
            neg++;
        }
    }
    if(neg&1 && !zero){
        cst += 2;
    }
    cout << cst << endl;
}
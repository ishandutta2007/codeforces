#include <bits/stdc++.h>

using namespace std;

int N;
long long lst, n;

int main(){
    cin >> N;
    long long tot = 0;
    for(int i =1 ; i<=N; i++){
        cin >> n;
        if(lst < n){
            tot += (n-lst)*(N-n+1);
        }
        else if(lst > n){
            tot += (lst-n)*(n);
        }
        lst = n;
    }
    cout << tot << endl;
}
#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N;
    long long ans = 0, n = 0;
    for(int i= 1; i<=N; i++){
        long long lst;
        cin >> lst;
        if(2*n > lst){
            ans += lst/2;
            n -= lst/2;
            lst = lst%2;
            n += lst;
        }
        else{
            ans += n;
            lst -= 2*n;
            ans += lst/3;
            n = lst%3;
        }
    }
    cout << ans << endl;
}
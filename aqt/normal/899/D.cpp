#include <bits/stdc++.h>

using namespace std;

int main(){
    long long N;
    cin >> N;
    if(N <= 4){
        cout << N*(N-1)/2 << endl;
        return 0;
    }
    long long a = 5, c = 4;
    int longest = 0;
    for(int i = 1; true; i++){
        if(a > N){
            break;
        }
        longest = i;
        a *= 10;
        c *= 10;
        c += 9;
    }
    long long ans = 0;
    for(int d = 0; d<=9; d++){
        long long tar = pow(10, longest)-1;
        tar += pow(10, longest)*d;
        long long mid = tar/2+1;
        ans += max(min(N - mid + 1, mid-1), 0LL);
    }
    cout << ans << endl;
}
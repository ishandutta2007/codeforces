#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        long long x = 0, s = 0;
        for(int i = 1; i<=N; i++){
            long long n;
            cin >> n;
            x ^= n;
            s += n;
        }
        long long num1 = 0, num2 = 0;
        num1 = x;
        s += x;
        x = 0;
        num2 = s;
        cout << 2 << "\n" << num1 << " " << num2 << "\n";
    }
}
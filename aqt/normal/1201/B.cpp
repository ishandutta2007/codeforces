#include <bits/stdc++.h>

using namespace std;

int N;
long long s, mx;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i= 1; i<=N; i++){
        long long n;
        cin >> n;
        mx = max(n, mx);
        s += n;
    }
    if(s&1 || mx > s/2){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
    }
}
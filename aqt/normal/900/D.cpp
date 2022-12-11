#include <bits/stdc++.h>

using namespace std;

int x, y;
vector<int> p;
long long MOD = 1e9+7;

long long mult(long long a, long long b){
    return (a*b)%MOD;
}

long long add(long long a, long long b){
    return (a+b)%MOD;
}

long long sub(long long a, long long b){
    a = add(a, -b);
    if(a < 0){
        a += MOD;
    }
    return a;
}

long long qikpow(long long b, long long e){
    if(!e){
        return 1;
    }
    long long mid = qikpow(b, e/2);
    mid = mult(mid, mid);
    if(e&1){
        mid = mult(mid, b);
    }
    return mid;
}

int main(){
    cin >> x >> y;
    if(y%x){
        cout << 0 << endl;
        return 0;
    }
    y /= x;
    int n = y;
    for(int i = 2; i<=sqrt(y); i++){
        if(n%i == 0){
            p.push_back(i);
            while(n%i == 0){
                n /= i;
            }
        }
    }
    if(n != 1){
        p.push_back(n);
    }
    int N = p.size();
    long long ans = 0;
    for(int b = 0; b<1<<N; b++){
        int k = 1;
        for(int n = 0; n<N; n++){
            if((b>>n)&1){
                k *= p[n];
            }
        }
        if(__builtin_popcount(b)%2){
            ans = sub(ans, qikpow(2, y/k-1));
        }
        else{
            ans = add(ans, qikpow(2, y/k-1));
        }
    }
    cout << ans << endl;
}
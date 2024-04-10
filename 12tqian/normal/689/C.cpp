#include <bits/stdc++.h>
using namespace std;
double A = 1.20;
static long long m;
long long compute(long long n){
    long long k = 2;
    long long ans = 0;
    while(true){
        long long x = floor(n / ((long long) (k*k*k)));
        ans += x;
        if(x == 0){
            break;
        }
        k += 1;
    }
    return ans;
}/*
long long compute(long long x){
    long long y = ceil(pow(x,1.0/3));
    long long  ans = 0;
    for(long long i = 2; i < y+1; ++i){
        ans += x/(i*i*i);
    }
    return ans;
}*/
long long bin(long long l, long long r){
    if(r>= l){
        long long mid = l + (r-l)/2;
        long long a = compute(mid);
        if(a == m){
            return mid;
        }
        if(a >m){
            return bin(l, mid - 1);
        }
        return bin(mid+1, r);
    }
    return -1;
}
long long mins(long long a, long long b){
    if(a>b){
        return a;
    }
    return b;
}
int main(){
    cin >> m;
    long long low = floor(m/A);
    long long temp = bin(1, 8*m);
    bool bad = false;
   /* if(compute(temp) != m){
        cout << -1;
        return 0;
    }
    while(!bad){
        temp--;
        if(compute(temp) != m){
            bad = true;
        }
    }
    cout<< temp + 1;*/
    for(long long i = mins(temp - 20, 0); i<= temp; i++){
        if(compute(i) == m){
            cout << i;
            return 0;
        }
    }
    cout << -1;
    return 0;
}
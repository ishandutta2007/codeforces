#include<iostream>
#include<algorithm>
#define DIM 200005
using namespace std;
int n, t, x, y, a, b, d, i, st, dr, mid;
long long k;
int v[DIM], s[DIM];
int cmmdc(int a, int b){
    int r;
    while(b != 0){
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int verif(int m){
    int i, u = n;
    for(i = 1; i <= m; i++){
        s[i] = 0;
    }
    long long sum = 0;
    for(i = d; i <= m; i += d){
        s[i] = 1;
        sum += (x + y) * 1LL * v[u];
        u--;
    }
    for(i = a; i <= m; i += a){
        if(s[i] == 1){
            continue;
        }
        s[i] = 1;
        sum += x * 1LL * v[u];
        u--;
    }
    for(i = b; i <= m; i += b){
        if(s[i] == 1){
            continue;
        }
        s[i] = 1;
        sum += y * 1LL * v[u];
        u--;
    }
    if(sum >= k){
        return 1;
    }
    return 0;
}
int main(){
    cin>> t;
    for(; t; t--){
        cin>> n;
        for(i = 1; i <= n; i++){
            cin>> v[i];
            v[i] /= 100;
            s[i] = 0;
        }
        cin>> x >> a;
        cin>> y >> b;
        if(x < y){
            swap(x, y);
            swap(a, b);
        }
        cin>> k;
        d = min(n + 1LL, a * 1LL * b / cmmdc(a, b) );
        st = 0;
        dr = n;
        sort(v + 1, v + n + 1);
        if(verif(n) == 0){
            cout<<"-1\n";
            continue;
        }
        while(st <= dr){
            mid = (st + dr) / 2;
            if(verif(mid)){
                dr = mid - 1;
            }
            else{
                st = mid + 1;
            }
        }
        cout<< st <<"\n";
    }
}
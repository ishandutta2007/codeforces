#include<iostream>
#include<set>
#define DIM 200005
#define mod 998244353
using namespace std;
int n, q, i, p, sol;
long long x, y;
int v[DIM], sum[DIM], prod[DIM];
set<int> s;
set<int> :: iterator it, it1, it2;
void ff(long long a, long long b, long long &x, long long &y){
    if(b == 0){
        x = 1;
        y = 0;
    }
    else{
        long long x2, y2;
        ff(b, a % b, x2, y2);
        x = y2;
        y = x2 - a / b * y2;
    }
}
int invmod(int a){
    ff(a, mod, x, y);
    x %= mod;
    if(x < 0){
        x += mod;
    }
    return x;
}
int solve(int p, int u){
    if(u == n){
        return sum[p];
    }
    return (sum[p] - sum[u + 1] + mod) * 1LL * invmod(prod[u + 1]) % mod;
}
int main(){
    cin>> n >> q;
    for(i = 1; i <= n; i++){
        cin>> v[i];
        v[i] = 100LL * invmod(v[i]) % mod;
    }
    prod[n + 1] = 1;
    for(i = n; i >= 1; i--){
        prod[i] = prod[i + 1] * 1LL * v[i] % mod;
        sum[i] = (sum[i + 1] + prod[i]) % mod;
    }
    sol = sum[1];
    s.insert(1);
    s.insert(n + 1);
    for(; q; q--){
        cin>> p;
        it = s.lower_bound(p);
        if(*it == p){
            it1 = it; it1--;
            it2 = it; it2++;
            sol = (sol * 1LL - solve(*it1, p - 1) - solve(p, *it2 - 1) + solve(*it1, *it2 - 1) + 2 * mod) % mod;
            s.erase(it);
        }
        else{
            it1 = it; it1--;
            it2 = it;
            sol = (sol * 1LL + solve(*it1, p - 1) + solve(p, *it2 - 1) - solve(*it1, *it2 - 1) + mod) % mod;
            s.insert(p);
        }
        cout<< sol <<"\n";
    }
}
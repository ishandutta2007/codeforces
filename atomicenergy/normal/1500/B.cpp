using namespace std;

#define visual

#ifdef visual
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <assert.h>
#include <functional>
#include <math.h>
#include <string>
#include <ctime>
#endif
#ifndef visual
#include <bits/stdc++.h>
#endif

typedef long long ll;

long long gcd(long long a, long long b){
    if(a == 0 || b == 0) return a + b;
    if(a < b) return gcd(b, a);
    return gcd(a%b, b);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    long long n, m, k;
    cin >> n >> m >> k;
    vector<int> v;

    long long g = gcd(m, n);
    long long ng = n/g;
    long long mg = m/g;

    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    map<long long, int> u;
    vector<int> w;
    for(int i=0; i<m; i++){
        int x;
        cin >> x;
        u[x] = i;
        w.push_back(x);
    }
    int tot = 0;
    for(int i=0; i<v.size(); i++){
        if(!u.count(v[i])) continue;
        if(i % g != u[v[i]] % g) continue;
        tot++;
    }
    long long ans = 0;
    while(k > (n * m/g - tot)){
                k--;
        ans += n*m/g*(k/(n*m/g - tot));
        k %= (n*m/g - tot);
        k++;
    }
    int i = 0;
    map<long long, long long> off;
    for(int k=0; k<n; k++){
        if(!u.count(v[k])) continue;
        if(k % g != u[v[k]] % g) continue;
        off[((u[v[k]] % m) - (k%m) + m)%m]++;
    }
    int j = 0;
    while(k > n){
        ans+=n;
        k-=n;
        k += off[j];

        j = (j + n)%m;
    }
    
    while(k > 0){
        ans++;
        if(v[i] != w[j]) k--;
        i = (i + 1) % n;
        j = (j + 1) % m;

    }
    cout << ans << endl;

    
    
    
    
}
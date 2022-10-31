#include<iostream>
#include<algorithm>
#include<set>
#define DIM 100005
using namespace std;
int n, i, poz, x;
long long sol;
int aib[2 * DIM], v[2 * DIM], w[DIM];
set<int> s[DIM];
set<int> :: iterator it;
void upd(int x){
    for(; x <= 2 * n; x += (x & -x)){
        aib[x]++;
    }
}
int query(int x){
    int sum = 0;
    for(; x >= 1; x -= (x & -x)){
        sum += aib[x];
    }
    return sum;
}
int main(){
    cin>> n;
    v[0] = 1000000;
    for(i = 1; i <= n; i++){
        cin>> v[i];
        w[i] = v[i + n] = v[i];
        s[ v[i] ].insert(i);
        s[ v[i] ].insert(i + n);
        if(v[i] < v[poz]){
            poz = i;
        }
    }
    sol = poz;
    s[ v[poz] ].erase(poz);
    s[ v[poz] ].erase(poz + n);
    upd(poz);
    upd(poz + n);
    sort(w + 1, w + n + 1);
    for(i = 2; i <= n; i++){
        it = s[ w[i] ].upper_bound(poz);
        x = *it;
        sol += x - poz - query(x) + query(poz);
        poz = x;
        if(poz > n){
            poz -= n;
        }
        s[ v[poz] ].erase(poz);
        s[ v[poz] ].erase(poz + n);
        upd(poz);
        upd(poz + n);
    }
    cout<< sol;
    return 0;
}
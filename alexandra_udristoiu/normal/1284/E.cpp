#include<iostream>
#include<algorithm>
#define x first
#define y second
using namespace std;
int n, i, j, u;
long long sol;
pair<int, int> v[2505], w[2505], pct;
long long comb(int n, int k){
    if(n < k){
        return 0;
    }
    long long sum = 1;
    int i;
    for(i = n; i > n - k; i--){
        sum *= i;
    }
    for(i = 1; i <= k; i++){
        sum /= i;
    }
    return sum;
}
long long det(pair<int, int> a, pair<int, int> b, pair<int, int> c){
    return (b.x - a.x) * 1LL * (c.y - a.y) - (c.x - a.x) * 1LL * (b.y - a.y);
}
int cadran(pair<int, int> a){
    if(a.x >= 0){
        if(a.y >= 0){
            return 0;
        }
        return 1;
    }
    else{
        if(a.y < 0){
            return 2;
        }
        return 3;
    }
}
int cmp(pair<int, int> a, pair<int, int> b){
    if(cadran(a) != cadran(b)){
        return cadran(a) < cadran(b);
    }
    return det(pct, a, b) < 0;
}
int ind(int u){
    if(u > n - 1){
        return u - n + 1;
    }
    return u;
}
int main(){
    cin>> n;
    for(i = 1; i <= n; i++){
        cin>> w[i].x >> w[i].y;
    }
    sol = comb(n, 5) * 5;
    pct = make_pair(0, 0);
    for(i = 1; i <= n; i++){
        for(j = 1; j < i; j++){
            v[j] = w[j];
        }
        for(j = i + 1; j <= n; j++){
            v[j - 1] = w[j];
        }
        for(j = 1; j < n; j++){
            v[j].x -= w[i].x;
            v[j].y -= w[i].y;
        }
        sort(v + 1, v + n, cmp);
        u = 1;
        for(j = 1; j < n; j++){
            while(u < j + n - 1 && det(pct, v[j], v[ ind(u) ]) <= 0){
                u++;
            }
            sol -= comb(u - j - 1, 3);
        }
    }
    cout<< sol;
}
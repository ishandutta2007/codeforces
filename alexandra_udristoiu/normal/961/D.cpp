#include<iostream>
#include<algorithm>
#define x first
#define y second
using namespace std;
int n, i, ii, st, dr;
pair<int, int> v[100005], p;
long long det(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3){
    return (p2.x - p1.x) * 1LL * (p3.y - p1.y) - (p3.x - p1.x) * 1LL * (p2.y - p1.y);
}
int cmp(pair<int, int> a, pair<int, int> b){
    return det(p, a, b) < 0;
}
int verif(int i, int j){
    if(st < i || dr > j){
        return 0;
    }
    if(i == 0 || j == n + 1){
        return 1;
    }
    if(i == 1 && j == n){
        return 1;
    }
    if(i >= 2 && j <= n - 1){
        if(det(v[1], v[2], v[n - 1]) == 0 && det(v[2], v[n - 1], v[n - 2]) == 0){
            return 1;
        }
        return 0;
    }
    if(i >= 2){
        if(det(v[1], v[2], v[n]) == 0){
            return 1;
        }
        return 0;
    }
    if(det(v[1], v[n - 1], v[n]) == 0){
        return 1;
    }
    return 0;
}
int main(){
    cin>> n;
    for(i = 1; i <= n; i++){
        cin>> v[i].x >> v[i].y;
    }
    ii = 1;
    for(i = 2; i <= n; i++){
        if(v[i] < v[ii]){
            ii = i;
        }
    }
    p = v[ii];
    for(i = ii; i < n; i++){
        v[i] = v[i + 1];
    }
    n--;
    if(n <= 3){
        cout<<"YES";
        return 0;
    }
    sort(v + 1, v + n + 1, cmp);
    st = n;
    for(i = 3; i <= n; i++){
        if(det(v[i - 2], v[i - 1], v[i]) != 0){
            st = i - 1;
            break;
        }
    }
    dr = 1;
    for(i = n - 2; i >= 1; i--){
        if(det(v[i + 2], v[i + 1], v[i]) != 0){
            dr = i + 1;
            break;
        }
    }
    ii = 1;
    for(i = 2; i <= n; i++){
        if(det(p, v[i - 1], v[i]) != 0){
            if(verif(ii - 1, i) ){
                cout<<"YES";
                return 0;
            }
            ii = i;
        }
    }
    if(verif(ii - 1, n + 1)){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
}
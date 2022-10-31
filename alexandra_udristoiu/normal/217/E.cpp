#include<iostream>
#include<vector>
#define DIM 3000005
using namespace std;
int n, k, i, p, m, p2, ii, j, nr;
int aib[DIM], nxt[DIM];
char s[DIM], sol[DIM];
vector<int> sv[5005], sw[5005];
pair<int, int> v[5005];
void update(int x, int val){
    for(; x <= k; x += (x & -x)){
        aib[x] += val;
    }
}
int query(int x){
    int p = 0, ii = 1, sum = 0;
    while(ii * 2 <= k){
        ii *= 2;
    }
    for(; ii; ii /= 2){
        if(p + ii <= k && sum + aib[p + ii] < x){
            sum += aib[p + ii];
            p += ii;
        }
    }
    return p + 1;
}
int main(){
    cin>> s + 1;
    cin>> k >> n;
    for(i = 1; i <= n; i++){
        cin>> v[i].first >> v[i].second;
    }
    for(i = 1; i <= k; i++){
        nxt[i] = i + 1;
        update(i, 1);
    }
    nr = k;
    nxt[k] = -1;
    for(i = n; i >= 1; i--){
        if(nr < v[i].second){
            continue;
        }
        p2 = query(v[i].second);
        p = nxt[p2];
        m = v[i].second - v[i].first + 1;
        while(m > 0 && p != -1){
            sv[i].push_back(p);
            nr--;
            update(p, -1);
            p = nxt[p];
            m--;
        }
        nxt[p2] = p;
        m = min(v[i].second - v[i].first + 1, 2 * (v[i].second - v[i].first + 1 - m) );
        p = query(v[i].first);
        while(m > 0){
            sw[i].push_back(p);
            m--;
            p = nxt[p];
        }
    }
    p = query(1);
    while(p != -1){
        sv[0].push_back(p);
        p = nxt[p];
    }
    for(i = 0; i < sv[0].size(); i++){
        sol[ sv[0][i] ] = s[i + 1];
    }
    for(i = 1; i <= n; i++){
        ii = 1;
        for(j = 0; j < sv[i].size(); j++){
            if(ii >= sw[i].size() ){
                ii = 0;
            }
            sol[ sv[i][j] ] = sol[ sw[i][ii] ];
            ii += 2;
        }
    }
    cout<< sol + 1;
}
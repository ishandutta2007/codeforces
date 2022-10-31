#include<iostream>
#include<algorithm>
#define x first
#define y second
#define DIM 200005
using namespace std;
int n, i, nr, p1, p2, j;
long long sol;
int aib[DIM], w[DIM], viz[DIM];
pair<int, int> v[DIM];
int cmp(pair<int, int> a, pair<int, int> b){
    if(a.y == b.y){
        return a.x < b.x;
    }
    return a.y > b.y;
}
int cautbin(int x){
    int st = 1, dr = nr, mid;
    while(st <= dr){
        mid = (st + dr) / 2;
        if(w[mid] == x){
            return mid;
        }
        if(w[mid] < x){
            st = mid + 1;
        }
        else{
            dr = mid - 1;
        }
    }
}
void update(int x){
    for(; x <= nr; x += (x & -x) ){
        aib[x]++;
    }
}
int query(int x){
    int sum = 0;
    for(; x >= 1; x -= (x & -x) ){
        sum += aib[x];
    }
    return sum;
}
int main(){
    cin>> n;
    for(i = 1; i <= n; i++){
        cin>> v[i].x >> v[i].y;
        w[i] = v[i].x;
    }
    sort(w + 1, w + n + 1);
    nr = 1;
    for(i = 2; i <= n; i++){
        if(w[i] != w[nr]){
            w[++nr] = w[i];
        }
    }
    for(i = 1; i <= n; i++){
        v[i].x = cautbin(v[i].x);
    }
    sort(v + 1, v + n + 1, cmp);
    for(i = 1; i <= n; i++){
        if(viz[ v[i].x ] == 0){
            viz[ v[i].x ] = 1;
            update(v[i].x);
        }
        j = i + 1;
        while(v[j].y == v[i].y){
             if(viz[ v[j].x ] == 0){
                viz[ v[j].x ] = 1;
                update(v[j].x);
            }
            j++;
        }
        p1 = query(v[i].x);
        p2 = query(nr) - p1 + 1;
        sol += p2 * 1LL * p1;
        while(v[i + 1].y == v[i].y){
            i++;
            p1 = query(v[i].x) - query(v[i - 1].x);
            p2 = query(nr) - query(v[i].x) + 1;
            sol += p2 * 1LL * p1;
        }
    }
    cout<< sol;
}
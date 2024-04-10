#include<iostream>
#include<algorithm>
#include<set>
#include<cstdio>
#define DIM 100005
using namespace std;
int n, i, ok;
struct str{
    int x, y, x2, y2;
};
str v[DIM];
struct event{
    int t, x, ind;
};
event w[2 * DIM];
set< pair<int, int> > sx, sy;
set< pair<int, int> > :: iterator it;
int cmp(event a, event b){
    if(a.x == b.x){
        return a.t < b.t;
    }
    return a.x < b.x;
}
void solve(){
    for(i = 1; i <= n; i++){
        w[2 * i - 1] = {0, v[i].x, i};
        w[2 * i] = {1, v[i].y, i};
    }
    sort(w + 1, w + 2 * n + 1, cmp);
    for(i = 1; i <= 2 * n; i++){
        if(w[i].t == 0){
            if(!sx.empty() ){
                it = sx.begin();
                if(-it->first > v[ w[i].ind ].y2){
                    ok = 0;
                    break;
                }
                it = sy.begin();
                if(it->first < v[ w[i].ind ].x2){
                    ok = 0;
                    break;
                }
            }
            sx.insert( make_pair(-v[ w[i].ind ].x2, w[i].ind) );
            sy.insert( make_pair(v[ w[i].ind ].y2, w[i].ind) );
        }
        else{
            sx.erase( make_pair(-v[ w[i].ind ].x2, w[i].ind) );
            sy.erase( make_pair(v[ w[i].ind ].y2, w[i].ind) );
        }
    }
}
int main(){
    cin>> n;
    for(i = 1; i <= n; i++){
        scanf("%d%d%d%d", &v[i].x, &v[i].y, &v[i].x2, &v[i].y2);
    }
    ok = 1;
    solve();
    if(ok == 1){
        for(i = 1; i <= n; i++){
            swap(v[i].x, v[i].x2);
            swap(v[i].y, v[i].y2);
        }
        solve();
        if(ok == 1){
            cout<<"YES";
        }
        else{
            cout<<"NO";
        }
    }
    else{
        cout<<"NO";
    }
}
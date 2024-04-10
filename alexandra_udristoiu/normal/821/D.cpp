#include<iostream>
#include<algorithm>
#include<set>
#define DIM 10005
#define f first
#define s second
using namespace std;
int n, m, k, i, nr, st, sol, p, u, nod, vecin;
int viz[DIM], d[DIM], c[DIM];
pair<int, int> v[DIM];
set< pair<int, int> > s[4];
set< pair<int, int> >::iterator it, it2;
struct str{
    int imin, jmin, imax, jmax;
};
str w[DIM];
int di[4] = {-1, 1, 0, 0};
int dj[4] = {0, 0, -1, 1};
int cautbin(int i, int j){
    int st = 1, dr = k, mid;
    while(st <= dr){
        mid = (st + dr) / 2;
        if(v[mid].f == i && v[mid].s == j){
            return mid;
        }
        else{
            if(v[mid].f < i || (v[mid].f == i && v[mid].s < j) ){
                st = mid + 1;
            }
            else{
                dr = mid - 1;
            }
        }
    }
    return -1;
}
void fill(int i, int j){
    for(int d = 0; d < 4; d++){
        int iv = i + di[d];
        int jv = j + dj[d];
        int x = cautbin(iv, jv);
        if(x != -1){
            if(viz[x] == 0){
                viz[x] = nr;
                w[nr].imin = min(w[nr].imin, iv);
                w[nr].imax = max(w[nr].imax, iv);
                w[nr].jmin = min(w[nr].jmin, jv);
                w[nr].jmax = max(w[nr].jmax, jv);
                fill(iv, jv);
            }
        }
    }
}
void add(int x){
    if(d[x] == 0){
        d[x] = d[nod] + 1;
        c[++u] = x;
    }
}
int main(){
    cin>> n >> m >> k;
    for(i = 1; i <= k; i++){
        cin>> v[i].f >> v[i].s;
    }
    sort(v + 1, v + k + 1);
    for(i = 1; i <= k; i++){
        if(viz[i] == 0){
            nr++;
            w[nr].imin = w[nr].imax = v[i].f;
            w[nr].jmin = w[nr].jmax = v[i].s;
            viz[i] = nr;
            fill(v[i].f, v[i].s);
        }
    }
    for(i = 1; i <= nr; i++){
        s[0].insert( make_pair(w[i].imin, i) );
        s[1].insert( make_pair(w[i].imax, i) );
        s[2].insert( make_pair(w[i].jmin, i) );
        s[3].insert( make_pair(w[i].jmax, i) );
    }
    d[1] = c[1] = p = u = 1;
    while(p <= u){
        nod = c[p];
        it = s[0].lower_bound( make_pair(w[nod].imin - 2, 0) );
        while(it != s[0].end()){
            if(it->f > w[nod].imax + 2){
                break;
            }
            add(it->s);
            it2 = it;
            it2++;
            s[0].erase(it);
            it = it2;
        }
        it = s[1].lower_bound( make_pair(w[nod].imin - 2, 0) );
        while(it != s[1].end()){
            if(it->f > w[nod].imax + 2){
                break;
            }
            add(it->s);
            it2 = it;
            it2++;
            s[1].erase(it);
            it = it2;
        }

        it = s[2].lower_bound( make_pair(w[nod].jmin - 2, 0) );
        while(it != s[2].end()){
            if(it->f > w[nod].jmax + 2){
                break;
            }
            add(it->s);
            it2 = it;
            it2++;
            s[2].erase(it);
            it = it2;
        }
        it = s[3].lower_bound( make_pair(w[nod].jmin - 2, 0) );
        while(it != s[3].end()){
            if(it->f > w[nod].jmax + 2){
                break;
            }
            add(it->s);
            it2 = it;
            it2++;
            s[3].erase(it);
            it = it2;
        }
        p++;
    }
    if(v[k].f == n && v[k].s == m){
        if(d[ viz[k] ] != 0){
            cout<< d[ viz[k] ] - 1;
        }
        else{
            cout<< -1;
        }
        return 0;
    }
    sol = 1000000;
    for(i = 1; i <= nr; i++){
        if(w[i].imax >= n - 1 || w[i].jmax >= m - 1){
            if(d[i] != 0){
                sol = min(sol, d[i]);
            }
        }
    }
    if(sol == 1000000){
        cout<< -1;
    }
    else{
        cout<< sol;
    }
    return 0;
}
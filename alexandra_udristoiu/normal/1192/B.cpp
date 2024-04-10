#include<iostream>
#include<vector>
#include<set>
#define DIM 100005
#define f first
#define s second
using namespace std;
//ifstream cin("date.in");
//ofstream cout("date.out");
int n, q, i, x, nr, j, srs, nod;
long long c, ww, sol, val[DIM], maxim;
int viz[DIM], num[DIM];
multiset<long long> s[DIM];
multiset<long long> :: iterator it;
vector< pair<int, int> > v[DIM];
vector< pair<long long, long long> > aint[DIM];
struct str{
    int x, y;
    long long c;
};
str vm[DIM];
struct str2{
    int ind, mch, tt, p, u, p2, u2;
};
vector<str2> w[DIM];
str2 curr;
void update(int ind, int nod, int st, int dr, int p, int u, long long val){
    if(p <= st && dr <= u){
        aint[ind][nod].s += val;
    }
    else{
        int mid = (st + dr) / 2;
        aint[ind][2 * nod].s += aint[ind][nod].s;
        aint[ind][2 * nod + 1].s += aint[ind][nod].s;
        aint[ind][nod].s = 0;
        if(p <= mid){
            update(ind, 2 * nod, st, mid, p, u, val);
        }
        if(u > mid){
            update(ind, 2 * nod + 1, mid + 1, dr, p, u, val);
        }
        aint[ind][nod].f = max(aint[ind][2 * nod].f + aint[ind][2 * nod].s, aint[ind][2 * nod + 1].f + aint[ind][2 * nod + 1].s);
    }
}
long long query(int ind, int nod, int st, int dr, int p, int u){
    if(p <= st && dr <= u){
        return aint[ind][nod].f + aint[ind][nod].s;
    }
    else{
        int mid = (st + dr) / 2;
        aint[ind][2 * nod].s += aint[ind][nod].s;
        aint[ind][2 * nod + 1].s += aint[ind][nod].s;
        aint[ind][nod].s = 0;
        long long x = 0, y = 0;
        if(p <= mid){
            x = query(ind, 2 * nod, st, mid, p, u);
        }
        if(u > mid){
            y = query(ind, 2 * nod + 1, mid + 1, dr, p, u);
        }
        aint[ind][nod].f = max(aint[ind][2 * nod].f + aint[ind][2 * nod].s, aint[ind][2 * nod + 1].f + aint[ind][2 * nod + 1].s);
        return max(x, y);
    }
}
void dfs(int nod, int t){
    num[nod] = 1;
    for(int i = 0; i < v[nod].size(); i++){
        int vecin = v[nod][i].f;
        if(viz[vecin] == 0 && vecin != t){
            dfs(vecin, nod);
            num[nod] += num[vecin];
        }
    }
}
int findcen(int nod, int n, int t){
    for(int i = 0; i < v[nod].size(); i++){
        int vecin = v[nod][i].f;
        if(viz[vecin] == 0 && vecin != t && num[vecin] > n / 2){
            return findcen(vecin, n, nod);
        }
    }
    return nod;
}
void upd(int nod, int mch, int srs, int t, long long dist, int ind, int p){
    w[nod].push_back( {ind, mch, srs, nr + 1, nr + num[nod], p, p + num[srs] - 1} );
    nr++;
    maxim = max(maxim, dist);
    update(ind, 1, 1, num[ind] - 1, nr, nr, dist);
    for(int i = 0; i < v[nod].size(); i++){
        int vecin = v[nod][i].f;
        if(viz[vecin] == 0 && vecin != t){
            upd(vecin, v[nod][i].s, srs, nod, dist + vm[ v[nod][i].s ].c, ind, p);
        }
    }
}
void decomp(int nod){
    dfs(nod, 0);
    int x = findcen(nod, num[nod], 0);
    viz[x] = 1;
    aint[x].resize(4 * num[nod] + 2);
    nr = 0;
    maxim = 0;
    dfs(x, 0);
    for(int i = 0; i < v[x].size(); i++){
        if(viz[ v[x][i].f ] == 0){
            maxim = 0;
            upd(v[x][i].f, v[x][i].s, v[x][i].f, 0, vm[ v[x][i].s ].c, x, nr + 1);
            s[x].insert(-maxim);
        }
    }
    if(s[x].size() >= 1){
        it = s[x].begin();
        if(s[x].size() == 1){
            val[x] = *it;
        }
        else{
            val[x] = *it;
            it++;
            val[x] += *it;
        }
    }
    s[0].insert(val[x]);
    for(int i = 0; i < v[x].size(); i++){
        if(viz[ v[x][i].f ] == 0){
            decomp(v[x][i].f);
        }
    }
}
int main(){
    cin>> n >> q >> ww;
    for(i = 1; i < n; i++){
        cin>> vm[i].x >> vm[i].y >> vm[i].c;
        v[ vm[i].x ].push_back( make_pair(vm[i].y, i) );
        v[ vm[i].y ].push_back( make_pair(vm[i].x, i) );
    }
    decomp(1);
    for(; q; q--){
        cin>> x >> c;
        x = (x + sol) % (n - 1) + 1;
        c = (c + sol) % ww;
        c -= vm[x].c;
        nod = vm[x].x;
        for(int ii = 0; ii < 2; ii++){
            if(ii == 1){
                nod = vm[x].y;
            }
            for(i = w[nod].size() - 1; i >= 0; i--){
                curr = w[nod][i];
                srs = curr.ind;
                if(curr.mch != x){
                    continue;
                }
                s[0].erase( s[0].lower_bound(val[srs]) );
                s[ srs ].erase( s[srs].lower_bound(- query(srs, 1, 1, num[srs] - 1, curr.p2, curr.u2) ) );
                update(srs, 1, 1, num[srs] - 1, curr.p, curr.u, c);
                s[srs].insert( - query(srs, 1, 1, num[srs] - 1, curr.p2, curr.u2) );
                it = s[srs].begin();
                val[srs] = *it;
                if(s[srs].size() > 1){
                    it++;
                    val[srs] += *it;
                }
                s[0].insert(val[srs]);
            }
        }
        vm[x].c += c;
        it = s[0].begin();
        sol = - *it;
        cout<< sol <<"\n";
    }
}
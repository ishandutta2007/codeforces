#include<iostream>
#include<vector>
#include<algorithm>
#define f first
#define s second
#define DIM 500005
#define ll long long
using namespace std;
int n, i, x, y, r;
int num[DIM];
long long d[DIM], sol;
pair<ll, ll> p[DIM];
vector<int> v[DIM];
ll det(pair<ll, ll> p1, pair<ll, ll> p2, pair<ll, ll> p3){
    return (p2.f - p1.f) * (p3.s - p1.s) - (p3.f - p1.f) * (p2.s - p1.s);
}
int cmp(pair<ll, ll> a, pair<ll, ll> b){
    if(a.f == b.f){
        return a.s > b.s;
    }
    return a.f > b.f;
}
void dfs(int nod, int tt){
    num[nod] = 1;
    int i, vecin, st, dr, nr = 0;
    for(i = 0; i < v[nod].size(); i++){
        vecin = v[nod][i];
        if(vecin == tt){
            continue;
        }
        dfs(vecin, nod);
        num[nod] += num[vecin];
    }
    d[nod] = num[nod] * 1LL * num[nod];
    for(i = 0; i < v[nod].size(); i++){
        vecin = v[nod][i];
        if(vecin == tt){
            continue;
        }
        d[nod] = min(d[nod], d[vecin] + (num[nod] - num[vecin]) * 1LL * (num[nod] - num[vecin]) );
        p[++nr].f = num[vecin];
        p[nr].s = d[vecin] + num[vecin] * 1LL * num[vecin] - 2LL * num[vecin] * n;
    }
    sort(p + 1, p + nr + 1, cmp);
    st = dr = 1;
    for(i = 2; i <= nr; i++){
        while(st < dr && p[st].s + p[st].f * 2 * p[i].f > p[st + 1].s + p[st + 1].f * 2 * p[i].f){
            st++;
        }
        sol = min(sol, p[st].s + p[i].s + 2 * p[st].f * p[i].f + n * 1LL * n);
        while(st <= dr && p[dr].f == p[i].f){
            dr--;
        }
        while(st < dr && det(p[dr - 1], p[dr], p[i]) >= 0){
            dr--;
        }
        p[++dr] = p[i];
    }
}
int main(){
    cin>> n;
    for(i = 1; i < n; i++){
        cin>> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    if(n == 2){
        cout<< 2;
        return 0;
    }
    for(i = 1; i <= n; i++){
        if(v[i].size() >= 2){
            r = i;
            break;
        }
    }
    sol = 1000000000000LL;
    dfs(r, 0);
    cout<< n * 1LL * (n - 1) - (sol - n) / 2;
}
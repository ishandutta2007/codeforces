#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<cstdio>
#define DIM 100005
#define f first
#define s second
using namespace std;
int n, i, x, y, cen, j, m;
long long nr;
int t[DIM], num[DIM], viz[DIM], nr1[DIM], nr2[DIM], sol[DIM], u[DIM], w2[DIM];
pair<int, int> w[DIM];
vector<int> v[DIM], p1[DIM], p2[DIM];
set< pair<int, int> > s;
set< pair<int, int> > :: iterator it;
void dfs(int nod, int t){
    num[nod] = 1;
    for(int i = 0; i < v[nod].size(); i++){
        int vecin = v[nod][i];
        if(vecin != t){
            dfs(vecin, nod);
            num[nod] += num[vecin];
        }
    }
}
void dfs2(int nod, int t, int i){
    p1[i].push_back(nod);
    p2[i].push_back(nod);
    for(int j = 0; j < v[nod].size(); j++){
        if(v[nod][j] != t){
            dfs2(v[nod][j], nod, i);
        }
    }
}
int getpoz1(int x){
    int val = p1[x][ p1[x].size() - 1 ];
    p1[x].pop_back();
    return val;
}
int getpoz2(int x){
    int val = p2[x][ p2[x].size() - 1 ];
    p2[x].pop_back();
    return val;
}
int findcen(int nod){
    viz[nod] = 1;
    for(int i = 0; i < v[nod].size(); i++){
        int vecin = v[nod][i];
        if(num[vecin] > n / 2 && viz[vecin] == 0){
            return findcen(vecin);
        }
    }
    return nod;
}
int main(){
    cin>> n;
    for(i = 1; i < n; i++){
        scanf("%d%d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1, 0);
    for(i = 1; i <= n; i++){
        for(j = 0; j < v[i].size(); j++){
            x = v[i][j];
            if(num[x] < num[i]){
                nr += min(num[x], n - num[x]);
            }
        }
    }
    nr *= 2;
    if(n == 2){
        cout<< nr <<"\n2 1";
        return 0;
    }
    cen = findcen(1);
    dfs(cen, 0);
    m = v[cen].size();
    y = 0;
    for(i = 0; i < v[cen].size(); i++){
        x = v[cen][i];
        dfs2(x, cen, i + 1);
        nr1[i + 1] = nr2[i + 1] = num[x];
        s.insert( make_pair(-num[x], i + 1) );
        for(j = 1; j <= num[x]; j++){
            w[++y] = make_pair(j, i + 1);
        }
    }
    w[++y] = make_pair(1, m + 1);
    p1[m + 1].push_back(cen);
    p2[m + 1].push_back(cen);
    for(i = 1; i <= n; i++){
        w[i].s *= -1;
    }
    sort(w + 1, w + n + 1);
    for(i = 1; i <= n; i++){
        u[i] = n;
        w2[i] = -w[i].s;
    }
    for(i = 1; i <= n; i++){
        w[i].s *= -1;
    }
    sort(w + 1, w + n + 1);
    for(i = n; i >= 1; i--){
        u[ w[i].s ] = min(i, u[ w[i].s ]);
        while(w2[ u[ w[i].s ] ] == w[i].s){
            u[ w[i].s ]--;
        }
        swap(w2[i], w2[ u[ w[i].s ] ]);
        sol[ getpoz1(w[i].s) ] = getpoz2(w2[i]);
    }
    cout<< nr <<"\n";
    for(i = 1; i <= n; i++){
        printf("%d ", sol[i]);
    }
}
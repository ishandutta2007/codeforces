#include<iostream>
#include<stack>
#include<queue>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<string>
#include<cstring>
#include<map>
#include<numeric>
#include<sstream>
#include<cmath>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define pb push_back
#define f(i,x,y) for(int i = x; i<y; i++ )
#define FORV(it,A) for(vector<int>::iterator it = A.begin(); it!= A.end(); it++)
#define FORS(it,A) for(set<int>::iterator it = A.begin(); it!= A.end(); it++)
#define quad(x) (x) * (x)
#define mp make_pair
#define clr(x, y) memset(x, y, sizeof x)
#define fst first
#define snd second
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
#define inf 100000000
#define N 2000000

int lcp[N];
int n;
struct no{
    int id;
    int tp;
    string s;
    bool operator < (const no &e) const{
        return s < e.s;
    }
};

struct seg{
    int esq[N], dir[N], mn[N];
    void build (int i, int e, int d){
        esq[i] = e, dir[i] = d;
        if (e == d){
            mn[i] = lcp[e];
        }
        else{
            int m = (e+d)/2;
            build(2*i, e, m); build(2*i+1, m+1, d);
            mn[i] = min(mn[2*i], mn[2*i+1]);
        }
    }
    int query (int i, int e, int d){
        if (esq[i] > d || e > dir[i]) return inf;
        if (esq[i] >= e && dir[i] <= d) return mn[i];
        return min(query(2*i, e, d), query(2*i+1, e, d));
    }
};


seg tree;
set <int> S;
int valor[N];
multiset <pii> V;
no v[N];
int r[N];
int onde[N];



int calc (int i, int j){
    if (i > j) swap(i, j);
    return tree.query(1, i, j-1);
}

void update (int i){
    set <int> :: iterator it = S.lower_bound(i);
    int x = 0;
    if (it == S.end()) return;
    set <int> :: iterator it2 = it;
    int lugar = 0;
    if (it != S.begin()){
        it2--;
        if (v[*it].tp != v[*it2].tp) {
            int y = calc(*it, *it2);
            if (x < y) x = y, lugar = 0;
        }
    }

    it2 = it; it2++;
    if (it2 != S.end()){
        if (v[*it].tp != v[*it2].tp){ 
            int y = calc(*it, *it2);
            if (x < y) x = y, lugar = 1;
        }
    }
    V.erase(V.find(pii(valor[i], i)));
    V.insert(pii(x,i));
    valor[i] = x;
    onde[i] = lugar;
}


int pref (int i, int j){
    int lim = min(v[i].s.size(), v[j].s.size());
    f (k, 0, lim){
        if (v[i].s[k] != v[j].s[k]) return k;
    }
    return lim;
}


void pre(){
    f (i, 0, 2*n-1){
        lcp[i] = pref(i, i+1);
    }
    tree.build (1, 0, 2*n-2);
}


int match[N];

bool acabou = 0;

int go (){
    multiset <pii> :: iterator it = V.end(); it--;
    int ans = it->fst;
    if (ans == 0){
        acabou = 1; return 0;
    }
    int i = it->snd;
    set <int> :: iterator it2 = S.lower_bound(i);
    if (onde[i]) it2++;
    else it2--;
//  printf("estamos ok i = %d valor[i] = %d\n", i, valor[i]);
    int i2 = (*it2);
//  printf("i =%d i2 = %d\n", i, i2);

    match[i] = i2; match[i2] = i;
    V.erase(V.find(pii(valor[i], i)));
//  printf("estamos ok\n");
    V.erase(V.find(pii(valor[i2], i2)));
    S.erase(S.find(i)); S.erase(S.find(i2));
    it2 = S.lower_bound(i);
    if (it2 != S.end()){
        update (*it2);
    }
    if (it2 != S.begin()){
        it2--;
        update(*it2);
    }
    return ans;
}


int main (){
    cin >> n;
    f (i, 0, 2*n) {
        cin >> v[i].s; v[i].id = i;
        v[i].tp = 0; if (i >= n) v[i].tp = 1;
    }
    sort (v, v+2*n);
    f (i, 0, 2*n) S.insert(i), V.insert(pii(0, i));
    pre();
    f (i, 0, 2*n) update (i);
    clr (match, -1);
    int ans = 0;
    while (S.size() > 0){
        ans += go();
        if (acabou) break;
//      printf("ans = %d\n", ans);
    }
    queue <int> Q;
    f (i, 0, 2*n) if (v[i].tp == 1 && match[i] == -1) Q.push(i);
    cout << ans << endl;
    f (i, 0, 2*n) if (v[i].tp == 0){
        if (match[i] == -1){
            int id = Q.front(); Q.pop();
            printf("%d %d\n", v[i].id+1, v[id].id+1-n);
        }
        else printf("%d %d\n", v[i].id+1, v[match[i]].id+1-n);
    }
    return 0;
}
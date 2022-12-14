#include <bits/stdc++.h>
# define md ((l + r) >> 1)
# define lc (id << 1)
# define rc (lc ^ 1)
using namespace std;

const int N = 2e5 + 77 , inf = 1e9;
int n , sa , sb , a[N] , b[N] , c[N];
int dist[N];
pair < int , int > mx[N << 2][2];


void combine(int id) {
    mx[id][0] = max(mx[lc][0] , mx[rc][0]);
    mx[id][1] = max(mx[lc][1] , mx[rc][1]);
}
void change(int x , int l = 1 , int r = n + 1 , int id = 1) {
    if(r - l < 2) {
        mx[id][0] = mx[id][1] = make_pair(-inf , -1);
        return ;
    }
    if(x < md) change(x , l , md , lc);
    else change(x , md , r , rc);
    combine(id);
}

void build(int l = 1 , int r = n + 1 , int id = 1) {
    if(r - l < 2) {
        mx[id][0] = make_pair(b[l] , l);
        mx[id][1] = make_pair(c[l] , l);
        return ;
    }
    build(l , md , lc);
    build(md , r , rc);
    combine(id);
}

pair < int , int > get(int ql , int qr , int f , int l = 1 , int r = n + 1 , int id = 1) {
    if(qr <= l || r <= ql) return make_pair(-inf , -1);
    if(ql <= l && r <= qr)
        return mx[id][f];
    return max(get(ql , qr , f , l , md , lc) , get(ql , qr , f , md , r , rc));
}

void test() {
    scanf("%d %d %d" , & n , & sa , & sb);
    for(int i = 1;i <= n;++ i) {
        scanf("%d" , a + i);
        dist[i] = inf;
        b[i] = a[i] - i;
        c[i] = a[i] + i;
    }
    dist[sa] = 0;
    build();
    //return ;
    queue < int > que;
    que.push(sa);
    change(sa);
    while(!que.empty()) {
        int v = que.front();
        que.pop();
        int ll = max(1 , v - a[v]);
        int rr = min(n + 1 , v + a[v] + 1);
        while(1) {
            auto x = get(v + 1 , rr , 0);
            int id = x.second;
            if(id <= 0) break ;
            if(id - v <= min(a[id] , a[v])) {
                dist[id] = dist[v] + 1;
                que.push(id);
                change(id);
            } else break ;
        }
        while(1) {
            auto x = get(ll , v , 1);
            int id = x.second;
            if(id <= 0) break ;
            if(v - id <= min(a[id] , a[v])) {
                dist[id] = dist[v] + 1;
                que.push(id);
                change(id);
            } else break ;
        }
    }

    printf("%d\n" , dist[sb]);

}

int main() {

    int tst = 1;
    scanf("%d" , & tst);
    while(tst --)
        test();
    return 0;
}
/*
1
10 2 9
4 1 1 1 5 1 1 1 1 5
*/
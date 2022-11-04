#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#define M 2000010

using namespace std;

struct Vec {
    vector <int> V;
    Vec() {V.clear();}
} vec[1000010];

map <vector <int>, int> hsh;

map <int, int> HH;

int Pr[100010], t = 0, notp[1000010], sym[1000010], Ans[333][333], Dis[555555], val[1000010], hshcnt = 0, nwcnt = 0;

int Head[M], Next[M], Go[M], Cnt = 0, hhcnt = 0;

void addedge(int x, int y) {
    Go[++Cnt] = y;
    Next[Cnt] = Head[x];
    Head[x] = Cnt;
}

int calc(vector <int> V) {
    int ans = 1;
    for(int i = 0; i < V.size(); i++) ans = ans * (V[i] + 1);
    return ans;
}

int vv[M];

int Search(Vec nw, int dep = 0) {
    int x;
    if(!hsh.count(nw.V)) {val[++hshcnt] = calc(nw.V), hsh[nw.V] = (x = hshcnt), vv[hshcnt] = 1;//
    }else {
        x = hsh[nw.V];
        if(vv[x]) return x;
        vv[x] = 1;
    }
    nw.V.push_back(0);
    if(dep <= 25) for(int i = 0; i < nw.V.size(); i++) if(!i || nw.V[i] != nw.V[i - 1]) {
        Vec G = nw;
        G.V[i]++;
        while(!G.V.empty() && G.V.back() == 0) G.V.pop_back();
        int y = Search(G, dep + 1);
        addedge(x * 2 - 1, y * 2 - 1);
        addedge(y * 2 - 1, x * 2 - 1);
        addedge(x * 2, y * 2);
        addedge(y * 2, x * 2);
    }
    return x;
}

int main() {
    for(int i = 2; i <= 1000000; i++) {
        if(!notp[i]) Pr[++t] = i, vec[i].V.push_back(1);
        for(int j = 1; Pr[j] * i <= 1000000; j++) {
            vec[i * Pr[j]] = vec[i];
            notp[i * Pr[j]] = 1;
            if(i % Pr[j] == 0) {
                vec[i * Pr[j]].V.back()++;
                break;
            } else vec[i * Pr[j]].V.push_back(1);
        }
    }
    for(int i = 1; i <= 1000000; i++) {
        sort(vec[i].V.begin(), vec[i].V.end()), reverse(vec[i].V.begin(), vec[i].V.end());
        if(!hsh.count(vec[i].V)) hsh[vec[i].V] = (sym[i] = ++hshcnt), val[hshcnt] = calc(vec[i].V);
        else i[sym] = hsh[vec[i].V];
    }
    nwcnt = hshcnt;
    Vec nw;
    Search(nw);
    for(int i = 1; i <= hshcnt; i++) {
        int tmp = !HH[val[i]] ? HH[val[i]] = ++hhcnt : HH[val[i]];
        addedge(i * 2 - 1, tmp + hshcnt * 2 + 1);
        addedge(tmp + hshcnt * 2 + 1, i * 2);
    }
    for(int i = 1; i <= nwcnt * 2; i += 2) {
        memset(Dis, 63, sizeof Dis);
        Dis[i] = 0;
        vector <int> V;
        V.clear(), V.push_back(i);
        for(int j = 0; j < V.size(); j++) {
            for(int T = Head[V[j]]; T; T = Next[T])
                if(Dis[Go[T]] > Dis[V[j]] + 1) {
                    Dis[Go[T]] = Dis[V[j]] + 1;
                    V.push_back(Go[T]);
                }
        }
        for(int j = 1; j <= nwcnt; j++)
            Ans[i / 2 + 1][j] = Dis[j * 2] - 2;
    }
    
    int q;
    scanf("%d", &q);
    for(int TT = 1; TT <= q; TT++) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", Ans[sym[a]][sym[b]]);
    }
    return 0;
}
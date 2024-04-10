#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5+5;
const int MAXM = 2e5+5;

int n,m,s;
vector<int> edges[MAXN];

int seen[MAXN];

int t;
int tu,tv;

void dfs(int cur, int st) {
    if (t || seen[cur] == st || cur == s) {
        return;
    }
    if (seen[cur]) {
        t = cur;
        tu = seen[cur];
        tv = st;
        return;
    }
    seen[cur] = st;
    for (int e : edges[cur]) {
        dfs(e, st);
    }
}

int seen2[MAXN];
vector<int> out;
bool dfs2(int cur, int target) {
    if (cur == target) {
        out.push_back(cur);
        return true;
    }
    if (seen2[cur] || cur == s) {
        return false;
    }
    seen2[cur] = 1;
    for (int e : edges[cur]) {
        if (dfs2(e,target)) {
            out.push_back(cur);
            return true;
        }
    }
    return false;
}


int main() {
    scanf("%d %d %d",&n,&m,&s);
    for (int i=0;i<m;i++) {
        int u,v;
        scanf("%d %d",&u,&v);
        edges[u].push_back(v);
    }
    for (int e : edges[s]) {
        seen[e] = e;
    }
    for (int e : edges[s]) {
        for (int f : edges[e]) {
            dfs(f,e);
        }
    }
    if (t) {
        printf("Possible\n");
        dfs2(tu, t);
        out.push_back(s);
        printf("%d\n",(int)out.size());
        reverse(out.begin(),out.end());
        for (int ite : out) {
            if (ite == out[out.size()-1]) {
                printf("%d\n",ite);
            } else {
                printf("%d ",ite);
            }
        }
        out.clear();
        dfs2(tv,t);
        out.push_back(s);
        printf("%d\n",(int)out.size());
        reverse(out.begin(),out.end());
        for (int ite : out) {
            if (ite == out[out.size()-1]) {
                printf("%d\n",ite);
            } else {
                printf("%d ",ite);
            }
        }
    } else {
        printf("Impossible\n");
    }
}
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

const int maxN = 4018;

struct printer {
    vector<char> data;
    int dim, pos;

    printer(int _dim) {
        dim = _dim;
        pos = 0;
        data.resize(dim + 11);
    }

    printer& operator<<(char c) {
        data[pos++] = c;
        if (pos == dim) {
            fwrite(&data[0], 1, dim, stdout);
            pos = 0;
        }
    }

    printer& operator<<(int x) {
        static vector<int> aux;

        if (x == 0) {
            (*this) << '0';
            return *this;
        }

        aux.clear();
        while (x > 0) {
            aux.pb(x % 10);
            x /= 10;
        }
        reverse(aux.begin(), aux.end());
        
        for (auto e : aux)
            (*this) << (char)('0' + e);
        return *this;
    }

    ~printer() {
        fwrite(&data[0], 1, pos, stdout);
    }
};

int a, b, m, i, j, x, y, gra[maxN], grb[maxN], mini, S, D;
vector< pair<int, int> > edges;

vector< pair<int, int> > list[maxN];
vector< vector<int> > ans;
bool us[maxN];

bool dfs(int node) {
    if (node == S) return true;
    if (us[node]) return false;
    us[node] = true;

    int i;
    for (i = 0; i < list[node].size(); i++) {
        auto e = list[node][i];
        list[node][i] = list[node].back();
        list[node].pop_back();
        
        if (dfs(e.first)) {
            list[e.first].pb(mp(node, e.second));
            return true;
        } else {
            list[node].pb(e);
            swap(list[node][i], list[node].back());
        }
    }

    return false;
}

void run() {
    vector<int> now = {};
    int i;
   
    while (dfs(D)) {
        memset(us, 0, sizeof(us));
        //cerr << "ano\n";
    }
    memset(us, 0, sizeof(us));

    for (i = 1; i <= b; i++) {
        for (auto e : list[a + i])
            if (e.second != 0)
                now.pb(e.second);
    }

    ans.pb(now);
}

int main()
{
    //freopen("test.in","r",stdin);
    printer fout(1 << 20);

    scanf("%d%d%d", &a, &b, &m);
    for (i = 1; i <= m; i++) {
        scanf("%d%d", &x, &y);
        edges.pb(mp(x, y));
        gra[x]++;
        grb[y]++;
        list[a + y].pb(mp(x, i));
    }

    mini = gra[1];
    for (i = 1; i <= a; i++)
        mini = min(mini, gra[i]);
    for (i = 1; i <= b; i++)
        mini = min(mini, grb[i]);

    S = a + b + 1;
    D = a + b + 2;
    for (i = 1; i <= a; i++) {
        for (j = 1; j <= gra[i] - mini; j++)
            list[i].pb(mp(S, 0));
    }
    for (i = 1; i <= b; i++) {
        for (j = 1; j <= grb[i] - mini; j++)
            list[D].pb(mp(a + i, 0));
    }

    for (; mini >= 0; mini--) {
        run();
        for (i = 1; i <= a; i++)
            list[i].pb(mp(S, 0));
        for (i = 1; i <= b; i++)
            list[D].pb(mp(a + i, 0));
    }
    

    for (i = ans.size() - 1; i >= 0; i--) {
        auto& v = ans[i];
        fout << (int)v.size() << ' ';
        for (auto &e : v) fout << e << ' ';  
        fout << '\n'; 
    }

    return 0;
}
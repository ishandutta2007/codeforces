#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < b; ++i)
#define trav(x,v) for(auto &x : v)
#define all(v) v.begin(),v.end()
#define sz(v) (int)(v.size())
#define rrep(i,a,b) for(int i = b; i --> a;)
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i, a, b) for (int i=(a); i<=(b); ++i)
vi v[10];
vi rev[10];
bool odw[10];

int tab[101][101][21];
vi top;
int fst[10];

int SKLA[10], SKL;
int nodes;
int ktory[10];
int H, W, S;
int edge[10][10];

void make_connection(int x1, int y1, int x2, int y2, int height) {
    while (y1 < y2) {
        ++y1;
        tab[x1][y1][height] = -1;
    }

    ++x1;
    while (x1 != x2) {
        tab[x1][y1][height] = -1;
        ++x1;
    }
}

void add_pillar(int x, int y, int h) {
    //cerr << "Adding pillars: " << x << ' ' << y << ' ' << h << endl;
    while (h <= H) tab[x][y][h] = -1, ++h;
}

void topdfs(int x) {
    odw[x] = 1;
    for (auto u : v[x])
        if (!odw[u]) topdfs(u);

    top.push_back(x);
}
vi graph;

void dfs(int x) {
    ++nodes;
    odw[x] = 1;
    SKLA[x] = SKL;

    tab[2 * nodes - 1][2 * nodes - 1][2 * SKL - 1] = x;
    ktory[x] = nodes;

    if (!graph.empty() && SKLA[graph.back()] == SKL) {
        make_connection(2 * (nodes - 1) - 1, 2 * (nodes - 1) - 1, 2 * nodes - 1,2 * nodes - 1, 2 * SKL - 1);
    }
    else fst[SKL] = x;
    graph.push_back(x);

    add_pillar(2 * nodes - 1, 2 * nodes - 1, 2 * SKL);
    for (auto u : rev[x]) {
        if (!odw[u]) dfs(u);
    }
}

int main(){
    H = 20, W = 20, S = 20;
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int n;
	cin >> n;
	for (int i=1; i<=n; ++i)
        for (int j=1; j<=n; ++j) {
            int val;
            cin >> val;
            edge[i][j] = val;
            if (val) v[i].push_back(j), rev[j].push_back(i);
        }

    for (int i=1; i<=n; ++i)
        if (odw[i] == 0) topdfs(i);

    fill(odw, odw+10, false);
    reverse(top.begin(), top.end());
    //cout << "TOP\n";
    //for (auto u : top) cout << u << ' ';
    //cout << endl;
    SKL = 10;
    for (auto u : top) {
        if (odw[u]) continue;
        --SKL;
        dfs(u);
    }

    FOR(i, 1, n)
        FOR(j, 1, n)
            if (SKLA[i] > SKLA[j] && i == fst[SKLA[i]] && j == fst[SKLA[j]] && edge[i][j] == 1) {
                assert(ktory[i] < ktory[j]);
                make_connection(2 * ktory[i] - 1, 2 * ktory[i] - 1, 2 * ktory[j] - 1, 2 * ktory[j] - 1, 2 * SKLA[i] - 1);
            }

    cout << W << ' ' << S << ' ' << H << endl;
    for (int h=H; h>0; --h) {
            for (int i=1; i<=W; ++i) {
                for (int j=1; j<=S; ++j)
                    if (tab[i][j][h] == -1) cout << ".";
                    else if (tab[i][j][h] == 0) cout << "#";
                    else cout << tab[i][j][h];
                cout << endl;
            }
            if (h != 1) cout << endl;
    }


}
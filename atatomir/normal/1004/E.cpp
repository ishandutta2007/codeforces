#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

const int maxN = 100011;

int n, k, i, x, y, z;
vector< pair<int, int> > list[maxN];
priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > >  H;
int gr[maxN];
int nodes, bad_nodes, last;
bool dead[maxN];

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &k);
    for (i = 1; i < n; i++) {
        scanf("%d%d%d", &x, &y, &z);
        list[x].pb(mp(y, z));
        list[y].pb(mp(x, z));
        gr[x]++; gr[y]++;
    }

    nodes = bad_nodes = 0;
    for (i = 1; i <= n; i++) {
        if (gr[i] > 1) {
            if (gr[i] > 2) bad_nodes++;
        } else {
            H.push(mp(0, i));

            gr[i]++;
            nodes++;
        }
    }
    nodes += n;

    while (bad_nodes > 0 || nodes > k) {
        auto aux = H.top(); H.pop();       
        nodes--;
        last = aux.first;
        int act = aux.second;
     
        //cerr << act << ' ' << last << '\n';
        //cerr << "!" << bad_nodes << ' ' << nodes << '\n';

        if (--gr[act] == 2) bad_nodes--;
        if (gr[act] > 1) continue;
        if (gr[act] == 0) break;

        //cerr << "!" << bad_nodes << ' ' << nodes << '\n';
        //for (i = 1; i <= n; i++) cerr << gr[i] << ' ';
        //cerr << '\n';

        dead[act] = true;
        for (auto to : list[act]) {
            if (dead[to.first]) continue;
            H.push(mp(last + to.second, to.first));
        }
    }

    printf("%d", last);


    return 0;
}
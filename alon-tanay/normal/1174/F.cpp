#include <bits/stdc++.h>

using namespace std;

vector<int> nei[200005];
int subsize[200005];
int depth[200005];
int chain[200005];
int parent[200005];

int rec(int node, int d = 0, int par = -1) {
    depth[node] = d;
    int sz = 1;
    for(int ne : nei[node]) {
        if(ne == par) { continue; }
        parent[ne] = node;
        sz += rec(ne,d+1,node);
    }
    return subsize[node] = sz;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 1; i < n; i ++) {
        int a, b;
        cin >> a >> b;
        nei[a].push_back(b);
        nei[b].push_back(a);
    }
    rec(1);
    vector<bool> visited(n+1);
    int root = 1;
    int x_depth;
    parent[1] = -1;
    cout << "d 1" << endl;
    cin >> x_depth;
    while(true) {
        if(x_depth == depth[root] || subsize[root] == 1) {
            cout << "! " << root << endl;
            return 0;
        }
        bool big_sub = false;
        int curr_size = 1;
        int root_par = parent[root];
        for(int ne : nei[root]) {
            if(visited[ne] || ne == root_par) { continue; };
            curr_size += subsize[ne];
        }
        for(int ne : nei[root]) {
            if(visited[ne] || ne == root_par) { continue; };
            if(subsize[ne] * 2 >= curr_size) {
                int par = root_par;
                int nxt = root;
                int chain_sz = 0;
                while(subsize[nxt] > 1) {
                    chain[chain_sz ++] = nxt;
                    visited[nxt] = true;
                    int mx_ne = 0;
                    int mx_sub = 0;
                    for(int ch : nei[nxt]) {
                        if(!visited[ch] && ch != par && subsize[ch] > mx_sub) {
                            mx_sub = subsize[ch];
                            mx_ne = ch;
                        }
                    }
                    par = nxt;
                    nxt = mx_ne;
                }
                chain[chain_sz] = nxt;
                visited[nxt] = true;
                cout << "d " << nxt << endl;
                int d;
                cin >> d;
                root = chain[(x_depth - d + depth[nxt]) / 2 - depth[root]];
                big_sub = true;
                break;
            }
        }
        if(big_sub) { continue; }
        cout << "s " << root << endl;
        root_par = root;
        cin >> root;
        if(root == -1) { return 0; }
    }
    return 0;
}

/*
5
1 2
1 3
3 4
3 5
*/

/*
10
1 5
5 8
9 7
5 2
3 8
1 4
9 10
9 5
10 6
*/

/*
  4
 /
1   2
 \ /
  5-8-3
   \
    9-7
     \
      10-6
*/
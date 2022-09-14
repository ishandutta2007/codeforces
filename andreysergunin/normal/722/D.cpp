#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <fstream>
#include <string.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define fs first
#define sc second

using namespace std;

const long long INF = 1e18;

struct Node {
    Node() {
        to[0] = -1;
        to[1] = -1;
        val = 0;
        ter = false;
    }
    int to[2];
    int val;
    int ter;
    int w;
};

vector<Node> nodes(1);

vector<int> res;



int dfs2(int v, int m, int d) {
    vector<int> to;
    if (nodes[v].to[0] != -1)
        to.push_back(nodes[v].to[0]);
    if (nodes[v].to[1] != -1)
        to.push_back(nodes[v].to[1]);

    int cnt = nodes[v].ter;

    for (int i = 0; i < sz(to); ++i) 
        cnt += dfs2(to[i], m, d + 1);

    if (nodes[v].val <= m && cnt > 0) {
        --cnt;
        res.push_back(nodes[v].val);
    }
    return cnt;
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    

    for (int i = 0; i < n; ++i)  {
        int a;
        cin >> a;
        vector<int> bits;

        for (; a != 0; a >>= 1) {
            bits.push_back(a & 1);
        } 

        int cur = 0;
        for (int j = sz(bits) - 1; j >= 0; --j) {
            if (nodes[cur].to[bits[j]] ==  -1) {
                nodes[cur].to[bits[j]] = sz(nodes);
                nodes.push_back(Node());
                nodes.back().val = nodes[cur].val * 2 + bits[j];
            }
            cur = nodes[cur].to[bits[j]];
        }
        nodes[cur].ter = true;
    }

    int l = 0, r = 1e9 + 10;

    while (r - l > 1) {
        int m = (r + l) / 2;
        res.clear();
        if (dfs2(1, m, 0) != 0)
            l = m;
        else 
            r = m;
    }

    res.clear();
    dfs2(1, r, 0);

    for (int i = 0; i < sz(res); ++i)
        cout << res[i] << " ";

    cout << endl;


}
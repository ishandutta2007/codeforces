/*
   First, we do a dfs to "flatten" our tree
   To answer a query: find the time of the most recent fill and empty updates, and whatever happened more recently is the answer
   To find the most recent fill update: range (max) update point query
   To find the most recent empty update: point update range (max) query
 */

#define MAX_N 500010
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

namespace point_u_range_q {
    // the number of additional nodes created can be as high as the next power of two up from MAX_N (131,072)
    int tree[MAX_N*4];

    // a is the index in the array. 0- or 1-based doesn't matter here, as long as it is nonnegative and less than MAX_N.
    // v is the value the a-th element will be updated to.
    // i is the index in the tree, rooted at 1 so children are 2i and 2i+1.
    // instead of storing each node's range of responsibility, we calculate it on the way down.
    // the root node is responsible for [0, MAX_N)
    void update(int a, int v, int i = 1, int start = 0, int end = MAX_N) {
        // this node's range of responsibility is 1, so it is a leaf
        if (end - start == 1) {
            tree[i] = v;
            return;
        }
        // figure out which child is responsible for the index (a) being updated
        int mid = (start + end) / 2;
        if (a < mid) update(a, v, i * 2, start, mid);
        else update(a, v, i * 2 + 1, mid, end);
        // once we have updated the correct child, recalculate our stored value.
        tree[i] = max(tree[i*2], tree[i*2+1]);
    }


    /*
    * range tree query
    */

    // query the sum in [a, b)
    int query(int a, int b, int i = 1, int start = 0, int end = MAX_N) {
        // the query range exactly matches this node's range of responsibility
        if (start == a && end == b) return tree[i];
        // we might need to query one or both of the children
        int mid = (start + end) / 2;
        int answer = 0;
        // the left child can query [a, mid)
        if (a < mid) answer = max(answer, query(a, min(b, mid), i * 2, start, mid));
        // the right child can query [mid, b)
        if (b > mid) answer = max(answer, query(max(a, mid), b, i * 2 + 1, mid, end));
        return answer;
    }
}

namespace range_u_point_q {
    int lazymax[MAX_N*4];

    // The root node is responsible for [0, MAX_N). Update range [uL, uR)
    // Compare to range query code.
    void update(int uL, int uR, int v, int i = 1, int cLeft = 0, int cRight = MAX_N) {
        if (uL == cLeft && uR == cRight) {
            lazymax[i] = max(v, lazymax[i]);
            return;
        }
        int mid = (cLeft + cRight) / 2;
        if (uL < mid) update(uL, min(uR, mid), v, i * 2, cLeft, mid);
        if (uR > mid) update(max(uL, mid), uR, v, i * 2 + 1, mid, cRight);
    }

    int query(int p, int i = 1, int cLeft = 0, int cRight = MAX_N) {
        if (cRight - cLeft == 1) {
            return lazymax[i];
        }
        int mid = (cLeft + cRight) / 2;
        int ans = lazymax[i];
        if (p < mid) ans = max(ans, query(p, i * 2, cLeft, mid));
        else ans = max(ans, query(p, i * 2 + 1, mid, cRight));
        return ans;
    }
}


vector<int> adj[MAX_N];
int subtree_start[MAX_N], subtree_end[MAX_N], upto = 1, n, q;
void dfs(int a) {
    subtree_start[a] = upto;
    upto++;

    for (int b : adj[a]) {
        if (!subtree_start[b]) {
            dfs(b);
        }
    }

    subtree_end[a] = upto;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        // edge from a to b
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1);

    /*for (int i = 1; i <= n; i++) {
        printf("%d: %d %d\n", i, subtree_start[i], subtree_end[i]);
    }*/

    scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
        int t, a;
        scanf("%d%d", &t, &a);
        if (t == 1) {
            // fill
            range_u_point_q::update(subtree_start[a], subtree_end[a], i);
        } else if (t == 2) {
            point_u_range_q::update(subtree_start[a], i);
        } else if (t == 3) {
            // find the time of the most recent fill update
            int most_recent_fill = range_u_point_q::query(subtree_start[a]);
            // find the most recent empty
            int most_recent_empty = point_u_range_q::query(subtree_start[a], subtree_end[a]);

            if (most_recent_empty >= most_recent_fill) {
                printf("0\n");
            } else {
                printf("1\n");
            }
        }
    }
}
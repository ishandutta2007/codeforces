#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
#define ld long double

using namespace std;

const int mx = 200005;

bool special[mx];
vector<int> nei[mx];
int dist1[mx];
int distn[mx];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> s(k);
    for(int &S : s) {
        cin >> S;
        special[S] = true;
    }
    for(int i = 0; i < m; i ++) {
        int a, b;
        cin >> a >> b;
        nei[a].push_back(b);
        nei[b].push_back(a);
    }
    vector<int> sorted(k);
    int idx = 0;
    deque<int> bfs = {1};
    dist1[1] = 1;
    while(bfs.size()) {
        int cur = bfs.back();
        bfs.pop_back();
        if(special[cur]) {
            sorted[idx++] = cur;
        }
        for(int ne : nei[cur]) {
            if(!dist1[ne]) {
                dist1[ne] = dist1[cur] + 1;
                bfs.push_front(ne);
            }
        }
    }
    bfs = {n};
    distn[n] = 1;
    while(bfs.size()) {
        int cur = bfs.back();
        bfs.pop_back();

        for(int ne : nei[cur]) {
            if(!distn[ne]) {
                distn[ne] = distn[cur] + 1;
                bfs.push_front(ne);
            }
        }
    }
    int mxDist = distn[sorted[k-1]]-1;
    int res = 0;
    for(int i = k - 2; i >= 0; i --) {
        res = max(res,mxDist + dist1[sorted[i]]);
        mxDist = max(mxDist,distn[sorted[i]]-1);
    }
    cout << min(res,dist1[n]-1);
    // int mx1 = 1;
    // int sc1 = 1;
    // int mxn = n;
    // int scn = n;
    // for(int S : s) {
    //     if(dist1[S] >= dist1[mx1]) {
    //         sc1 = mx1;
    //         mx1 = S;
    //     } else if(dist1[S] > dist1[sc1]) {
    //         sc1 = S;
    //     }
    //     if(dist1[S] >= distn[mxn]) {
    //         scn = mxn;
    //         mxn = S;
    //     } else if(dist1[S] > distn[scn]) {
    //         scn = S;
    //     }
    // }
    // int res = 0;
    // if(mx1 == mxn) {

    // } else {
    //     res = min(dist1[n],dist1[mx1]+dist2[mx2]+1)
    // }
    // int res = dist[n];
    return 0;
}

/*
1
5 7
1 2 3 4 6
*/
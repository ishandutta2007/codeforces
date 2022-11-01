#include <bits/stdc++.h>
#define pb push_back
#define mt make_tuple
#define i first
#define j second
using namespace std;

int pr[1000000], sz[1000000];

void MakeSet(int el) {
    pr[el] = el;
    sz[el] = 1;
}

int FindSet(int el) {
    return (pr[el] == el ? el : pr[el] = FindSet(pr[el]));
}

void Union(int x, int y) {
    if((x = FindSet(x)) != (y = FindSet(y))) {
        if(sz[x] < sz[y]) swap(x, y);
        pr[y] = x; sz[x] += sz[y];
    }
}

int n, m, a[1000][1000];
int go[][2] = {1,0, -1,0, 0,1, 0,-1};

int main()
{
    ios_base::sync_with_stdio(0);
    long long k;
    cin >> n >> m >> k;
    vector<tuple<int,int,int> > all;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> a[i][j], MakeSet(i*m + j), all.pb(mt(-a[i][j], i, j));
    for(int i=0; i<n; i++) for(int j=0; j<m; j++)
            if(a[i][j] == k) {
                cout << "YES\n";
                for(int p=0; p<n; p++, cout << "\n") for(int q=0; q<m; q++)
                    cout << (p==i && q==j ? k : 0) << " ";
                return 0;
            }
    sort(all.begin(), all.end());
    for(auto ad : all) {
        int v=-get<0>(ad), i=get<1>(ad), j=get<2>(ad);
        for(int w=0; w<4; w++) {
            int ii = i + go[w][0], jj = j + go[w][1];
            if(ii>=0 && ii<n && jj>=0 && jj<m && v <= a[ii][jj])
                Union(i*m+j, ii*m+jj);
        }
        if(k % a[i][j] == 0 && sz[FindSet(i*m+j)] >= k / a[i][j]) {
            cout << "YES\n";
            queue<pair<int,int> > q;
            bool b[n][m];
            for(int p=0; p<n; p++) for(int q=0; q<m; q++) b[p][q] = 0;
            b[i][j] = 1;
            q.push({i, j});
            int opt = (int)(k / a[i][j]), cnt = 1;
            while(!q.empty() && cnt < opt) {
                pair<int,int> c = q.front();
                q.pop();
                for(int w=0; w<4 && cnt < opt; w++) {
                    int ii = c.i + go[w][0], jj = c.j + go[w][1];
                    if(ii>=0 && ii<n && jj>=0 && jj<m && !b[ii][jj] && a[ii][jj] >= a[i][j])
                        b[ii][jj] = 1, cnt++, q.push({ii, jj});
                }
            }
            for(int p=0; p<n; p++, cout << "\n") for(int q=0; q<m; q++)
                cout << (b[p][q] ? a[i][j] : 0) << " ";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}
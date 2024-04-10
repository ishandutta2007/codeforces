//Author: Vclav Volhejn (-Wave-)
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
typedef long long ll;
const int CHUNK = 1000;
const int N = 1e6;
const int CN = 1010;

vector<pair<pair<int,int>, int>> chunks[CN][CN];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
cin.tie(0);
    int n;
    cin >> n;
    rep(i, 0, n) {
        int x, y;
        cin >> x >> y;
        chunks[x / CHUNK][y / CHUNK].push_back({{x, y}, i+1});
    }
    vector<int> res;
    for(int cy = 0; cy < CN; cy++) {
        rep(cx, 0, CN) {
            if(!chunks[cx][cy].size()) continue;
            sort(chunks[cx][cy].begin(),chunks[cx][cy].end());
            for(auto x : chunks[cx][cy]) res.push_back(x.second);
        }
        cy++;
        per(cx, 0, CN) {
            if(!chunks[cx][cy].size()) continue;
            sort(chunks[cx][cy].begin(),chunks[cx][cy].end());
            reverse(chunks[cx][cy].begin(),chunks[cx][cy].end());
            for(auto x : chunks[cx][cy]) res.push_back(x.second);
        }
    }
    rep(i,0,n) cout << res[i] << " "; cout << endl;
    return 0;
}
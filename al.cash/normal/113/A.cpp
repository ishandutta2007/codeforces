#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <complex>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define FOR(i, a, b) for(int i(a), _b(b); i < _b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define FORD(i, a, b) for(int i(a), _b(b); i >= _b; --i)
#define CL(a, v) memset(a, v, sizeof a)
#define UNIQUE(a) sort(all(a)), (a).erase(unique(all(a)), (a).end())
#define pb push_back
#define X first
#define Y second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int INF = 1000000000;
const ll INFLL = 1000000000000000000LL;

const string e[3][2] = {
    "lios", "liala",
    "etr", "etra",
    "initis", "inites"
};

int k[3];

int main () {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif
    string s;
    int r = -1;
    int u = -1;
    bool ok = true;
    while(cin>>s) {
        int i=0, j=0;
        while(s.substr(max(0, sz(s)-sz(e[i][j])), sz(s)) != e[i][j]) {
            ++j;
            if(j==2) {
                ++i;
                j=0;
                if(i==3) break;
            }
        }
        if(i<u || i==3) {
            ok = false;
            break;
        }
        else u = i;
        if(r!=-1 && j!=r) {
            ok = false;
            break;
        }
        else r = j;
        ++k[u];
    }
    if(k[0]+k[1]+k[2]!=1 && k[1]!=1) ok = false;
    printf("%s\n", ok ? "YES" : "NO");
#ifdef LocalHost
  cout << endl << "Time: " << clock() << endl;
#endif
  return 0;
}
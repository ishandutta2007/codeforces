#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>

using namespace std;

#define F first
#define S second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))

#define equal equalll
#define less lesss
const int N = 5555;
const int M = 1111;
const long long INF = 1e9 + 19;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

int cnt[2][M];
int dp[2][N][M];
int n, m;


int main(){
#ifdef HOME 
    freopen("in", "r", stdin);
#endif
    scanf("%d%d", &n, &m);
    map<string,int> q;
    for (int i = 0; i < n; i++) {
        string nameA;
        string tmp;
        cin >> nameA;
        q[nameA] = i;
        cin >> tmp;
        assert(tmp == ":=");
        string s;
        cin >> s;
        if (s[0] == '1' || s[0] == '0') {
            assert((int)s.size() == m);
            for (int j = 0; j < m; j++) {
                dp[0][i][j] = s[j] - '0';
                dp[1][i][j] = s[j] - '0';
            }
        }
        else {
            string op;
            string arg2;
            cin >> op;
            cin >> arg2;
            int idL = q[s];
            int idR = q[arg2];
            for (int t = 0; t < 2; t++) 
                for (int j = 0; j < m; j++) {
                    int l, r;
                    if (s[0] == '?') 
                        l = t;
                    else 
                        l = dp[t][idL][j];

                    if (arg2[0] == '?')
                        r = t;
                    else
                        r = dp[t][idR][j];
                    int res;
                    if (op[0] == 'O')
                        res = l | r;
                    else if (op[0] == 'X')
                        res = l ^ r;
                    else if (op[0] == 'A')
                        res = l & r;
                    else
                        assert(false);
                    dp[t][i][j] = res;
                } 
        }
    }
    
    for (int t = 0; t < 2; t++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cnt[t][j] += dp[t][i][j];

    for (int j = 0; j < m; j++) {
        if (cnt[0][j] <= cnt[1][j])
            printf("0");
        else
            printf("1");
    }
    puts("");

    for (int j = 0; j < m; j++) {
        if (cnt[0][j] >= cnt[1][j])
            printf("0");
        else
            printf("1");
    }
    puts("");

    


    return 0;
}
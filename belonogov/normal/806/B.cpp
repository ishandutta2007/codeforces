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
#include <random>
#include <functional>

using namespace std;

#define F first
#define S second
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define dbv(a) cerr << #a << ": "; for (auto& xxxx: a) cerr << xxxx << " "; cerr << endl;
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))

#define equal equalll
#define less lesss
typedef long double dbl;
typedef long long ll;
const int N = 4444;
const int M = 6;
const ll INF = 1.01e9;
typedef vector<int> vi;


vector<vector<int>> a;
int st[N];
ll answer = INF;
vector<int> points = {500, 1000, 1500, 2000, 2500, 3000};
vector<int> cntOk;
int can[N][M][M];


int calcScore(vector<int> tmr) {
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        if (tmr[i] == -1) continue;

        sum += points[st[i]];
        sum -= points[st[i]] / 250 * tmr[i];
    }
    return sum;
}

void rec(int pos) {
    if (pos == 5) {
        //for (int i = 0; i < 5; i++) 
            //st[i] = 0;
        //st[0] = 2;
        //db2(calcScore(a[0]), calcScore(a[1]));
        if (calcScore(a[0]) > calcScore(a[1])) {
            //for (int i = 0; i < 5; i++) {
                //cerr << st[i] << " ";
            //}
            //cerr << endl;
            for (int i = 0; i < min(answer, N * 1ll); i++) {
                bool ok = 1;
                for (int j = 0; j < 5; j++) {
                    ok &= can[i][j][st[j]];
                }
                if (ok) {
                    answer = i;
                    break;
                }
            }
            //ll need = 0;
            //for (int i = 0; i < 5; i++) {
                //need = max(need, G[i][st[i]]);
            //}
            ////db(need);
            //answer = min(answer, need);
        }
        //exit(0);
        return;
    }

    for (int i = 0; i < 6; i++) {
        st[pos] = i;
        rec(pos + 1);
    }
}



int main(){
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    int n;
    scanf("%d", &n);
    a.resize(n, vector<int>(5, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    cntOk.assign(5, 0);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 5; j++)
            if (a[i][j] != -1)
                cntOk[j]++;

    //G.resize(5, vector<ll> (6, INF));
    //kF.resize(5, vector<ll> (6, INF));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 5; j++) {

            if (a[0][j] == -1) {
                int total = i + n;
                int cc = cntOk[j];
                if (cc * 2 > total)
                    can[i][j][0] = 1;
                else if (cc * 4 > total)
                    can[i][j][1] = 1;
                else if (cc * 8 > total)
                    can[i][j][2] = 1;
                else if (cc * 16 > total)
                    can[i][j][3] = 1;
                else if (cc * 32 > total)
                    can[i][j][4] = 1;
                else 
                    can[i][j][5] = 1;
            }
            else {
                int total = i + n;
                int mn = cntOk[j];  
                int mx = cntOk[j] + i;
                if (mx * 2 > total) 
                    can[i][j][0] = 1;
                
                if (mx * 4 > total && mn * 2 <= total) 
                    can[i][j][1] = 1;

                if (mx * 8 > total && mn * 4 <= total) 
                    can[i][j][2] = 1;

                if (mx * 16 > total && mn * 8 <= total) 
                    can[i][j][3] = 1;

                if (mx * 32 > total && mn * 16 <= total) 
                    can[i][j][4] = 1;

                if (mn * 32 <= total) 
                    can[i][j][5] = 1;
            }
        }
    }

    //db(can[4000][5][5]);


    //auto upd = [](ll& A, ll B) {
        //A = min(A, B);
    //};

    //for (int i = 0; i < 5; i++) {
        //for (int t = 0; t < 4000; t++) {
            //ll total = n + t;
            //ll cc = cntOk[i];
         

        //if (a[0][i] != -1) {
            //for (int t = 0; t < 4000; t++) {
                //ll total = n + t;
                //ll cc  = cntOk[i] + t;
                //if (cc * 2 > total)
                    //upd(G[i][0], t);
                //else if (cc * 4 > total)
                    //upd(G[i][1], t);
                //else if (cc * 8 > total)
                    //upd(G[i][2], t);
                //else if (cc * 16 > total)
                    //upd(G[i][3], t);
                //else if (cc * 32 > total)
                    //upd(G[i][4], t);
                //else 
                    //upd(G[i][5], t);
            //} 
        //}
    //}

    //for (int i = 0; i < 5; i++, cerr << endl)
        //for (int j = 0; j < 6; j++)
            //cerr << G[i][j] << " ";


    rec(0);

    


    

    if (answer == INF) {
        answer = -1;
    }
    cout << answer << endl;

    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}
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

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = 1e6;
const long long INF = 1e18 + 19;
const int F = 5;

int n, k, c5, c1;
int t[N];
vector < int > rem[F];

void read() {
    scanf("%d%d%d%d", &n, &k, &c5, &c1);
    for (int i = 0; i < n; i++)
        scanf("%d", &t[i]);
}

long long solve() {
    sort(t, t + n);
    c5 = min(c5, c1 * 5);
    for (int i = 0; i < F; i++)
        rem[i].clear();
    for (int i = 0; i < n; i++)
        rem[((t[i] % F) + F) % F].pb(t[i]);
    //db("here");
    vector < int > need;
    for (int i = 0; i < n; i++) 
        for (int dt = 0; dt < F; dt++) 
            need.pb(t[i] + dt);


    sort(need.begin(), need.end());
    need.resize(unique(need.begin(), need.end()) - need.begin());

    vector < int > h[F];    
    for (auto x: need)
        h[((x % F) + F) % F].pb(x);

    long long answer = INF;  



    for (int j = 0; j < F; j++) {
        //cerr << "h: ";
        //for (auto x: h[j])
            //cerr << x << " ";
        //cerr << endl;
        long long cnt = 0;
        vector < int > curL(F, 0);
        vector < int > curR(F, 0);
        //for (auto x: h[j]) {
        for (int ii = 0; ii < (int)h[j].size(); ii++) {
            for (int i = 0; i < F; i++)
                for (; curR[i] < (int)rem[i].size() && rem[i][curR[i]] <= h[j][ii]; curR[i]++) {
                    cnt += (h[j][ii] - rem[i][curR[i]]) / F;                     
                }
            long long sum = 0;
            for (int i = 0; i < F; i++) {
                assert(curL[i] <= curR[i]);
                sum += curR[i] - curL[i];
            }
            //db2(ii, sum);
            //db(cnt);
            for (; sum > k; sum--) {
                int where = -1;
                long long cost = -1;
                long long cost2 = -1;
                for (int i = 0; i < F; i++) {
                    if (curL[i] < curR[i]) {
                        long long tmpCost = (h[j][ii] - rem[i][curL[i]]) / F * 1ll * c5 + (j - i + F) % F * c1;
                        long long tmpCost2 = (h[j][ii] - rem[i][curL[i]]) / F;
                        if (tmpCost > cost) {
                            cost = tmpCost;
                            cost2 = tmpCost2;
                            where = i;
                        }
                    } 
                } 
                assert(where != -1);
                curL[where]++;
                cnt -= cost2;
            }
            if (sum == k) {
                long long res = 0;
                for (int i = 0; i < F; i++) {
                    int cof = (j + F - i) % F;
                    res += cof * 1ll * c1 * (curR[i] - curL[i]);
                }
                answer = min(answer, res + cnt * 1ll * c5);
            }

            if (ii + 1 < (int)h[j].size())
                cnt += sum * 1ll * ((h[j][ii + 1] - h[j][ii]) / F);
        }
        //break;


    }




    return answer;
}

long long stupid() {
    sort(t, t + n);
    c5 = min(c5, c1 * 5);
    long long answer = INF; 
    for (int i = 0; i < n; i++) {
        for (int dt = 0; dt < 5; dt++) {
            int tmr = t[i] + dt;
            vector < int > cost;
            for (int j = 0; j < n; j++) {
                if (t[j] <= tmr) {
                    int diff = tmr - t[j];
                    cost.pb(diff / 5 * c5 + diff % 5 * c1);
                }
            }
            sort(cost.begin(), cost.end());
            if ((int)cost.size() >= k) {
                long long res = 0;
                for (int i = 0; i < k; i++)
                    res += cost[i];
                answer = min(answer, res);
            }
        }
    }
    return answer;

}

void printTest() {
    cerr << n << " " << k << " " << c5 << " " << c1 << endl;
    for (int i = 0; i < n; i++)
        cerr << t[i] << " ";
    cerr << endl;
}

void stress() {
    for (int tt = 0; ; tt++) {
        db(tt);
        int T = 10;
        int G = 30;
        n = rand() % T + 1;
        k = rand() % n + 1;
        for (int i = 0; i < n; i++) 
            t[i] = rand() % G;
            //t[i] = rand() % G - (G / 2);
        c1 = rand() % G + 1;
        c5 = rand() % (G * 3) + 1;
        auto r1 = solve();
        auto r2 = stupid();
        //printTest();
        db2(r1, r2);
        assert(r1 == r2);
    }

}



int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        int k = 1;
        for (int tt = 0; tt < k; tt++) {
            read();
            cout << solve() << endl;
            //cout << stupid() << endl;
        }
    }
    else {
        stress();
    }

    return 0;
}
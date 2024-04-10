#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <cstdlib>
#include <cmath>


using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)
const int N = 1e3 + 10;
const int INF = 1e9;

struct Line {
    int id;
    long long sum; 
    int cnt;
    bool operator < (const Line & t) const {
        return sum > t.sum || (sum == t.sum && id < t.id);
    }
};

int a[N][N];
int sumN[N];
int sumM[N];
int cnt[N];
set < Line > qN;
set < Line > qM; 


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    int n, m, k, p;
    long long ans, res = 0;
    scanf("%d%d%d%d", &n, &m, &k, &p);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);
    for (int i = 0; i < n; i++)
       for (int j = 0; j < m; j++) {
            sumN[i] += a[i][j];
            sumM[j] += a[i][j];
       } 
    for (int i = 0; i < n; i++) {
        Line d = {i, sumN[i], 0};
        qN.insert(d);
    } 
    for (int i = 0; i < k; i++) {
        Line d = *qN.begin();
        qN.erase(qN.begin());
        res += d.sum;
        d.sum -= p * m;
        d.cnt++;
        qN.insert(d);
    }
    ans = res;
    for (int i = 0; i < m; i++) {
        Line d = {i, sumM[i], 0};
        qM.insert(d);
    }
    for (int i = 0; i < k; i++) {
        for (;;) {
            assert(!qN.empty());
            set < Line > :: iterator it = qN.end();        
            it--;
            Line d = *it;
            qN.erase(it);  
            if (d.cnt == 0)
                continue;
            d.sum += p * m; 
            d.cnt--;
            res -= d.sum;
            if (d.cnt > 0)
                qN.insert(d); 
            break;
        }
        ////
        Line d = *qM.begin();
        qM.erase(qM.begin());
        res += d.sum; 
        d.cnt++; 
        d.sum -= p * n;
        qM.insert(d);
        ans = max(res - (i + 1) * 1ll * (k - i - 1) * p, ans);
        //cerr << res - (i + 1) * 1ll * (k - i - 1) * p << endl;
    }
    printf("%lld\n", ans);
    return 0;
}
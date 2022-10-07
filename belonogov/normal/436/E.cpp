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
const int N = 1e6 + 10;
const int INF = 1e9;

struct Candy {
    int a, b, id;   
    Candy() { }
};

Candy a[N];
Candy b[N];
set < pair < int, int > > getF, getS, canF, canS;
long long sum, res;
int ans[N];
int n, w;

bool cmpA(Candy a, Candy b) {
    return a.a < b.a;
}

void insert(set < pair < int, int > > & t, pair < int, int > val, int cnt, int kof) {
    assert(t.find(val) == t.end());
    t.insert(val);
    sum += cnt * kof;
    res += val.fr * kof;
}

void erase(set < pair < int, int > > & t, pair < int, int > val, int cnt, int kof) {
    assert(t.find(val) != t.end());
    t.erase(val);
    sum += cnt * kof;
    res += val.fr * kof;
}

void read() {
    scanf("%d%d", &n, &w);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a[i].a, &a[i].b);
    }
}

long long solve() {
    int val1, val2;
    long long answer = 1e18;
    pair < int, int > tmp1, tmp2, tmp, tmpCan, tmpGet;
    for (int i = 0; i < n; i++)
        a[i].id = i;
    for (int i = 0; i < n; i++)
        b[i] = a[i];
    sort(a, a + n, cmpA);
    int cur = -1;
    for (int i = 0; i < n; i++)
        ans[i] = 0;
    //for (int i = 0; i < n; i++)
        //cerr << a[i].a << " " << a[i].b << endl;
    //cerr << endl;
    for (int ttt = 0; ttt < 2; ttt++) {
        canS.clear();
        canF.clear();
        getF.clear();
        getS.clear();
        sum = 0;
        res = 0;
        for (int i = 0; i < n; i++)
            canS.insert(mp(a[i].b, a[i].id));
        for (int i = 0; i <= n; i++) {
            if (i > w) break;
            if (!(i == 0 && w % 2 == 1)) {
                if (!canF.empty() && abs(sum - w) % 2 != 0) {
                    tmpCan = *canF.begin();
                    insert(getF, tmpCan, 1, 1);
                    erase(canF, tmpCan, 0, 0);
                }
                if (!getF.empty() && abs(sum - w) % 2 != 0) {
                    tmpGet = *getF.rbegin();
                    insert(canF, tmpGet, 0, 0);
                    erase(getF, tmpGet, 1, -1);
                }
                assert(abs(sum - w) % 2 == 0);
                for (;sum < w;) {
                    if (!canS.empty()) {
                        tmpCan = *canS.begin();
                        insert(getS, tmpCan, 2, 1);
                        erase(canS, tmpCan, 0, 0);
                        continue;
                    }
                    if ((int)canF.size() >= 2) {
                        for (int tt = 0; tt < 2; tt++) {
                            tmpCan = *canF.begin();
                            insert(getF, tmpCan, 1, 1);
                            erase(canF, tmpCan, 0, 0);
                        }
                        continue;
                    }
                    assert(false);
                }
                for (;sum > w;) {
                    if (!getS.empty()) {
                        tmpGet = *getS.rbegin();
                        insert(canS, tmpGet, 0, 0);
                        erase(getS, tmpGet, 2, -1);
                        continue;
                    } 
                    if ((int)getF.size() >= 2) {
                        for (int tt = 0; tt < 2; tt++) {
                            tmpGet = *getF.rbegin();
                            insert(canF, tmpGet, 0, 0);
                            erase(getF, tmpGet, 1, -1);
                        }
                        continue;
                    }
                    assert(false);
                }
                assert(sum == w);
                for (;;) {
                    if (!canF.empty() && !getF.empty() && canF.begin()->fr < getF.rbegin()->fr) {
                        tmpCan = *canF.begin();
                        tmpGet = *getF.rbegin();
                        insert(getF, tmpCan, 1, 1);
                        insert(canF, tmpGet, 0, 0);
                        erase(getF, tmpGet, 1, -1);  
                        erase(canF, tmpCan, 0, 0); 
                        continue;
                    }
                    if (!canS.empty() && !getS.empty() && canS.begin()->fr < getS.rbegin()->fr) {
                        tmpCan = *canS.begin();
                        tmpGet = *getS.rbegin();
                        insert(getS, tmpCan, 2, 1);
                        insert(canS, tmpGet, 0, 0);
                        erase(getS, tmpGet, 2, -1);  
                        erase(canS, tmpCan, 0, 0); 
                        continue;
                    }
                    break;
                }
                //if (ttt == 0)
                    //cerr << "i sum res: " << i << " " << sum << " " << res << endl;
                for (;;) {
                    if ((int)getF.size() >= 2 && (int)canS.size() >= 1) {
                        set < pair < int, int > > :: iterator it = getF.end();
                        it--;
                        val1 = it->fr; it--;
                        val1 += it->fr;
                        val2 = canS.begin()->fr;
                        //cerr << "sz f s: " << getF.size() << " " << getS.size() << endl;
                        //cerr << "val1 val2: " << val1 << " " << val2 << endl;
                        if (val1 > val2) {
                            tmp1 = *it;
                            it++;
                            tmp2 = *it;
                            insert(canF, tmp1, 0, 0);
                            insert(canF, tmp2, 0, 0);
                            erase(getF, tmp1, 1, -1);
                            erase(getF, tmp2, 1, -1);
                                
                            tmp = *canS.begin();
                            insert(getS, tmp, 2, 1);
                            erase(canS, tmp, 0, 0);
                            continue;
                        }
                    }
                    if ((int)canF.size() >= 2 && (int)getS.size() >= 1) {
                        set < pair < int, int > > :: iterator it = canF.end();
                        it--;
                        val1 = it->fr; it--;
                        val1 += it->fr;
                        val2 = getS.rbegin()->fr;
                        if (val1 < val2) {
                            tmp1 = *it;
                            it++;
                            tmp2 = *it;
                            insert(getF, tmp1, 1, 1);
                            insert(getF, tmp2, 1, 1);
                            erase(canF, tmp1, 0, 0);
                            erase(canF, tmp2, 0, 0);
                                
                            tmp = *getS.begin();
                            insert(canS, tmp, 0, 0);
                            erase(getS, tmp, 2, -1);
                            continue;
                        }
                    }
                    break;
                }
                if (ttt == 0) {
                    if (answer > res) {
                        answer = res;
                        cur = i;
                    }
                }
                if (ttt == 1 && cur == i) {
                    assert(answer == res);
                    for (int j = 0; j < i; j++)
                        ans[a[j].id]++;
                    //cerr << getF.size() << endl;
                    //cerr << getS.size() << endl;
                    for (set < pair < int, int > > :: iterator it = getF.begin(); it != getF.end(); it++)
                        ans[it->sc]++;
                    for (set < pair < int, int > > :: iterator it = getS.begin(); it != getS.end(); it++) 
                        ans[it->sc] += 2;
                }
            }


///     finish
            if (i == n) continue;
            if (canS.find(mp(a[i].b, a[i].id)) != canS.end()) {
                canS.erase(mp(a[i].b, a[i].id));
            } 
            else {
                erase(getS, mp(a[i].b, a[i].id), 2, -1);
            }
            sum++;
            res += a[i].a;
            insert(canF, mp(a[i].b - a[i].a, a[i].id), 0, 0);
        }
    }        
    long long secondAnswer = 0;
    for (int i = 0; i < n; i++) {
        if (ans[i] == 1) secondAnswer += b[i].a;
        if (ans[i] == 2) secondAnswer += b[i].b;
    }
    assert(answer == secondAnswer);
    return answer;
}

void genTest() {
    n = 10;
    w = 1 + rand() % (n * 2);
    int T = 50;
    for (int i = 0; i < n; i++) {
        a[i].a = rand() % T + 1;
        a[i].b = a[i].a + 1 + rand() % T;
    }
}
int e[N]; 

void decode(int mask) {
    for (int i = 0; i < n; i++, mask /= 3)
        e[i] = mask % 3;
}

long long stupid() {
    int st = 1;
    int ans = INF;
    for (int i = 0; i < n; i++)
       st *= 3; 
    for (int mask = 0; mask < st; mask++) {
        decode(mask);  
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += e[i];
        if (sum != w) continue; 
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (e[i] == 1) res += a[i].a;
            if (e[i] == 2) res += a[i].b;
        }
        ans = min(res, ans);
    }
    return ans;
}

void printTest() {
    epr("%d %d\n", n, w);
    for (int i = 0; i < n; i++)
        epr("%d %d\n", a[i].a, a[i].b);
}

void stress() {
    for (int tt = 0; tt < 200000; tt++) {
        cerr << "test: " << tt << endl;
        genTest();    
        int r1 = solve();
        int r2 = stupid();
        if (r1 != r2) {
            cerr << "fail\n";
            cerr << "r1 r2: " << r1 << " " << r2 << endl;
            printTest();
            return;
        } 
    }
}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (0) {
        stress();
    }
    else {
        read();
        long long answer = solve();
        printf("%lld\n", answer);
        for (int i = 0; i < n; i++)
            printf("%d", ans[i]);
    }
   return 0;
}
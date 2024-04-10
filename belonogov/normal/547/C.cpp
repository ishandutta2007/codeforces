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

#define equal equalll
#define less lesss
#define count counttt
const int N = 1e6;
const int INF = 1e9;

int n, q;
int a[N];
vector < int > d[N];
int cnt[N];
int use[N];
int c[N];
int count;
long long sum;
vector < int > query;

void read() {
    scanf("%d", &n);
    scanf("%d", &q);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    query.resize(q);
    for (int i = 0; i < q; i++)
        scanf("%d", &query[i]);
}


void add(int cof, int v) {
    for (auto x: d[v]) {
        cnt[x] += cof;
    }
    count += cof;
    //db2(count, cof);
}

void calc(int cof, int v) {
    long long dif = 0;
    for (auto x: d[v]) {
        //dif += cnt[x];
        //cerr << "x:  " << x << " " ;
        //db2(cnt[x], c[x]);
        dif += cnt[x] * c[x];
    }
    //db2(count, dif);
    long long tmp = count - dif;
    sum += cof * tmp; 
}


vector < long long > solve() {
    int mx = 0;
    count = 0;
    for (int i = 0; i < n; i++)
        mx = max(a[i], mx);
    for (int i = 0; i <= mx; i++)
        cnt[i] = 0;
    for (int i = 1; i <= mx; i++) {
        int sum = 0;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                sum += c[j];
                if (j * j != i) 
                    sum += c[i / j];
            }
        }
        c[i] = 1 - sum;
    } 
    
    for (int i = 0; i < n; i++) {
        d[i].clear();
        use[i] = 0;
    }
 


    vector < long long > answer;
    for (int i = 0; i < n; i++) {
        for (int j = 2; j * j <= a[i]; j++) {
            if (a[i] % j == 0) {
                d[i].pb(j);
                if (j * j != a[i])
                    d[i].pb(a[i] / j);
            }
        }
        if (a[i] > 1)
            d[i].pb(a[i]);
    }
    //for (int i = 0; i < n; i++, cerr << endl) {
        //for (auto x: d[i])
            //cerr << x << " ";
    //}
    sum = 0;
    for (int i = 0; i < q; i++) {
        int v = query[i];
        v--;
        if (use[v]) {
            add(-1, v);
            calc(-1, v);
        }
        else {
            calc(1, v);
            add(1, v);
        }

        use[v] ^= 1;

        answer.pb(sum);
    } 
    return answer;
}

void printAns() {


}

vector < long long > stupid() {
    vector < int > used(n, 0);
    vector < long long > answer;
    for (int i = 0; i < q; i++) {
        int v = query[i] - 1;
        used[v] ^= 1;
        vector < int > tmp;
        for (int i = 0; i < n; i++)
            if (used[i])
                tmp.pb(a[i]);
        //db(tmp.size();
        int sum = 0;
        for (int i = 0; i < (int)tmp.size(); i++)
            for (int j = i + 1; j < (int)tmp.size(); j++)
                sum += __gcd(tmp[i], tmp[j]) == 1; 
        answer.pb(sum);
    } 
    return answer; 

}

void printTest() {
    cerr << n << " " << q << endl;
    for (int i = 0; i < n; i++)
        cerr << a[i] << " ";
    cerr << endl;
    for (int i = 0; i < q; i++)
        cerr << query[i] << endl;
}

void stress() {
    for (int tt = 0; ; tt++) {
        cerr << "test id: " << tt << endl;
        q = n = 20;
        int T = 1000;
        query.resize(q);
        for (int i = 0; i < n; i++)
            a[i] = rand() % T + 1;
        for (int i = 0; i < q; i++)
            query[i] = rand() % n + 1; 
        auto r1 = solve();
        auto r2 = stupid();
        printTest();
        cerr << "res\n";
        for (auto x: r1)
            cerr << x << " ";
        cerr << endl;
        for (auto x: r2)
            cerr << x << " ";
        cerr << endl;
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
            auto r = solve();
            //auto r = stupid();
            for (auto x: r)
                cout << x << "\n";
            printAns();
        }
    }
    else {
        stress();
    }

    return 0;
}
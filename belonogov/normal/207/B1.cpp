#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <queue>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)
const int maxn = 25e4 + 10;
const int inf = 1e9;
const int maxLog = 20;

struct Tree {
    vector < pair < int, int > > val;
    int sz;
    Tree() {
    }
    void init(int * b, int n) {
        sz = n;
        val.resize(sz * 4); 
        init2(0, 0, sz, b);
    }
    void init2(int v, int ll, int rr, int * b) {
        if (ll + 1 == rr) {
            val[v] = mp(b[ll], ll);
            return; 
        }
        init2(v * 2 + 1, ll, (ll + rr) / 2, b);
        init2(v * 2 + 2, (ll + rr) / 2, rr, b);
        val[v] = min(val[v * 2 + 1], val[v * 2 + 2]);
    }
    pair < int, int > getMin(int l, int r) {
        return getMin2(0, 0, sz, l, r);
    }
    pair < int, int > getMin2(int v, int ll, int rr, int l, int r) {
        if (ll >= r || l >= rr) 
            return mp(inf, -1);
        if (l <= ll && rr <= r)
            return val[v];
        return min(getMin2(v * 2 + 1, ll, (ll + rr) / 2, l, r), 
                    getMin2(v * 2 + 2, (ll + rr) / 2, rr, l, r));
    }
};

int a[maxn];
int b[maxn];
int go[maxn];
int jump[maxLog][maxn];
int sumJump[maxLog][maxn];
int n;
Tree t;

void printPair(pair < int, int > p) {
    printf("< %d, %d > \n", p.fr, p.sc);
}

//void stupid() {
    //int q[100];
    //for (int i = n - 1; i >= 0; i--) {
        //pos = i;
        //maxLeft = inf;
        //where = -1;
        //cnt = 0;
        //sum = 0;
        //for (int 
        //for (;;) {
            //for (int j = 1; j <= a[pos]; j++) {
                //k = pos - j;
                //d = 0;
                //if (k < 0) {
                    //d = n;
                    //k += n;
                //}
                //if (a[k] - d < maxLeft) {
                    //maxLeft = a[k] - d;
                    //where = j;
                //} 
            //}
            //cnt++;
        //}
    //}
//}

long long solve() {
    int cnt, sum, pos;
    long long answer = 0;
    pair < int, int > r1, r2;
    //scanf("%d", &n);
    //for (int i = 0; i < n; i++)
        //scanf("%d", &a[i]);
    //for (int i = 0; i < n; i++)
        //a[i] = min(a[i], n - 1);

    for (int i = 0; i < n; i++)
        b[i] = i - a[i];
    t.init(b, n); 
    //cerr << "    ";
    //for (int i = 0; i < n; i++)
        //cerr << i << " ";
    //cerr << endl;
    //cerr << "b:  ";
    //for (int i = 0; i < n; i++)
        //cerr << b[i] << " ";
    //cerr << endl;
    for (int i = 0; i < n; i++) {
        //cerr << "calc go for: " << i << endl;
        if (b[i] >= 0)
            go[i] = t.getMin(b[i], i).sc;
        else {
            r1 = t.getMin(0, i);
            r2 = t.getMin(b[i] + n, n);
            r2.sc -= n;
            r2.fr -= n;
            //printPair(r1);
            //printPair(r2);
            go[i] = min(r1, r2).sc;
        }
    }
    for (int i = 0; i < maxLog; i++)
        for (int j = 0; j < n; j++) {
            if (i == 0) {
                jump[i][j] = (go[j] >= 0) ? go[j]: go[j] + n;
                sumJump[i][j] = j - go[j];
            }
            else {
                jump[i][j] = jump[i - 1][jump[i - 1][j]];
                sumJump[i][j] = sumJump[i - 1][j] + sumJump[i - 1][jump[i - 1][j]];
            }
        } 
    //cerr << "go: ";
    //for (int i = 0; i < n; i++)
        //cerr << ((go[i] < 0)? go[i] + n: go[i]) << " ";
    //cerr << endl;
    ////for (int i = 0; i < n; i++)
        ////cerr << i - go[i] << " ";
    ////cerr << endl;
    //////for (int i = 0; i < 6; i++, printf("\n"))
        ////for (int j = 0; j < n; j++)
            ////epr("%d ", jump[i][j]);
    ////epr("\n");
    ////for (int i = 0; i < 6; i++, printf("\n"))
        ////for (int j = 0; j < n; j++)
            ////epr("%d ", sumJump[i][j]);
    ////epr("\n");
    ////for (int i = 0; i < 6; i++, printf("\n"))
        ////for (int j = 0; j < n; j++)
            //epr("%d ", cntJump[i][j]);
    for (int i = n - 1; i >= 0; i--) {
        //cerr << a[i] << endl;
        sum = 0;
        pos = i;
        cnt = 0;
        for (int j = maxLog - 1; j >= 0; j--) {
            if (a[pos] + sum >= n - 1) {
                break;
            }
            if (sum + sumJump[j][pos] + a[jump[j][pos]] < n - 1) {
                cnt += (1 << j);
                sum += sumJump[j][pos];
                //cerr << "from : " << pos << " ";
                pos = jump[j][pos];
                //cerr << "    to: " << pos << " cost: " << (1 << j) << endl;
                //cerr << "sum: " << sum << endl;
        
            }
        }
        //cerr << "cnt: " << cnt << endl;
        if (a[pos] + sum < n - 1) {
            sum += sumJump[0][pos];
            pos = jump[0][pos];
            cnt++;
        }
        assert(sum + a[pos] >= n - 1); 
        if (sum < n - 1) 
            cnt++;
        if (cnt >= 2) {
            int tmp = cnt - 2;
            sum = 0;
            pos = i;
            for (int j = maxLog - 1; j >= 0; j--) {
                if (tmp >= (1 << j)) {
                    tmp -= (1 << j);
                    sum += sumJump[j][pos];
                    pos = jump[j][pos];
                }
            }
            if (sum + a[pos] >= n - 1)
                cnt--;
        }
        //cerr << "cnt: " << cnt << endl;
        answer += cnt;
    }
    return answer;
}

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
        a[i] = min(n - 1, a[i]);
}

void genTest() {
    n = 200;
    for (int i = 0; i < n; i++)
        a[i] = rand() % 20 + 1;
}

void printTest() {
    epr("%d\n", n);
    for (int i = 0; i < n; i++)
        epr("%d ", a[i]);
    epr("\n");
}

long long stupid() {
    int b[maxn];
    int answer = 0, k, newPos, pos, maxLeft;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            b[(i + j) % n] = a[j];
        pos = n - 1;
        //cerr << "new Step: " << endl;
        //for (int j = 0; j < n; j++)
            //cerr << b[j] << " ";
        //cerr /<< endl;
        for (;;) {
            if (b[pos] >= n - 1) {
                answer++;
                break;
            }
            maxLeft = inf;
            newPos = -1;
            for (int j = 1; j <= b[pos]; j++) {
                k = pos - j; 
                if (k - b[k] < maxLeft) {
                    maxLeft = k - b[k];
                    newPos = k;
                }
            }
            pos = newPos;
            //cerr << "pos : " << pos << endl; 
            answer++;
            if (pos - b[pos] <= 0) {
                answer++;
                break;
            }
        }
    }
    return answer;
}


void stress() {
    long long r1, r2;
    for (int tt = 0; tt < 100000; tt++) {
        cerr << "test id: " << tt << endl;
        genTest();
        r1 = stupid();
        r2 = solve();
        if (r1 != r2) {
            cerr << "r1 r2: " << r1 << " " << r2 << endl;
            printTest();
            exit(0);
        }
    }
}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (0)
        stress();
    else {
        read();
       cout << solve() << endl;
        //cout << stupid() << endl;
    }
    
    return 0;
}
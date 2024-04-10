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
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = 1e6 + 10;
const long long INF = 1e9 + 19;

struct Node {
    Node * next, * prev;
    Node * p;
    int type;
    int id;
    Node (): next(NULL), prev(NULL), p(NULL), type(0), id(-1) { }
};

int n, m, p;
char s[N];
char c[N];
Node * data[N];
Node * st[N];

void read() {
    scanf("%d%d%d", &n, &m, &p);
    scanf("%s", s);
    scanf("%s", c);
}

void solve() {
    for (int i = 0; i < n; i++)
        data[i] = new Node();
    for (int i = 0; i < n - 1; i++) {
        data[i]->next = data[i + 1];
        data[i + 1]->prev = data[i];
    }
    int cur = 0;
    for (int i = 0; i < n; i++) {
        data[i]->id = i;
        if (s[i] == '(') {
            st[cur++] = data[i];
            data[i]->type = 1;
        }
        else {
            assert(cur > 0);
            data[i]->p = st[cur - 1];
            st[cur - 1]->p = data[i];
            data[i]->type = -1;
            cur--;
        }
    }
    Node * v = data[p - 1]; 
    for (int i = 0; i < m; i++) {
        assert(v != NULL);
        //db(v->id);
        if (c[i] == 'L')
            v = v->prev;    
        else if (c[i] == 'R')
            v = v->next;
        else if (c[i] == 'D') {
            Node * u = v->p; 
            if (v->id > u->id) swap(v, u);        
            if (u->next != NULL) {
                Node * g = u->next;
                if (v->prev != NULL) {
                    Node * t = v->prev;
                    t->next = g;
                    g->prev = t;
                }
                else
                    g->prev = NULL;
                v = g;
            }
            else {
                assert(v->prev != NULL);
                v = v->prev;
                v->next = NULL;
            }
        }
        else
            assert(false);
    }

    for (; v->prev != NULL; v = v->prev);
    //db(v->id);

    for (; v != NULL; v = v->next)
        if (v->type == 1)
            printf("(");
        else
            printf(")");
    puts("");

}

void stress() {

}


int main(){
#ifdef MY_DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        int k = 1;
        for (int tt = 0; tt < k; tt++) {
            read();
            solve();
        }
    }
    else {
        stress();
    }

    return 0;
}
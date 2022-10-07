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
const int N = 1e6 + 10;
const long long INF = 1e9 + 19;

struct Node {
    Node *l, *r;
    int y, pos, cnt;
    Node() {
        y = rand();
        pos = -1;
        cnt = 1;
        l = NULL;
        r = NULL;
    }
};

int n, m;
Node data[N];
int curData = 0;
Node * empty;
int answer[N];
bool use[N];

Node * getNew() {
    curData++;
    return data + (curData - 1);
}

void upd(Node * v) {
    v->cnt = v->l->cnt + v->r->cnt + 1;
}




Node * merge(Node * l, Node * r) {
    assert(l != NULL && r != NULL);
    if (l == empty) return r;
    if (r == empty) return l;
    if (l->y > r->y) {
        l->r = merge(l->r, r);
        upd(l);
        return l;
    }
    else {
        r->l = merge(l, r->l);
        upd(r);
        return r;
    }
}

void split(Node * head, int cnt, Node * & l, Node * & r) {
    assert(head != NULL);
    if (head == empty) {
        l = r = empty;
        return;
    }
    if (head->l->cnt < cnt) {
        split(head->r, cnt - head->l->cnt - 1, head->r, r);
        upd(head);
        l = head;
    }
    else {
        split(head->l, cnt, l, head->l);
        upd(head);
        r = head;
    }
}


void read() {
    scanf("%d%d", &n, &m);
}

void solve() {
    empty = getNew(); 
    empty->cnt = 0;
    Node * head = empty;
    for (int i = 0; i < n; i++) {
        //db(i);
        Node * v = getNew();
        v->l = empty;
        v->r = empty;
        v->pos = i;
        head = merge(head, v);
    }
    //db("here");

    assert(head->cnt == n);
    memset(answer, -1, sizeof(answer));
    for (int i = 0; i < m; i++) {
        int x, y; 
        scanf("%d%d", &x, &y); x--; y--;
        Node * l, * r, * mid;
        split(head, y, l, r);
        split(r, 1, mid, r);
        assert(mid->cnt == 1);
        if (answer[mid->pos] == -1) {
            if (use[x]) {
                puts("-1");
                return;
            }
            use[x] = 1;
            answer[mid->pos] = x;
        }
        else {
            if (answer[mid->pos] != x) {
                puts("-1");
                return;
            }
        }
        head = merge(mid, merge(l, r));
    }
    //for (int i = 0; i < n; i++)
        //if (answer[i] != -1)
            //use[answer[i]] = 1;
    vector < int > tmp;
    for (int i = 0; i < n; i++)
        if (!use[i])
            tmp.pb(i);
    int cur = 0;
    for (int i = 0; i < n; i++)
        if (answer[i] == -1)
            answer[i] = tmp[cur++];
    assert(cur == (int)tmp.size());
    for (int i = 0; i < n; i++)
        printf("%d ", answer[i] + 1);
    puts("");

}

void stress() {

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
            solve();
        }
    }
    else {
        stress();
    }



    return 0;
}
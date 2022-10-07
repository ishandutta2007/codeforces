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
    char type;
    Node * l, * r;
    Node(char type, Node * l, Node * r): type(type), l(l), r(r) { }
};

char s[N];
int cur;

void read() {
    int t;
    scanf("%d", &t);
    scanf("%s", s);
}

Node * parseE();

Node * parseC() {
    if (s[cur] == '(') {
        cur++;
        Node * v = parseE();
        //db2(s[cur], cur);
        assert(s[cur] == ')');
        cur++;
        return v;
    }
    Node * v = new Node(s[cur], NULL, NULL);
    cur++;
    return v;
}

Node * parseB() {
    Node * v = parseC();
    while (s[cur] == '&') {
        cur++;
        Node * u = parseC();
        v = new Node('&', v, u);
    }
    return v;
}

Node * parseA() {
    Node * v = parseB();
    for (; s[cur] == '^';) {
        cur++;
        Node * u = parseB();
        v = new Node('^', v, u);
    }
    return v;
}

Node * parseE() {
    Node * v = parseA();
    for (; s[cur] == '|'; ) {
        cur++; 
        Node * u = parseA();
        v = new Node('|', v, u);
    }
    return v;
}

struct Res {
    bool rev, st0, st1;
    Res(bool rev, bool st0, bool st1): rev(rev), st0(st0), st1(st1) { }
    void Epr() {
        cerr << "rev 0 1: " << rev << " " << st0 << " " << st1 << endl;
    }
};

Res dfs(Node * v) {
    if (v->type == '&') {
        auto r1 = dfs(v->l);
        auto r2 = dfs(v->r);
        return Res((r1.rev && r2.rev) || (r1.rev && r2.st1) || (r1.st1 &&  r2.rev), 
                   //(r1.rev || r1.st0) && (r2.rev || r2.st0),
                   (r1.st0 || r2.st0 || (r1.rev && r2.rev)),
                   (r1.st1 && r2.st1));
    }
    if (v->type == '|') {
        auto r1 = dfs(v->l); 
        auto r2 = dfs(v->r);
        return Res((r1.rev && r2.rev) || (r1.rev && r2.st0) ||  (r1.st0 && r2.rev),
                   (r1.st0 && r2.st0),
                   //(r1.rev || r1.st1) && (r2.rev || r2.st1));
                   (r1.st1 || r2.st1 || (r1.rev && r2.rev)));                
    }
    if (v->type == '^') {
        auto r1 = dfs(v->l);
        auto r2 = dfs(v->r);
        return Res((r1.rev && (r2.st0 || r2.st1)) || (r2.rev && (r1.st0 || r1.st1)), 
                   (r1.st0 && r2.st0) || (r1.st1 && r2.st1) || (r1.rev && r2.rev),
                   (r1.st0 && r2.st1) || (r1.st1 && r2.st0) || (r1.rev && r2.rev));
    }
    if (v->type == '?') {
        return Res(1, 0, 0);
    }
    if (v->type == '0') {
        return Res(0, 1, 0);
    }
    if (v->type == '1') {
        return Res(0, 0, 1);
    }
    assert(false);
}


void solve() {
    Node * head = parseE();
    auto g = dfs(head);
    //g.Epr();

    if (g.rev)
        puts("YES");
    else
        puts("NO");

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
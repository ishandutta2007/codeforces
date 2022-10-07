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
const int N = -1;
const long long INF = 1e12 + 19;
const bool DEBUG_MOD = 0;

int n;


struct Rect {
    int x1, y1, x2, y2;
    Rect() { }
    Rect(int x1, int y1, int x2, int y2): x1(x1), y1(y1), x2(x2), y2(y2) { 
    }
    bool isValid() {
        return (x1 <= x2 && y1 <= y2);
    }
    void print() {
        cout << x1 << " " << y1 << " " << x2 << " " << y2;
    }
    long long getArea() {
        return (x2 - x1 + 1) * 1ll * (y2 - y1 + 1);
    }
    bool operator == (Rect rect) {
        return x1 == rect.x1 && y1 == rect.y1 && x2 == rect.x2 && y2 == rect.y2;
    }
    void read() {
        cin >> x1 >> y1 >> x2 >> y2;
    }
};

Rect key1, key2;

void read() {
    cin >> n;
    if (DEBUG_MOD) {
        key1.read();
        key2.read();
    }
}

int inside(Rect key, Rect b) {
    return b.x1 <= key.x1 && key.x2 <= b.x2 && b.y1 <= key.y1 && key.y2 <= b.y2;
}

int get(Rect rect) {
    if (DEBUG_MOD) {
        int answer = inside(key1, rect) + inside(key2, rect);          
        cerr << "Query: ";
        rect.print();
        cerr << "      answer: " << answer << endl;
        return answer;
    }
    else {
        cout << "? ";
        rect.print();
        cout << endl;
        int res;
        cin >> res;
        return res;
    }
}

int search1(int cnt) { // 1 or 2
    int l = 0;
    int r = n;
    while (r - l > 1) {
        if (get(Rect(1, 1, n, (l + r) / 2)) >= cnt)        
            r = (l + r) / 2;
        else
            l = (l + r) / 2;
    }
    return r;
}


int search2(int cnt) { // 1 or 2
    int l = 0;
    int r = n;
    while (r - l > 1) {
        if (get(Rect(1, 1, (l + r) / 2, n)) >= cnt)        
            r = (l + r) / 2;
        else
            l = (l + r) / 2;
    }
    return r;
}

int search3(int cnt) { // 1 or 2
    int l = 1;
    int r = n + 1;
    while (r - l > 1) {
        if (get(Rect(1, (l + r) / 2, n, n)) >= cnt)        
            l = (l + r) / 2;
        else
            r = (l + r) / 2;
    }
    return l;
}

int search4(int cnt) { // 1 or 2
    int l = 1;
    int r = n + 1;
    while (r - l > 1) {
        if (get(Rect((l + r) / 2, 1, n, n)) >= cnt)        
            l = (l + r) / 2;
        else
            r = (l + r) / 2;
    }
    return l;
}

vector < int > g[4];

void printAns(Rect res1, Rect res2) {
    if (DEBUG_MOD) {
        if ((key1 == res1 && key2 == res2) || (key1 == res2 && key2 == res1)) {
            cerr << "OK!" << endl;
        }
        else {
            cerr << "fail" << endl;
        }
    }
    else {
        cout << "! ";
        res1.print();
        cout << " ";
        res2.print();
        cout << endl;
    }
}

 
void solve() {
    g[0].pb(search1(1));
    g[0].pb(search1(2));

    g[1].pb(search2(1));
    g[1].pb(search2(2));

    g[2].pb(search3(1));
    g[2].pb(search3(2));

    g[3].pb(search4(1));
    g[3].pb(search4(2));

    for (int i = 0; i < 4; i++, cerr << endl)
        for (int j = 0; j < 2; j++)
            cerr << g[i][j] << " ";

    Rect res1, res2;
    long long answer = INF;
    for (int mask = 0; mask < (1 << 4); mask++) {
        vector < int > a[2]; 
        for (int i = 0; i < 4; i++)
            if (((mask >> i) & 1) == 1) {
                a[0].pb(g[i][0]); 
                a[1].pb(g[i][1]); 
            }
            else {
                a[0].pb(g[i][1]); 
                a[1].pb(g[i][0]); 
            }
        Rect r1(a[0][3], a[0][2], a[0][1], a[0][0]);
        Rect r2(a[1][3], a[1][2], a[1][1], a[1][0]);
        if (!r1.isValid() || !r2.isValid())
            continue;
        if (get(r1) && get(r2)) {
            if (r1.getArea() + r2.getArea() < answer) {
                answer = r1.getArea() + r2.getArea();
                res1 = r1;
                res2 = r2;
            } 
        }

    }
    db(answer);
    printAns(res1, res2);
}

void stress() {

}


int main(){
#ifdef MY_DEBUG
    //freopen("in", "r", stdin);
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
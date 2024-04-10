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

#define F first
#define S second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))

#define equal equalll
#define less lesss
const int N = -1;
const long long INF = 1e9 + 19;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

int n, m;

void rotate(int x, int y, vector<pair<int,int>>& log, vector<string>& board) {
    log.pb(mp(x, y));
    if (board[x][y] == 'L') {
        assert(board[x][y + 1] == 'R');
        assert(board[x + 1][y] == 'L');
        assert(board[x + 1][y + 1] == 'R');
        board[x][y] = 'U';
        board[x][y + 1] = 'U';
        board[x + 1][y] = 'D';
        board[x + 1][y + 1] = 'D';
    } 
    else if (board[x][y] == 'U') {
        assert(board[x][y + 1] == 'U');
        assert(board[x + 1][y] == 'D');
        assert(board[x + 1][y + 1] == 'D');
        board[x][y] = 'L';
        board[x][y + 1] = 'R';
        board[x + 1][y] = 'L';
        board[x + 1][y + 1] = 'R';
    }
    else
        assert(false);

}

void print(vector<string> board) {
    cerr << endl;
    for (int i = 0; i < n; i++)
        cerr << board[i] << endl;
    cerr << endl;
}

void needVer(int x, int y, vector<pair<int,int>>& log, vector<string>& board);

void needHor(int x, int y, vector<pair<int,int>>& log, vector<string>& board) {
    //db3("hor", x, y);
    if (board[x][y] == 'L') 
        return;
    assert(board[x][y] == 'U');
    assert(y + 1 < m);
    assert(x + 1 < n);
    if (board[x][y + 1] == 'U') {
        rotate(x, y, log, board);
        return;
    }
    needVer(x, y + 1, log, board);
    rotate(x, y, log, board);
}

void needVer(int x, int y, vector<pair<int,int>>& log, vector<string>& board) {
    //db3("ver", x, y);
    if (board[x][y] == 'U') {
        return;
    }
    assert(board[x][y] == 'L');
    assert(y + 1 < m);
    assert(x + 1 < n);
    if (board[x + 1][y] == 'L') {
        rotate(x, y, log, board);
        return;
    }
    needHor(x + 1, y, log, board);
    rotate(x, y, log, board);
}



vector<pair<int,int>> solve(vector<string> board) {
    vector<pair<int,int>> log;
    if (m % 2 == 0) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j += 2)
                needHor(i, j, log, board);
    }
    else {
        assert(n % 2 == 0);
        //db("tut");
        for (int j = 0; j < m; j++)
            for (int i = 0; i < n; i += 2) {
                //db3("main", i, j);
                needVer(i, j, log, board);
                //print(board);
            }
    }
    return log;
}

int main(){
#ifdef HOME 
    freopen("in", "r", stdin);
#endif
    vector<string> a;
    vector<string> b;
    cin >> n >> m;
    a.resize(n);
    b.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    auto r1 = solve(a);
    auto r2 = solve(b);

    reverse(all(r2));
    r1.insert(r1.end(), all(r2));
    
    printf("%d\n", (int)r1.size());
    for (auto x: r1)
        printf("%d %d\n", x.F + 1, x.S + 1);



    return 0;
}
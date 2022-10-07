#include <bits/stdc++.h>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define getTime() cerr << (clock() * 1.0 / CLOCKS_PER_SEC) << endl
#define equal equalll
#define less lesss
const int N = 1e5 + 100;
const int INF = 1e9;
const long long MOD = 1e9 + 9;
const int dx[7] = {-2, -1, 1, 2, -1, 0, 1};
const int dy[7] = {0, 0, 0, 0, -1, -1, -1};

struct data {
    int cnt, id;
    data() { }
    data(int cnt, int id): cnt(cnt), id(id) { }
};

int n;
int x[N];
int y[N];
map < pair < int, int >, data > keep;
//map < pair < int, int >, int > cub;
set < pair < int, pair < int, int > > > q;
set < pair < int, int > > tmp;

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d%d", &x[i], &y[i]);
}

void check(int x, int y) {
    if (keep.count(mp(x, y)) == 0) return;

    int y1 = y + 1;
    bool flag = 1;
    for (int x1 = x - 1; x1 <= x + 1; x1++)
        if (keep.count(mp(x1, y1)) && keep[mp(x1, y1)].cnt == 1)
            flag = 0;

    int myId = keep[mp(x, y)].id;
    if (flag)
        q.insert(mp(myId, mp(x, y)));
    else
        q.erase(mp(myId, mp(x, y)));
}

void solve() {
    for (int i = 0; i < n; i++)
        tmp.insert(mp(x[i], y[i]));
    for (int i = 0; i < n; i++) {
        if (y[i] == 0)
            keep[mp(x[i], y[i])] = data(INF, i);
        else {
            int y1 = y[i] - 1;
            int cnt = 0;
            for (int x1 = x[i] - 1; x1 <= x[i] + 1; x1++)
                cnt += tmp.count(mp(x1, y1));
            keep[mp(x[i], y[i])] = data(cnt, i);
        }
    }
    tmp.clear();
    for (int i = 0; i < n; i++) {
        check(x[i], y[i]);
    } 

    long long answer = 0;
    for (int id = 0;!q.empty(); id++) {
        int x1, y1;
        int val;
        if (id % 2 == 0) {
            auto it = q.end(); it--;
            val = it->fr;
            x1 = it->sc.fr;
            y1 = it->sc.sc;
            q.erase(it);
            keep.erase(mp(x1, y1));
        }     
        else {
            val = q.begin()->fr;
            x1 = q.begin()->sc.fr;
            y1 = q.begin()->sc.sc;
            q.erase(q.begin());
            keep.erase(mp(x1, y1));
        }
        answer = (answer * n + val) % MOD;
        int y2 = y1 + 1;
        for (int x2 = x1 - 1; x2 <= x1 + 1; x2++) 
            if (keep.count(mp(x2, y2)) == 1) {
                keep[mp(x2, y2)].cnt--;
            }
        for (int i = 0; i < 7; i++)
            check(x1 + dx[i], y1 + dy[i]);
    }
    cout << answer << endl;
                //int r = keep[mp(x2, y2)].cnt;
                //assert(r >= 1);
                //if (r == 1) {
                    //int y3 = y2 - 1;  
                    //for (int x3 = x2 - 1; x3 <= x2 + 1; x3++) {
                        //if (keep.count(mp(x3, y3)) == 1) {
                            //q.erase(mp(keep[mp(x3, y3)].fr, mp(x3, y3)));
                        //}
                    //}
                //}
            //}
        //}

        //y2 = y1 - 1;
        //for (int x2 = x1 - 1; x2 <= x1 + 1; x2++) {
            //int y3 = y2 + 1;
            //bool flag = 1;

        //}
        //bool flag = 1; 
        //int y1 = y[i] + 1;
        //for (int x1 = x[i] - 1; x1 <= x[i] + 1; x1++) {
            //if (keep.count(mp(x1, y1)) == 1 && keep[mp(x1, y1)].cnt <= 1) {
                //assert(keep[mp(x1, y1)].cnt == 1);
                //flag = 0;
            //}
        //}
        //if (flag)
            //q.insert(mp(i, mp(x[i], y[i])));
}

void printAns() {

}

void stress() {

}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        while (true) {
            read();
            solve();
            printAns();
            return 0;
        }
    }
    else {
        stress();
    }

    return 0;
}
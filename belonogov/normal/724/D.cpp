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
#define sz(a) (int)a.size()

#define equal equalll
#define less lesss
const int N = 1e5 + 10;
const long long INF = 1e9 + 19;
typedef long long ll;
const int ALF = 26;

int m;
int n;
char s[N];
string res[ALF];
int cntCh[ALF];

void read() { 
    scanf("%d", &m);
    scanf("%s", s);
    n = strlen(s);
}

void solve() {
    for (int i = 0; i < n; i++)
        cntCh[s[i] - 'a']++;

    for (int j = 0; j < ALF; j++) {
        //j = 1;
        int cnt = 0;   
        bool flag = 1;
        
        for (int i = 0; i < n; ) {
            int cur = i;
            for (; i < n && (s[i] >= 'a' + j); i++);
             
            //db3(cur, i, flag);
            vector<int> pos;
            pos.pb(cur - 1);
            for (int t = cur; t < i; t++)
                if (s[t] == 'a' + j)
                    pos.pb(t);
            pos.pb(i);
            for (int t = 0; t + 1 < (int)pos.size(); t++)
                if (pos[t + 1] - pos[t] > m) {
                    flag = 0;  
                    break;
                }
            //db(pos.size());
            if (!flag)
                break;

            int prev = cur - 1;
            for (int t = 1; t + 1 < (int)pos.size(); t++) {
                if (pos[t + 1] - prev > m) {
                    cnt++;
                    prev = pos[t];
                }
            }


            for (; i < n && (s[i] < 'a' + j); i++);
        }
        //db2(flag, cnt);
        //exit(0);

        if (flag) {
            //db2(j, cnt);
            for (int t = 0; t < j; t++)
                for (int x = 0; x < cntCh[t]; x++)
                    res[j].pb('a' + t);
            for (int x = 0; x < cnt; x++)
                res[j].pb('a' + j);
        }
    }


    string answer;
    for (int j = 0; j < ALF; j++) {
        if (res[j].empty()) continue;
        if (answer.empty() || res[j] < answer)
            answer = res[j];
    }
    cout << answer << endl;
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
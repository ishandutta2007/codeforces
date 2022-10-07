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

char s[N];
char t[N];
int n;
string res;
int cnt[20];

bool flag = 0;

void read() {
    scanf("%s", s);
    scanf("%s", t);
}


void upd(string g) {
    if (flag == 0) {
        flag = 1;
        res = g;
    }
    else {
        if (g.size() > res.size() || res > g) {
            res = g;
        }
    }
}

void solve() {
    n = strlen(s);
    assert(n >= 2);
    if (n == 2) {
        int sum = (s[0] - '0') + (s[1] - '0');
        printf("%d\n", sum - 1);
        return;
    }
    for (int len = 1; len <= 7; len++) {
        int tmp = n - len;
        int curLen = 0;
        for (; tmp > 0; tmp /= 10, curLen++);
        if (curLen == len) {
            int l = strlen(t);             
            int type = 1;
            for (int j = 0; j < l; j++)
                if (t[0] != t[j]) {
                    type = (t[0] < t[j])? 2: 1;
                    break;
                }
            memset(cnt, 0, sizeof(cnt));
            for (int i = 0; i < n; i++)
                cnt[s[i] - '0']++;
            for (int i = 0; i < l; i++)
                cnt[t[i] - '0']--;
            tmp = n - len;
            for (; tmp > 0; tmp /= 10)
                cnt[tmp % 10]--;
            bool flag = 1;
            for (int i = 0; i < 10; i++)
                flag &= cnt[i] >= 0;

            //db("here");
           //db(pos);
            //for (int i = 0; i < 10; i++)
                //db2(i, cnt[i]);
            assert(flag);

            int pos = -1;
            for (int i = 1; i < 10; i++)
                if (cnt[i] > 0) {
                    pos = i;
                    break;
                }
            string h;
            //db2(pos, t[0] - '0');
            vector < int > cc(10);
            for (int i = 0; i < 10; i++)
                cc[i] = cnt[i];
            if (pos != -1) {
                assert(0 <= pos && pos < 10);
                h += '0' + pos;
                cnt[pos]--;
                for (int i = 0; i < 10; i++) {
                    if (t[0] - '0' == i && type == 1) {
                        for (int j = 0; j < l; j++)
                            h += t[j];
                    }
                    for (int j = 0; j < cnt[i]; j++)
                        h += '0' + i;
                    if (t[0] - '0' == i && type == 2) {
                        for (int j = 0; j < l; j++)
                            h += t[j];
                    }
                }
                //db(h);
                upd(h);
            }
            if (t[0] != '0') {
                h = "";
                for (int i = 0; i < l; i++)
                    h += t[i];
                for (int i = 0; i < 10; i++)
                    for (int j = 0; j < cc[i]; j++)
                        h += '0' + i;
                //db(h);
                upd(h);
            }

        }
    }
    assert(flag);
    cout << res << endl;
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
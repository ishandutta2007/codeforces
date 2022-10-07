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
#include <random>
#include <functional>

using namespace std;

#define F first
#define S second
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define dbv(a) cerr << #a << ": "; for (auto& xxxx: a) cerr << xxxx << " "; cerr << endl;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))
#define equal equalll
#define less lesss

typedef double dbl;
typedef long long ll;
const int N = -1;
const int INF = 1.01e9;
typedef vector<int> vi;


map<char,int> mp;
vector<char> alf;

void add(char ch) {
    //db(ch);
    mp[ch] = alf.size();
    alf.pb(ch);
}

int main(){
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    for (int i = 0; i < 26; i++) {
        add('a' + i);
    }
    for (int i = 0; i < 26; i++) {
        add('A' + i);
    }
    for (int i = 0; i < 10; i++) {
        add('0' + i);
    }
    int cur = 26 + 26 + 10;

    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> cnt(cur);
    for (auto ch: s) {
        cnt[mp[ch]]++;
    }
    int cntPair = 0;
    vector<pair<int,int>> pr;
    vector<int> alone;
    for (int i = 0; i < cur; i++) {
        pr.pb({cnt[i] / 2, i});
        cntPair += cnt[i] / 2;
        if (cnt[i] % 2 == 1) {
            alone.pb(i);
        }
    }

    for (int answer = 1; answer <= n; answer++) {
        if (n % answer != 0) continue;
        int len = n / answer;  
        int needPair = len / 2 * answer;
        if (cntPair >= needPair) {
            cout << answer << "\n"; 
            for (int i = 0; i < answer; i++) {
                int need = len / 2;
                vector<int> f;
                for (;need > 0; ) {
                    int x = min(need, pr.back().F);
                    need -= x;
                    pr.back().F -= x;
                    for (int j = 0; j < x; j++)  {
                        f.pb(pr.back().S);
                    }
                    if (pr.back().F == 0) {
                        pr.pop_back();
                    }
                }
                vector<int> word = f;
                if (len % 2 == 1) {
                    if (alone.empty()) {
                        for (;pr.back().F == 0; pr.pop_back());
                        pr.back().F--;
                        word.pb(pr.back().S);
                        alone.pb(pr.back().S);
                    }
                    else {
                        word.pb(alone.back());
                        alone.pop_back();
                    }
                }
                reverse(all(f));
                word.insert(word.end(), all(f));
                //db2(word.size(), len);
                assert((int)word.size() == len);

                for (auto x: word) {
                    cout << alf[x];
                }
                cout << " ";
            }
            cout << endl;
            return 0;
        }

    }  
    assert(false);



    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}
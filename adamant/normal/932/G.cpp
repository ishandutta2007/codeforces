#include <bits/stdc++.h>
 
using namespace std;
 
//#define int int64_t
#define link abaaalal
 
const int maxn = 1e6 + 42, sigma = 26;
int len[maxn], link[maxn], to[maxn][sigma];
int slink[maxn], diff[maxn], series_ans[maxn][2];
int sz, last, n;
char s[maxn];
 
void init() {
    memset(len, 0, sizeof(len));
    memset(s, 0, sizeof(s));
    memset(slink, 0, sizeof(slink));
    memset(diff, 0, sizeof(diff));
    memset(series_ans, 0, sizeof(series_ans));
    memset(link, 0, sizeof(link));
    memset(to, 0, sizeof(to));
    s[n++] = -1;
    link[0] = 1;
    len[1] = -1;
    sz = 2;
}
 
int get_link(int v) {
    while(s[n - len[v] - 2] != s[n - 1]) v = link[v];
    return v;
}
 
void add_letter(char c) {
    s[n++] = c -= 'a';
    last = get_link(last);
    if(!to[last][c])
    {
        len[sz] = len[last] + 2;
        link[sz] = to[get_link(link[last])][c];
        diff[sz] = len[sz] - len[link[sz]];
        if(diff[sz] == diff[link[sz]])
            slink[sz] = slink[link[sz]];
        else
            slink[sz] = link[sz];
        to[last][c] = sz++;
    }
    last = to[last][c];
}

const int mod = 1e9 + 7;

int min_pal(string s) {
    init();
    int n = s.size();
    int ans[n + 1];
    memset(ans, 0, sizeof(ans));
    ans[0] = 1;
    int d[n + 1];
    memset(d, 0, sizeof(d));
    d[0] = 1;
    //cout << s << endl;
    for(int i = 1; i <= n; i++) {
        add_letter(s[i - 1]);
        for(int v = last; len[v] > 0; v = slink[v]) {
            int mn_len = len[slink[v]] + diff[v];
            series_ans[v][mn_len % 2] = ans[i - mn_len];
            series_ans[v][!(mn_len % 2)] = 0;
            //cout << v << "(" << len[v] << ") " << series_ans[v][0] << ' ' << series_ans[v][1] << endl;
            if(diff[v] == diff[link[v]]) {
                for(int z = 0; z <= 1; z++) {
                    series_ans[v][z] += series_ans[link[v]][z ^ (diff[v] % 2)];
                    series_ans[v][z] %= mod;
                }
            }
            ans[i] += series_ans[v][0];
            ans[i] %= mod;
            series_ans[v][0] %= mod;
            series_ans[v][1] %= mod;
            //cout << v << "(" << len[v] << ") " << series_ans[v][0] << ' ' << series_ans[v][1] << endl;
        }
        //for(int v = last; len[v] > 0; v = link[v]) {
        //    d[i] += (len[v] % 2 == 0) * d[i - len[v]];
        //    d[i] %= mod;
        //}
        //cout << ans[i] << ' ' << d[i] << endl;
        //assert(ans[i] == d[i]);
    }
    cout << ans[n] << ' ';
    
}

bool gen(string &s, int n) {
    s.clear();
    for(int i = 0; i < n / 2; i++) {
        s.push_back(char('a' + rand() % 2));
    }
    s += s;
    return true;
}

bool gen_fib(string &s, int n) {
    string a, b;
    gen(a, 5);
    gen(b, 3);
    while(b.size() < n) {
        b += a;
        swap(b, a);
    }
    while(b.size() > n) {
        b.pop_back();
    }
    s = b;
    return true;
}
 
signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string a, b;
    while(cin >> a) {
        b = string(a.rbegin(), a.rend());
        string c;
        for(int i = 0; i < a.size() / 2; i++) {
            c += a[i];
            c += b[i];
        }
        min_pal(c);
        break;
    }
    return 0;
}
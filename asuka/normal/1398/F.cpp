#include <bits/stdc++.h>

using namespace std;

const int N = int(1e6) + 99;
const int INF = int(1e9) + 99;

int n;
string s;
vector <int> p[2][N];
int nxt[2][N];
int ptr[2];
char buf[N];

int main(){
    cin >> n >> s;
    
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] != '0') nxt[0][i] = 1 + nxt[0][i + 1];
        if (s[i] != '1') nxt[1][i] = 1 + nxt[1][i + 1];
    }
    
    for (int b = 0; b <= 1; ++b) {
        int l = 0;
        while (l < n) {
            if (s[l] == char('0' + b)) {
                ++l;
                continue;
            }
            int r = l + 1;
            while (r < n && s[r] != char('0' + b)) ++r;
            for (int len = 1; len <= r - l; ++len)
                p[b][len].push_back(l);
            l = r;
        }
    }

    for (int len = 1; len <= n; ++len) {
        int pos = 0, res = 0;
        ptr[0] = ptr[1] = 0;
        
        while (pos < n) {
            int npos = INF;
            for (int b = 0; b <= 1; ++b) {
                if (nxt[b][pos] >= len) 
                   npos = min(npos, pos + len);
                while (ptr[b] < p[b][len].size() && pos > p[b][len][ ptr[b] ]) 
                    ++ptr[b];
                if (ptr[b] < p[b][len].size()) 
                    npos = min(npos, p[b][len][ ptr[b] ] + len);
            }
            if (npos != INF) 
                ++res;
            pos = npos;
        }
        
        cout << res << ' ';
    }
    cout << endl;
    
    return 0;
}
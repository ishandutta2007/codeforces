#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fc first
#define sc second
#define ll long long
#define forn(i, n) for (int i = 0; i < (int) (n); i++)
#define fort(i, j, n) for (int i = j; i < (int) (n); i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define bit(x) __builtin_popcount(x)

string t[] = {"S", "M", "L", "XL", "XXL", "XXXL"};
string g = "";
const int N = (int) 1e6 + 7;
bool good[N];
int cnt[N];
string res[N];
char c[7];

int ind(string s) {
    for (int i = 0; i < 6; i++) if (t[i] == s) return i;
}
bool cp(string a, string b) {
    int ina = 0, inb = 0;
    for (int i = 0; i < 6; i++) {
        if (t[i] == a) ina = i;
        if (t[i] == b) inb = i;
    }
    return ina < inb;
}


string next() {
    scanf(" %s", c);
    return string(c);
}

bool cmp(pair <pair <string, string>, int> a, pair <pair <string, string>, int> b) {
    if (a.fc.fc != b.fc.fc) return cp(a.fc.fc, b.fc.fc);
    else if (a.fc.sc != b.fc.sc) return cp(a.fc.sc, b.fc.sc);
    else return (a.sc < b.sc);
}

int main() {
    #ifdef ONPC
        freopen("a.in", "r", stdin);
        freopen("a.out", "w", stdout);
    #else
        //
        //
    #endif
    for (int i = 0; i < 6; i++) {
        scanf("%d", &cnt[i]);
    }
    int n;
    scanf("%d", &n);
    vector <pair <pair <string, string>, int> > go;
    for (int i = 0; i < n; i++) {
        string s = next();
        if (s.find(",") == string::npos) {
            cnt[ind(s)]--;
            res[i] = s;
        } else {
            string a = "";
            int j = 0;
            for (j = 0; s[j] != ','; j++) {
                a += s[j];
            }
            string b = "";
            j++;
            for (; j < (int) s.size(); j++) {
                b += s[j];
            }
            if (cp(b, a)) swap(b, a);
            go.pb({{a, b}, i});
        }
    }
    sort(go.begin(), go.end(), cmp);
    for (int i = 0; i < (int) go.size(); i++) {
        int g = ind(go[i].fc.fc);
        if (cnt[g] > 0) {
            cnt[g]--;
            res[go[i].sc] = t[g];
        } else {
            cnt[g + 1]--;
            res[go[i].sc] = t[g + 1];
        }
    }
    for (int i = 0; i < 6; i++) {
        if (cnt[i] < 0) {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    for (int i = 0; i < n; i++) {
        puts(res[i].c_str());
    }
}
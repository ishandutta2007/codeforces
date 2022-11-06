#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

const int limit = 20;

struct expr {
    int table;
    string s;

    bool operator<(const expr& who) const {
        if (s.empty()) return false;
        if (who.s.empty()) return false;

        if (s.size() < who.s.size()) return true;
        if (s.size() > who.s.size()) return false;
        return mp(s, table) < mp(who.s, table);
    }

    bool operator==(const expr& who) const {
        if (s != who.s) return false;
        return true;
    }
};

vector<expr> E, T, F;
expr best[1 << 8];
int need;
bool us[1 << 8];
int n, i, j, x;
char s[22];
bool any;

vector<string> bb = {"!x&x","!(x|y|z)","!x&!y&z","!x&!y","!x&!z&y","!x&!z","!(!y&!z|x|y&z)","!(x|y&z)","!x&y&z","!(!y&z|!z&y|x)","!x&z","!(!z&y|x)","!x&y","!(!y&z|x)","!x&(y|z)","!x","!y&!z&x","!y&!z","!(!x&!z|x&z|y)","!(x&z|y)","!(!x&!y|x&y|z)","!(x&y|z)","!(!x&!y|x&y|z)|!x&!y&z","!((x|y)&z|x&y)","!x&y&z|!y&!z&x","!x&y&z|!y&!z","!x&z|!y&!z&x","!x&z|!y&!z","!x&y|!y&!z&x","!x&y|!y&!z","!x&(y|z)|!y&!z&x","!x|!y&!z","!y&x&z","!(!x&z|!z&x|y)","!y&z","!(!z&x|y)","!x&!z&y|!y&x&z","!x&!z|!y&x&z","!x&!z&y|!y&z","!x&!z|!y&z","!x&y&z|!y&x&z","!(!x&z|!z&x|y)|!x&y&z","!(x&y)&z","!(!z&x|y)|!x&z","!x&y|!y&x&z","!(!y&z|x)|!y&x&z","!x&y|!y&z","!x|!y&z","!y&x","!(!x&z|y)","!y&(x|z)","!y","!x&!z&y|!y&x","!x&!z|!y&x","!x&!z&y|!y&(x|z)","!x&!z|!y","!x&y&z|!y&x","!(!x&z|y)|!x&y&z","!x&z|!y&x","!x&z|!y","!x&y|!y&x","!(!x&!y&z|x&y)","!x&(y|z)|!y&x","!x|!y","!z&x&y","!(!x&y|!y&x|z)","!x&!y&z|!z&x&y","!x&!y|!z&x&y","!z&y","!(!y&x|z)","!x&!y&z|!z&y","!x&!y|!z&y","!x&y&z|!z&x&y","!(!x&y|!y&x|z)|!x&y&z","!x&z|!z&x&y","!(!z&y|x)|!z&x&y","!(x&z)&y","!(!y&x|z)|!x&y","!x&z|!z&y","!x|!z&y","!z&x","!(!x&y|z)","!x&!y&z|!z&x","!x&!y|!z&x","!z&(x|y)","!z","!x&!y&z|!z&(x|y)","!x&!y|!z","!x&y&z|!z&x","!(!x&y|z)|!x&y&z","!x&z|!z&x","!(!x&!z&y|x&z)","!x&y|!z&x","!x&y|!z","!x&(y|z)|!z&x","!x|!z","!y&x&z|!z&x&y","!(!x&y|!y&x|z)|!y&x&z","!y&z|!z&x&y","!(!z&x|y)|!z&x&y","!y&x&z|!z&y","!(!y&x|z)|!y&x&z","!y&z|!z&y","!(!y&!z&x|y&z)","!x&y&z|!y&x&z|!z&x&y","!(!x&y|!y&x|z)|!x&y&z|!y&x&z","!(x&y)&z|!z&x&y","!(!z&x|y)|!x&z|!z&x&y","!(x&z)&y|!y&x&z","!(!y&x|z)|!x&y|!y&x&z","!(x&y)&z|!z&y","!x|!y&z|!z&y","!(y&z)&x","!(!x&y|z)|!y&x","!y&z|!z&x","!y|!z&x","!y&x|!z&y","!y&x|!z","!y&(x|z)|!z&y","!y|!z","!(y&z)&x|!x&y&z","!(!x&y|z)|!x&y&z|!y&x","!(x&y)&z|!z&x","!x&z|!y|!z&x","!(x&z)&y|!y&x","!x&y|!y&x|!z","!x&y|!y&z|!z&x","!(x&y&z)","x&y&z","!(x|y|z)|x&y&z","!x&!y&z|x&y&z","!x&!y|x&y&z","!x&!z&y|x&y&z","!x&!z|x&y&z","!(!y&!z|x|y&z)|x&y&z","!(x|y&z)|x&y&z","y&z","!(x|y|z)|y&z","!x&z|y&z","!x&!y|y&z","!x&y|y&z","!x&!z|y&z","!x&(y|z)|y&z","!x|y&z","!y&!z&x|x&y&z","!y&!z|x&y&z","!(!x&!z|x&z|y)|x&y&z","!(x&z|y)|x&y&z","!(!x&!y|x&y|z)|x&y&z","!(x&y|z)|x&y&z","!(!x&!y|x&y|z)|!x&!y&z|x&y&z","!((x|y)&z|x&y)|x&y&z","!y&!z&x|y&z","!y&!z|y&z","!x&z|!y&!z&x|y&z","!(x&z|y)|y&z","!x&y|!y&!z&x|y&z","!(x&y|z)|y&z","!x&(y|z)|!y&!z&x|y&z","!x|!y&!z|y&z","x&z","!(x|y|z)|x&z","!y&z|x&z","!x&!y|x&z","!x&!z&y|x&z","!x&!z|x&z","!x&!z&y|!y&z|x&z","!(x|y&z)|x&z","(x|y)&z","!(x|y|z)|(x|y)&z","z","!x&!y|z","!x&y|x&z","!(!y&z|x)|x&z","!x&y|z","!x|z","!y&x|x&z","!y&!z|x&z","!y&(x|z)|x&z","!y|x&z","!x&!z&y|!y&x|x&z","!(x&y|z)|x&z","!x&!z&y|!y&(x|z)|x&z","!x&!z|!y|x&z","!y&x|y&z","!(!x&z|y)|y&z","!y&x|z","!y|z","!x&y|!y&x|x&z","!x&!z|!y&x|y&z","!x&y|!y&x|z","!x|!y|z","x&y","!(x|y|z)|x&y","!x&!y&z|x&y","!x&!y|x&y","!z&y|x&y","!x&!z|x&y","!x&!y&z|!z&y|x&y","!(x|y&z)|x&y","(x|z)&y","!(x|y|z)|(x|z)&y","!x&z|x&y","!(!z&y|x)|x&y","y","!x&!z|y","!x&z|y","!x|y","!z&x|x&y","!y&!z|x&y","!x&!y&z|!z&x|x&y","!(x&z|y)|x&y","!z&(x|y)|x&y","!z|x&y","!x&!y&z|!z&(x|y)|x&y","!x&!y|!z|x&y","!z&x|y&z","!(!x&y|z)|y&z","!x&z|!z&x|x&y","!x&!y|!z&x|y&z","!z&x|y","!z|y","!x&z|!z&x|y","!x|!z|y","(y|z)&x","!(x|y|z)|(y|z)&x","!y&z|x&y","!(!z&x|y)|x&y","!z&y|x&z","!(!y&x|z)|x&z","!y&z|!z&y|x&y","!x&!y|!z&y|x&z","(x|y)&z|x&y","!(x|y|z)|(x|y)&z|x&y","x&y|z","!x&!y|x&y|z","x&z|y","!x&!z|x&z|y","y|z","!x|y|z","x","!y&!z|x","!y&z|x","!y|x","!z&y|x","!z|x","!y&z|!z&y|x","!y|!z|x","x|y&z","!y&!z|x|y&z","x|z","!y|x|z","x|y","!z|x|y","x|y|z","!x|x"};


bool add_to(expr e) {
    if (best[e.table].s.empty()) {
        need--;
        best[e.table] = e;
        //cerr << need << '\n';
        any = true;
        return true;
    } else {
        if (e < best[e.table]) {
            best[e.table] = e;
            any = true;
            return true;
        }
        return false;
    }
}

void clean_up(vector<expr>& data) {
    vector<expr> aux = data;
    data.clear();

    for (auto e : aux) us[e.table] = true;
    for (auto e : aux) {
        if (us[e.table]) {
            us[e.table] = false;
            data.pb(e);
        }
    }
}

void pre() {
    int i, cnt;
    vector<expr> aux;
    expr act;

    need = 256;

    F = {(expr){256 - 16, "x"},
         (expr){4 + 8 + 64 + 128, "y"},
         (expr){2 + 8 + 32 + 128, "z"}};

    for (auto e : F) add_to(e);

    cnt = 0;
    any = true;
    while (need > 0 || any || cnt <= 100) {
        cerr << ++cnt << ' ' << any << '\n';
        any = false;

        aux.clear();
        for (auto e1 : T) {
            aux.pb(e1);
            for (auto e2 : E) {
                act.s = e1.s + "|" + e2.s;
                act.table = e1.table | e2.table;

                add_to(act);
                aux.pb(act);
            }
        }
        for (auto e : aux)
            if (e.s.size() < limit)
                E.pb(e);

        sort(E.begin(), E.end());
        E.resize((unique(E.begin(), E.end())) - E.begin());

        aux.clear();
        for (auto e1 : F) {
            aux.pb(e1);
            for (auto e2 : T) {
                act.s = e1.s + "&" + e2.s;
                act.table = e1.table & e2.table;

                add_to(act);
                aux.pb(act);
            }
        }
        for (auto e : aux)
            if (e.s.size() < limit)
                T.pb(e);

        sort(T.begin(), T.end());
        T.resize((unique(T.begin(), T.end())) - T.begin());

        aux.clear();
        for (auto e1 : F) {
            act.s = "!" + e1.s;
            act.table = e1.table ^ (255);

            add_to(act);
            aux.pb(act);
        }

        for (auto e1 : E) {
            act.s = "(" + e1.s + ")";
            act.table = e1.table;

            add_to(act);
            aux.pb(act);
        }
        for (auto e : aux)
            if (e.s.size() < limit)
                F.pb(e);

        sort(F.begin(), F.end());
        F.resize((unique(F.begin(), F.end())) - F.begin());

        clean_up(E);
        clean_up(F);
        clean_up(T);

    }

    cout << '{';
    for (i = 0; i < 256; i++)
        cout << "\"" << best[i].s << "\"" << ",";
    cout << "}";
}

int main()
{
    //freopen("test.in","r",stdin);
    //freopen("test.out", "w", stdout);

    //pre();
    //return 0;

    scanf("%d\n", &n);
    for (i = 1; i <= n; i++) {
        scanf("%s\n", s);

        x = 0;
        for (j = 0; j < 8; j++)
            x += (1 << j) * (s[j] - '0');

        //cout << best[x].s << '\n';
        cout << bb[x] << '\n';
    }

    return 0;
}
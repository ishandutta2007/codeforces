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

#define maxN 100011

struct tp {
    int s, h;
    int id;

    bool operator<(const tp& who)const {
        return 1LL * s * who.h > 1LL * h * who.s;
    }
};

int n, i;
string s;
vector<tp> ord;
tp aux;
ll ans;

void add_string(int id) {
    int i;
    tp aux = {0, 0, id};

    for (auto e : s) {
        if (e == 's') {
            aux.s++;
        } else {
            aux.h++;
            ans += aux.s;
        }
    }

    ord.pb(aux);
}

int main()
{
    //freopen("test.in","r",stdin);

    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> s;
        add_string(i);
    }

    sort(ord.begin(), ord.end());

    aux = {0, 0, 0};
    for (auto e : ord) {
        ans += 1LL * aux.s * e.h;
        aux.s += e.s;
        aux.h += e.h;
    }

    cout << ans;

    return 0;
}
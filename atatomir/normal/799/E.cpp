#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 200011

class Buffer {
    public:
        Buffer(string name, int _dim) {
            if (name != "")
                freopen(name.c_str(), "r", stdin);
            dim = _dim;
            data.resize(dim + 11);
            refill();
        }

        template<typename T>
        Buffer& operator>>(T &dest) {
            T sign = +1;
            dest = 0;

            while (!is_digit(data[pos]) && data[pos] != '-')
                if (++pos == dim)
                    refill();

            if (data[pos] == '-') {
                sign = -1;
                if (++pos == dim)
                    refill();
            }

            while (is_digit(data[pos])) {
                dest = dest * 10 + data[pos] - '0';
                if (++pos == dim)
                    refill();
            }

            dest *= sign;
            return *this;
        }


    private:
        int pos, dim;
        vector<char> data;

        bool is_digit(char c) {
            return '0' <= c && c <= '9';
        }

        void refill() {
            memset(&data[0], 0, dim);
            fread(&data[0], 1, dim, stdin);
            pos = 0;
        }
};

int n, m, k, i, cnt, x, cnt2, zz;
int cost[maxN];
int who[maxN];

vector<int> none, one, two, both;
int pone, ptwo, pboth;
priority_queue<ll> H;
priority_queue<ll, vector<ll>, greater<ll> > rez;
ll in_heap;
ll ans = 1LL << 60;
ll aux;

void add_element(int x) {
    if (rez.empty()) {
        H.push(x);
        in_heap += x; zz++;
        return;
    }

    if (x <= rez.top()) {
        H.push(x);
        in_heap += x; zz++;
        return;
    }

    rez.push(x);
}

int main()
{
    //freopen("test.in","r",stdin);

    Buffer fin("", 1 << 20);

    fin >> n >> m >> k;
    for (i = 1; i <= n; i++) fin >> cost[i];

    fin >> cnt;
    for (i = 1; i <= cnt; i++) fin >> x, who[x]++;

    fin >> cnt;
    for (i = 1; i <= cnt; i++) fin >> x, who[x] += 2;


    for (i = 1; i <= n; i++) {
        if (who[i] == 0) none.pb(cost[i]);
        if (who[i] == 1) one.pb(cost[i]);
        if (who[i] == 2) two.pb(cost[i]);
        if (who[i] == 3) both.pb(cost[i]);
    }


    sort(one.begin(), one.end());
    sort(two.begin(), two.end());
    sort(both.begin(), both.end());
    sort(none.begin(), none.end());

    for (auto e : none) H.push(e), in_heap += 1LL * e, zz++;

    pone = one.size() - 1;
    ptwo = two.size() - 1;

    for (auto e : one) aux += e;
    for (auto e : two) aux += e;

    for (pboth = 0; pboth <= both.size() && pboth <= m; pboth++) {
        int need = k - pboth;

        while (pone + 1 > need && pone >= 0) {
            add_element(one[pone]);
            aux -= one[pone];
            pone--;
        }

        while (ptwo + 1 > need && ptwo >= 0) {
            add_element(two[ptwo]);
            aux -= two[ptwo];
            ptwo--;
        }


        int need2 = m - pboth - (pone + 1) - (ptwo + 1);
        while (zz > max(0, need2)) {
            in_heap -= H.top();
            rez.push(H.top());
            H.pop();

            zz--;
        }

        while (zz < need2 && !rez.empty()) {
            in_heap += rez.top();
            H.push(rez.top());
            rez.pop();

            zz++;
        }

        if (pboth + pone + 1 >= k && pboth + ptwo + 1 >= k && pboth + pone + ptwo + 2 + zz == m)
            ans = min(ans, aux + in_heap);

        if (pboth < both.size()) aux += both[pboth];
    }

    if (ans == 1LL << 60) ans = -1;
    cout << ans;

    return 0;
}
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 50011
#define maxK 12

int k;

struct group {
    int lo[maxK], hi[maxK];
    int sz;

    group() {
        sz = 0;
        memset(lo, 0, sizeof(lo));
        memset(hi, 0, sizeof(hi));
    }

    group(int *from) {
        sz = 1;
        for (int i = 1; i <= k; i++)
            lo[i] = hi[i] = from[i];
    }

    bool operator<(const group who)const {
        for (int i = 1; i <= k; i++)
            if (hi[i] >= who.lo[i])
                return false;
        return true;
    }

    group operator+(const group who)const {
        group ans;
        for (int i = 1; i <= k; i++) {
            ans.lo[i] = min(lo[i], who.lo[i]);
            ans.hi[i] = max(hi[i], who.hi[i]);
        }
        ans.sz = sz + who.sz;
        return ans;
    }
};

int n, i, j;
set<group> S;
vector<group> to_erase;
group aux;
int act[maxK];

int main()
{
    //freopen("test.in","r",stdin);

    cin >> n >> k;

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= k; j++)
            cin >> act[j];

        aux = group(act);
        auto it1 = S.lower_bound(aux);
        auto it2 = S.upper_bound(aux);

        while (it1 != it2) {
            to_erase.pb(*it1);
            aux = aux + *it1;
            it1++;
        }

        for (auto e : to_erase)
            S.erase(e);

        to_erase.clear();
        S.insert(aux);

        auto it = S.end(); it--;
        cout << it->sz << '\n';
    }


    return 0;
}
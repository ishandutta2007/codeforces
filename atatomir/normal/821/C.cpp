#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 300011

int n, i, id, need;
char s[maxN];
set<int> fr;
vector<int> se;
int ans;

int get_last() {
    if (se.size()) return se.back();
    return *fr.begin();
}

void reorder() {
    ans++;

    for (auto e : se) fr.insert(e);
    se.clear();
}

void remove_last() {
    if (se.size()) {
        se.pop_back();
        return;
    }
    fr.erase(fr.begin());
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d\n", &n); need = 1;
    for (i = 1; i <= 2 * n; i++) {
        scanf("%s", s + 1);
        if (s[1] == 'a') {
            scanf("%d\n", &id);
            se.pb(id);
        } else {
            scanf("\n");
            if (get_last() != need)
                reorder();

            need++;
            remove_last();
        }
    }

    cout << ans;

    return 0;
}
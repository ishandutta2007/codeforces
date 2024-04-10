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

#define sigma 26

struct node {
    node* son[sigma];
    node* fail;
    int value;

    node() {
        memset(son, 0, sizeof(son));
        fail = NULL;
        value = 0;
    }
};

class aho_manager {
    public:
        int sz;

        void reset() {
            del_node(Head);
            Head = new node();
            sz = 0;
        }

        void add_string(char *s, int n, int val) {
            node* act = Head;
            sz += n;

            for (i = 0; i < n; i++) {
                int go = s[i] - 'a';

                if (act->son[go] == NULL)
                    act->son[go] = new node();
                act = act->son[go];
            }

            act->value += val;
        }

        void build_fail() {
            while (!Q.empty()) Q.pop();
            Q.push(Head);
            Head->fail = Head;

            while (!Q.empty()) {
                node* act = Q.front(); Q.pop();
                act->value += act->fail->value;

                for (int i = 0; i < sigma; i++) {
                    if (act->son[i] == NULL) continue;

                    act->son[i]->fail = (act == Head ? Head : next_node(act->fail, i));
                    Q.push(act->son[i]);
                }
            }
        }

        ll evaluate(char *s, int n) {
            ll ans = 0;
            node* act = Head;
            int i;

            for (i = 0; i < n; i++) {
                int go = s[i] - 'a';

                act = next_node(act, go);
                ans += 1LL * act->value;
            }

            return ans;
        }

    private:
        queue< node* > Q;
        node* Head;
        int i;

        void del_node(node* A) {
            if (A == NULL) return;

            for (int i = 0; i < sigma; i++)
                if (A->son[i] != NULL)
                    del_node(A->son[i]);
            delete A;
        }

        node* next_node(node* act, int go) {
            while (act != Head && act->son[go] == NULL)
                act = act->fail;
            if (act->son[go] != NULL) act = act->son[go];
            return act;
        }
};

#define maxN 300011

const int limit = sqrt(maxN);

int n, i, last, pos, dim;

int op[maxN];
pair<int, int> wh[maxN];
char s[maxN];

aho_manager Big, Small;
bool need = false;


void reset_big(int step) {
    last = step;
    Big.reset();
    Small.reset();

    for (int i = 1; i <= last; i++) {
        if (op[i] == 3) continue;

        Big.add_string(s + wh[i].first, wh[i].second, (op[i] == 1 ? +1 : -1));
    }

    Big.build_fail();
}

void reset_small(int step) {
    Small.reset();

    for (int i = last + 1; i <= step; i++) {
        if (op[i] == 3) continue;

        Small.add_string(s + wh[i].first, wh[i].second, (op[i] == 1 ? +1 : -1));
    }

    Small.build_fail();
}


int main()
{
    //freopen("test.in","r",stdin);

    last = 0;
    pos = 0;

    Big.reset();
    Small.reset();

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %s", &op[i], s + pos);
        dim = strlen(s + pos);
        wh[i] = mp(pos, dim);
        pos += dim;

        if (op[i] == 3) {
            if (need) {
                need = false;
                Small.sz += dim;

                if (Small.sz > limit)
                    reset_big(i);
                else
                    reset_small(i);
            }

            ll ans = Big.evaluate(s + wh[i].first, dim);
            ans += Small.evaluate(s + wh[i].first, dim);
            printf("%lld\n", ans);

            fflush(stdout);
        } else {
            need = true;
        }
    }


    return 0;
}
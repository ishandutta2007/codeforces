#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>

using namespace std;

struct treap{
    treap *l, *r;
    int v, s, y;
    treap(){
        l = r = NULL;
        s = 1;
        y = rand();
        v = -1;
    }
};

int size(treap *t){
    if (t == NULL)
        return 0;
    return t->s;
}

void upd(treap *t){
    if (t == NULL)
        return;
    t->s = 1 + size(t->l) + size(t->r);
}

treap * merge(treap *l, treap *r){
    if (l == NULL)
        return r;

    if (r == NULL)
        return l;

    if (l->y > r->y){
        l->r = merge(l->r, r);
        upd(l);
        return l;
    }

    if (l->y <= r->y){
        r->l = merge(l, r->l);
        upd(r);
        return r;
    }
}

void split(int c, treap *t, treap *&l, treap *&r){
    if (t == NULL){
        l = NULL;
        r = NULL;
        return;
    }


    if (size(t->l) + 1 <= c){
        split(c - size(t->l) - 1, t->r, t->r, r);
        l = t;
        upd(l);
    }
    else{
        split(c, t->l, l, t->l);
        r = t;
        upd(r);
    }
}

#define M 1000100

int n, m, x[M], y[M];
treap t[M];
treap *root = NULL;
bool bad, u[M];
vector<int> fr;

void read(void){
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i)
        scanf("%d%d", x + i, y + i);
}

void ini(void){
    for (int i = 0; i < n; ++i){
        root = merge(root, t + i);
        //cout << size(root) << "!\n";
    }

}

void kill(void){
    treap *f, *l, *r;

    for (int i = m - 1; i >= 0; --i){
        split(1, root, f, root);
        split(y[i] - 1, root, l, r);

        if (f->v == -1){
            if (u[x[i]]){
                bad = 1;
                break;
            }
            f->v = x[i];
        }

        u[x[i]] = 1;

        if (f->v != x[i]){
            bad = 1;
            break;
        }

        root = merge(l, merge(f, r));
    }

    if (bad){
        printf("-1\n");
        return;
    }

    for (int i = 1; i <= n; ++i)
    if (!u[i])
        fr.push_back(i);

    int k = 0;

    for (int i = 1; i <= n; ++i){
        split(1, root, f, root);
        if (f->v == -1)
            f->v = fr[k++];
        printf("%d ", f->v);
    }
}

int main(){
#ifdef GORILLA
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#else
#endif
    srand(34560);

    read();
    ini();
    kill();

    return 0;
}
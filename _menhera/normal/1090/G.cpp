#include<bits/stdc++.h>
using namespace std;

const int MAXN = 262144;

struct Node
{
    int s, e;
    Node *l, *r;
    int v;
    int findZero(int from) const
    {
        if(s==e) return v == 0 ? s: -1;
        if(e-s+1 == v) return -1;
        
        int m = (s+e)/2;
        if(from <= m)
        {
            if(l)
            {
                int x = l->findZero(from);
                if(x != -1)
                    return x;
            } else return from;

            if(r) return r->findZero(m+1);
            else return m+1;
        }
        else if(r) return r->findZero(from);
        else return from;
    };
    bool exists(int from) const
    {
        if(from == s) return v;

        int m = (s+e)/2;
        if(from <= m)
        {
            if(l && l->exists(from)) return 1;
            return r && r->exists(m+1);
        }
        else return r && r->exists(from);
    }
    void update()
    {
        v = 0;
        if(l) v += l->v;
        if(r) v += r->v;
    }
    Node* set0(int from, int to) const
    {
        // printf("%d %d %d %d\n", s, e, from, to);
        Node* ret = new Node(*this);
        if(s == e) return nullptr;
        int m = (s+e)/2;
        
        if(from <= s && m <= to) ret->l = nullptr;
        else if(from <= m) ret->l = ret->l->set0(from, min(to, m));
        
        if(from <= m+1 && e <= to) ret->r = nullptr;
        else if(m+1 <= to) ret->r = ret->r->set0(max(m+1, from), to);
        ret->update();
        return ret;
    }
    Node* set1(int idx) const
    {
        Node* ret = new Node(*this);
        if(s==e){ ret->v = 1; return ret;}
        int m = (s+e)/2;
        if(idx <= m)
        {
            if(!ret->l)
            {
                ret->l = new Node();
                ret->l->s = s; ret->l->e = m;
                ret->l->l = ret->l->r = nullptr;
                ret->l->v = 0;
            }
            ret->l = ret->l->set1(idx);
        }
        else
        {
            if(!ret->r)
            {
                ret->r = new Node();
                ret->r->s = m+1; ret->r->e = e;
                ret->r->l = ret->r->r = nullptr;
                ret->r->v = 0;
            }
            ret->r = ret->r->set1(idx);
        }
        ret->update();
        return ret;
    }
};


Node* deal(const Node* ptr, int a)
{
    int idx = ptr->findZero(a);
    assert(idx != -1);
    Node* res = ptr->set1(idx);
    if(a != idx) res = res->set0(a, idx-1);
    return res;
}

struct Mob
{
    int a, h;
    Node* dmg;
};

vector<Mob> V;
vector<int> ans;
int main()
{
    Node* ZERO = new Node();
    ZERO->s = 0; ZERO->e = 2*MAXN-1; ZERO->l = ZERO->r = nullptr; ZERO->v = 0;
    int Q; scanf("%d", &Q);
    for(int turn=1; turn <= Q; ++turn)
    {
        int t; scanf("%d", &t);
        if(t == 1)
        {
            Mob M; M.a = 0; M.h = MAXN-1; M.dmg = ZERO;
            V.push_back(M); ans.push_back(-1);
        }
        else if(t == 2)
        {
            int x; scanf("%d", &x); --x;
            V[x].a++;
        }
        else if(t == 3)
        {
            int x; scanf("%d", &x); --x;
            V[x].h--;
        }
        else if(t == 4)
        {
            int x; scanf("%d", &x); --x;
            V.push_back(V[x]);
            if(V.back().dmg == nullptr) ans.push_back(turn);
            else ans.push_back(-1);
        }
        else if(t == 5)
        {
            int a, b; scanf("%d%d", &a, &b); --a; --b;
            if(V[a].dmg == nullptr || V[b].dmg == nullptr) continue;
            V[a].dmg = deal(V[a].dmg, V[b].a+V[a].h);
            V[b].dmg = deal(V[b].dmg, V[a].a+V[b].h);
            if(V[a].dmg->exists(MAXN-1))
            {
                V[a].dmg = nullptr; ans[a] = turn;
            }
            if(V[b].dmg->exists(MAXN-1))
            {
                V[b].dmg = nullptr; ans[b] = turn;
            }
        }
        else assert(false);
    }
    printf("%d\n", (int)ans.size());
    for(auto x: ans) printf("%d ", x);
}
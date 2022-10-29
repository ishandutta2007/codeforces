#include<bits/stdc++.h>

using namespace std;

template <int N>
class SuffixAutomaton {
  struct State {
    int length;
    map<int, State*> next;
    void clearNext() { next.clear(); }
    bool hasNext(int c) { return next.count(c) > 0; }
    State* link;
  } state[2*N-1];
  State* last, *free;

  State* computeLink(State* p, int c) {
    State* q = p->next[c];
    if (p->length + 1 == q->length) return q;
    State* clone = free++;
    clone->length = p->length + 1;
    clone->next = q->next;
    clone->link = q->link;
    for (; p && p->next[c] == q; p = p->link) p->next[c] = clone;
    return q->link = clone;
  }

public:
  long long differentSubstrings = 0;

  void init() {
    last = state;
    free = last + 1;
    last->clearNext();
    last->length = 0;
    last->link = nullptr;
  }

  void addLetter(int c) {
    State* p = last;
    if (p->hasNext(c)) return void(last = computeLink(p, c));
    last = free++;
    last->clearNext();
    last->length = p->length + 1;
    for (; p && !p->hasNext(c); p = p->link) p->next[c] = last;
    last->link = p ? computeLink(p, c) : state;
    differentSubstrings += last->length - last->link->length;
  }

  int end() {
    int index = last - state;
    last = state;
    return index;
  }
};

const int N = 5e5+5;
int n;
char s[N];
SuffixAutomaton<N> sa;
vector<int> t[N];

int main() {
  scanf("%d%s", &n, s);
  sa.init();
  int l = 0;
  for (char* c = s; *c; ++c)
    if (*c == '(') ++l;
    else {
      for (int c : t[l]) sa.addLetter(c);
      int v = sa.end();
      t[l].clear();
      if (l > 0) t[--l].push_back(v);
    }
  for (; l >= 0; --l) {
    for (int c : t[l]) sa.addLetter(c);
    sa.end();
  }
  printf("%lld\n", sa.differentSubstrings);
  return 0;
}
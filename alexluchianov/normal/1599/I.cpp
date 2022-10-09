#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

int const inf = 1000000000;

class Splay{
  public:
    struct Node{
      int parent = 0;
      int ch[2] = {0, 0};
      int flip = 0;
      int val = 0, path = 0;
      int val2 = 0, path2 = 0;
      int lazy = 0;
    };
    std::vector<Node> T;

    Splay(int n) {
      T.resize(1 + n);
    }

    void push(int node) {
      if(0 == node || (0 == T[node].flip && 0 == T[node].lazy))
        return ;
      int x = T[node].ch[0];
      int y = T[node].ch[1];

      if(T[node].flip == 1) {
        std::swap(T[node].ch[0], T[node].ch[1]);
        T[x].flip ^= 1;
        T[y].flip ^= 1;
        T[node].flip = 0;
      }

      if(0 != T[node].lazy) {
        T[node].val += T[node].lazy; 
        T[node].path += T[node].lazy;

        if(0 < x)
          T[x].lazy += T[node].lazy;
        if(0 < y)
          T[y].lazy += T[node].lazy;
        T[node].lazy = 0;
      }
    }

    void pull(int node) {
      push(T[node].ch[0]);
      push(T[node].ch[1]);
      T[node].path = std::max(T[T[node].ch[0]].path, std::max(T[node].val, T[T[node].ch[1]].path));
      T[node].path2 = std::max(T[T[node].ch[0]].path2, std::max(T[node].val2, T[T[node].ch[1]].path2));
    }

    void set(int node, int side, int to) {
      T[node].ch[side] = to;
      T[to].parent = node;
      pull(node);
    }

    int get_side(int node) {
      int far = T[node].parent;
      if(far == 0)
        return -1;
      if(T[far].ch[0] == node)
        return 0;
      if(T[far].ch[1] == node)
        return 1;
      return -1;
    }

    void rotate(int node) {
      int far = T[node].parent;
      int far2 = T[far].parent;

      int side1 = get_side(node);
      int side2 = get_side(far);

      if(side1 == -1)
        return ;
      set(far, side1, T[node].ch[!side1]);
      set(node, !side1, far);
      if(side2 == -1) 
        T[node].parent = far2;
      else
        set(far2, side2, node);
    }

    void splay(int node) {
      while(0 < node) {
        int far = T[node].parent;
        int far2 = T[far].parent;
        push(far2);
        push(far);
        push(node);

        int side1 = get_side(node);
        int side2 = get_side(far);
        if(side1 == -1)
          return ;

        if(side1 == side2)
          rotate(far);
        else
          rotate(node);
        rotate(node);
      }
    }

    int scout(int node) {
      int far = T[node].parent;
      if(get_side(node) == -1) {
        push(node);
        return node;
      } else {
        int result = scout(far);
        push(node);
        return result;
      }
    }

    void _print() {
      std::cout << "Print\n";
      for(int i = 1;i < T.size(); i++) {
        std::cout << i << " " << T[i].parent << " " << T[i].ch[0] << " " << T[i].ch[1] << '\n';
        std::cout << T[i].val << " " << T[i].path << '\n';
        std::cout << T[i].val2 << " " << T[i].path2 << '\n';
        std::cout << '\n';
      }
    }

};

class LinkCutTree : Splay {
  public:
    LinkCutTree(int n) : Splay(n) {}

    void _scout(int node) {
      while(0 < node) {
        node = T[scout(node)].parent;
      }
    }

    int _access(int node) {
      int prev = 0;
      int orig = node;
      while(0 < node) {
        splay(node);
        set(node, 1, prev);
        prev = node;
        node = T[node].parent;
      }
      splay(orig);
      return prev;
    }

    int access(int node) {
      _scout(node);
      return _access(node);
    }

    void reroot(int root) {
      access(root);
      T[root].flip ^= 1;
      push(root);
    }

    void link(int x, int y) {
      access(x);
      reroot(y);
      T[y].parent = x;
    }

    void cut(int x, int y) {
      reroot(x);
      access(y);
      T[y].ch[0] = 0;
      T[x].parent = 0;
      pull(y);
    }

    void increment_path(int x, int y, int val) {
      reroot(x);
      access(y);
      T[y].lazy += val;
      push(y);
    }

    int get_lca(int x, int y) {
      access(x);
      int result = access(y);
      if(T[x].parent == 0)
        return -1;
      return result;
    }

    std::pair<int,int> query_path(int x, int y) {
      reroot(x);
      access(y);
      return {T[y].path, T[y].path2};
    }

    void force_set(int x, int val, int val2) {
      T[x].val = T[x].path = val;
      T[x].val2 = T[x].path2 = val2;
    }

    void print() {
      _print();
    }

};

using ll = long long;

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, m;
  std::cin >> n >> m;
  std::vector<std::pair<int,int>> edges(1 + m);
  std::vector<int> state(1 + m);

  LinkCutTree mst(n + m);

  for(int i = 1; i <= m; i++) {
    std::cin >> edges[i].first >> edges[i].second;
  }

  for(int i = 0; i <= n; i++)
    mst.force_set(i, -inf, -inf);
  for(int i = 1; i <= m; i++)
    mst.force_set(n + i, 0, -i);

  int ptr = 1;
  
  ll result = 0;

  for(int i = 1; i <= m; i++) {
    int id = -1;
    int x = edges[i].first, y = edges[i].second;
    state[i] = 2;

    if(mst.get_lca(x, y) == -1) {
      mst.link(x, i + n);
      mst.link(y, i + n);
    } else {

      while(mst.get_lca(x, y) != -1 && 0 < mst.query_path(x, y).first) {
        if(state[ptr] == 2) {
          mst.cut(edges[ptr].first, n + ptr);
          mst.cut(edges[ptr].second, n + ptr);
        } else {
          mst.increment_path(edges[ptr].first, edges[ptr].second, -1);
        }
        ptr++;
      }
      
      int id = -mst.query_path(x, y).second;
      bool makelater = false;
      if(mst.get_lca(x, y) != -1) {
        makelater = true;
        mst.cut(edges[id].first, n + id);
        mst.cut(edges[id].second, n + id);
        state[id] = 1;
      }
      mst.link(x, n + i);
      mst.link(y, n + i);
      if(makelater == true) {
        mst.increment_path(edges[id].first, edges[id].second, 1);
      }
    }
    result += i - ptr + 1;
  }
  
  std::cout << result << '\n';
  return 0;
}
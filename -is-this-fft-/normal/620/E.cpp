#include <iostream>
#include <vector>

const int MAX_V = 400005;
const char newl = '\n';

using namespace std;

class propa {
  long long* tree;
  long long* ovrwrt;
  int segsize, segstart, treeh;

  void propagate (int vertex) {
    if (ovrwrt[vertex] != 0) {
      tree[vertex] = ovrwrt[vertex];

      for (int i = vertex; i != 1; i >>= 1) {
	if (tree[i >> 1] != (tree[i] | tree[i ^ 1])) {
	  tree[i >> 1] = (tree[i] | tree[i ^ 1]);
	} else {
	  break;
	}
      }
 
      if (vertex < segstart) {
	ovrwrt[vertex << 1] = ovrwrt[vertex];
	ovrwrt[vertex << 1 ^ 1] = ovrwrt[vertex];
      }

      ovrwrt[vertex] = 0;
    }
  }

  int rstart (int vertex, int height) {
    return (vertex << height) - segstart;
  }

  int rend (int vertex, int height) {
    return rstart(vertex + 1, height) - 1;
  }

  void tset (int left, int right, int root, int height, long long val) {
    propagate(root);

    left = max(left, rstart(root, height));
    right = min(right, rend(root, height));

    if (left == rstart(root, height) && right == rend(root, height)) {
      ovrwrt[root] = val;
      propagate(root);
    } else if (left > right) {
      return;
    } else {
      tset(left, right, root << 1, height - 1, val);
      tset(left, right, root << 1 ^ 1, height - 1, val);
    }
  }

  long long tget (int left, int right, int root, int height) {
    propagate(root);

    left = max(left, rstart(root, height));
    right = min(right, rend(root, height));

    if (left == rstart(root, height) && right == rend(root, height)) {
      return tree[root];
    } else if (left > right) {
      return 0;
    } else {
      return (tget(left, right, root << 1, height - 1) |
	      tget(left, right, root << 1 ^ 1, height - 1));
    }
  }

public:
  propa (int s) {
    for (int i = 2; i < 25; ++i) {
      if (s < 1 << i) {
	segstart = 1 << i;
	segsize = segstart * 2;
	treeh = i;
	break;
      }
    }

    tree = new long long [segsize];
    for (int i = 0; i < segsize; ++i) {
      tree[i] = 0;
    }

    ovrwrt = new long long [segsize];
    for (int i = 0; i < segsize; ++i) {
      ovrwrt[i] = 0;
    }
  }

  void set (int left, int right, long long val) {
    tset(left, right, 1, treeh, val);
  }

  long long get (int left, int right) {
    return tget(left, right, 1, treeh);
  }

  void print_tree () {
    cout << "Size: " << segsize << ", height: " << treeh << endl;

    for (int i = 0; i <= treeh; i++) {
      for (int j = 1 << i; j < 1 << (i + 1); j++) {
	cout << tree[j] << " ";
      }
      cout << endl;
    }
    cout << endl;

    for (int i = 0; i <= treeh; i++) {
      for (int j = 1 << i; j < 1 << (i + 1); j++) {
	cout << ovrwrt[j] << " ";
      }
      cout << endl;
    }
  }
};

int bitc (long long bitmask) {
  int ans = 0;
  for (int i = 0; i < 64; ++i) {
    if (bitmask & 1LL << i) {
      ans++;
    }
  }
  
  return ans;
}

int bginx [MAX_V], endinx [MAX_V], cur;
vector<int> adj [MAX_V];
void traverse (int vertex, int parent) {
  ++cur;
  bginx[vertex] = cur;

  for (int i = 0; i < (int) adj[vertex].size(); ++i) {
    if (adj[vertex][i] != parent) {
      traverse(adj[vertex][i], vertex);
    }
  }

  endinx[vertex] = cur;
}

int initcol [MAX_V];

int main () {
  ios::sync_with_stdio(false);

  int verticec, queryc;
  cin >> verticec >> queryc;

  for (int i = 1; i <= verticec; ++i) {
    cin >> initcol[i];
  }

  for (int i = 0; i < verticec - 1; ++i) {
    int u, v;
    cin >> u >> v;
    
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  traverse(1, 0);
  
  propa nytree (verticec + 2);
  for (int i = 1; i <= verticec; ++i) {
    nytree.set(bginx[i], bginx[i], 1LL << initcol[i]);
  }
  // nytree.print_tree();

  for (int i = 0; i < queryc; ++i) {
    int query;
    cin >> query;
    
    if (query == 1) {
      int vertex, val;
      cin >> vertex >> val;
      nytree.set(bginx[vertex], endinx[vertex], 1LL << val);
      // nytree.print_tree();
    } else if (query == 2) {
      int vertex;
      cin >> vertex;
      // nytree.print_tree();
      cout << bitc(nytree.get(bginx[vertex], endinx[vertex])) << newl;
    }
  }
}
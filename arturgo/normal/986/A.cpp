#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <vector>
using namespace std;


template<typename Node, typename Map = map<Node, size_t> >
class directed_graph {
public:
  typedef Node node_type;
  
  Map r_nodes;
  vector<Node> nodes;
  vector<vector<size_t>> childs, parents;
  
  directed_graph();
  void add_node(const Node& node);
  void add_edge(const Node& begin, const Node& end);
  void add_edge_id(size_t begin, size_t end);
};


template<typename Node, typename Map = map<Node, size_t>>
class undirected_graph : public directed_graph<Node, Map> {
public:
  void add_edge(const Node &begin, const Node &end);
  void add_edge_id(size_t begin, size_t end);
};

template<typename ContainerOut, typename ContainerIn>
ContainerOut convert_container(const ContainerIn& container);


template<typename Map>
vector<vector<typename Map::value_type>> equivalency_classes(const Map& container);

template<typename Map, typename Table>
Map table_to_map(const Table &table);


template<typename Graph>
vector<int> distances_from_bfs(const Graph &graph, vector<size_t> node_ids);

template<typename Graph>
vector<int> distances_from_bfs(const Graph &graph, size_t node_id);

const int NOT_REACHABLE = -2000 * 1000 * 1000;


template<typename Container>
Container sorted(const Container &a);

template<typename ContainerOut, typename ContainerIn>
ContainerOut key_set(const ContainerIn& container);


vector<int> biens;
int dists[100 * 1000][100];

int main() {
  int nbVilles, nbRoutes, nbBiens, nbRequis;
  scanf("%d%d%d%d", &nbVilles, &nbRoutes, &nbBiens, &nbRequis);

  undirected_graph<int> pays;
  for(int iVille = 0;iVille < nbVilles;iVille++) {
    int bien;
    scanf("%d", &bien);
    biens.push_back(bien);
    pays.add_node(iVille);
  }
  
  for(int iRoute = 0;iRoute < nbRoutes;iRoute++) {
    int deb, fin;
    scanf("%d%d", &deb, &fin);
    deb--; fin--;
    pays.add_edge_id(deb, fin);
  }

  auto classes = equivalency_classes(table_to_map<vector<pair<int, int>>>(biens));

  int nbTypes = 0;
  for(vector<pair<int, int>> type : classes) {
    vector<int> dists_from = distances_from_bfs(pays, key_set<vector<size_t>>(type));
    for(int node : pays.nodes) {
      dists[node][nbTypes] = dists_from[node];
    }
    nbTypes++;
  }

  for(int node : pays.nodes) {
    int min_sum = 0;
    sort(dists[node], dists[node] + nbTypes);
    
    for(int ith = 0;ith < nbRequis;ith++) {
      min_sum += dists[node][ith];
    }

    printf("%d ", min_sum);
  }

  printf("\n");
  return 0;
}


template<typename Node, typename Map>
directed_graph<Node, Map>::directed_graph() {
}

template<typename Node, typename Map>
void directed_graph<Node, Map>::add_node(const Node& node) {
  r_nodes[node] = nodes.size();
  nodes.push_back(node);
  childs.push_back({});
  parents.push_back({});
}

template<typename Node, typename Map>
void directed_graph<Node, Map>::add_edge(const Node& begin, const Node& end) {
  add_edge_id(r_nodes[begin], r_nodes[end]);
}

template<typename Node, typename Map>
void directed_graph<Node, Map>::add_edge_id(size_t begin, size_t end) {
  childs[begin].push_back(end);
  parents[end].push_back(begin);
}

template<typename Node, typename Map>
void undirected_graph<Node, Map>::add_edge(const Node &begin, const Node &end) {
  add_edge_id(directed_graph<Node, Map>::r_nodes[begin], directed_graph<Node, Map>::r_nodes[end]);
}

template<typename Node, typename Map>
void undirected_graph<Node, Map>::add_edge_id(size_t begin, size_t end) {
  directed_graph<Node, Map>::childs[begin].push_back(end);
  directed_graph<Node, Map>::childs[end].push_back(begin);
  directed_graph<Node, Map>::parents[begin].push_back(end);
  directed_graph<Node, Map>::parents[end].push_back(begin);
}

template<typename ContainerOut, typename ContainerIn>
ContainerOut convert_container(const ContainerIn& container) {
  ContainerOut converted;
  for(auto elem : container) {
    inserter(converted, converted.end()) = elem;
  }
  return converted;
}

template<typename Map>
vector<vector<typename Map::value_type>> equivalency_classes(const Map& container) {
  auto pairs = convert_container<vector<typename Map::value_type>>(container);

  sort(pairs.begin(), pairs.end(), [](const typename Map::value_type& a, const typename Map::value_type &b) { return a.second < b.second; });

  vector<vector<typename Map::value_type>> res;

  for(auto p : pairs) {
    if(res.empty() || p.second != res.back().back().second) {
      res.push_back(vector<typename Map::value_type>());
    }
    res.back().push_back(p);
  }

  return res;
}

template<typename Map, typename Table>
Map table_to_map(const Table &table) {
  Map res;

  for(size_t key = 0;key < table.size();key++) {
    inserter(res, res.end()) = make_pair(key, table[key]);
  }

  return res;
}

template<typename Graph>
vector<int> distances_from_bfs(const Graph &graph, vector<size_t> node_ids) {
  vector<int> dists(graph.nodes.size(), NOT_REACHABLE);

  list<size_t> queued;
  for(auto node : node_ids) {
    queued.push_back(node);
    dists[node] = 0;
  }

  while(!queued.empty()) {
    size_t node = queued.front();
    queued.pop_front();

    for(size_t child : graph.childs[node]) {
      if(dists[child] == NOT_REACHABLE) {
	dists[child] = dists[node] + 1;
	queued.push_back(child);
      }
    }
  }

  return dists;
}

template<typename Graph>
vector<int> distances_from_bfs(const Graph &graph, size_t node_id) {
  return distances_from_bfs(graph, vector<size_t>(1, node_id));
}

template<typename Container>
Container sorted(const Container &a) {
  Container res = a;
  sort(res.begin(), res.end());
  return res;
}

template<typename ContainerOut, typename ContainerIn>
ContainerOut key_set(const ContainerIn& container) {
  ContainerOut keys;
  for(typename ContainerIn::value_type p : container) {
    inserter(keys, keys.end()) = p.first;
  }
  return keys;
}
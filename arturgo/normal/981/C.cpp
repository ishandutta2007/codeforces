#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

void fast_io();


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


int main() {
  fast_io();
  int nbNodes;
  cin >> nbNodes;

  undirected_graph<int> graph;

  for(int iNode = 0;iNode < nbNodes;iNode++) {
    graph.add_node(iNode);
  }

  for(int iEdge = 0;iEdge < nbNodes - 1;iEdge++) {
    int deb, fin;
    cin >> deb >> fin;
    graph.add_edge_id(deb - 1, fin - 1);
  }

  vector<int> stars, leaves;
  for(int iNode = 0;iNode < nbNodes;iNode++) {
    if(graph.childs[iNode].size() > 2) {
      stars.push_back(iNode);
    }
    if(graph.childs[iNode].size() == 1) {
      leaves.push_back(iNode);
    }
  }

  if(stars.size() > 1) {
    cout << "No" << endl;
  }
  else {
    cout << "Yes" << endl;
    if(stars.empty())
      stars.push_back(0);
    vector<pair<int, int>> paths;
    for(int leave : leaves) {
      if(leave != stars[0])
	paths.push_back({leave, stars[0]});
    }
    cout << paths.size() << endl;
    for(pair<int, int> path : paths) {
      cout << path.first + 1 << " " << path.second + 1 << endl;
    }
  }
  return 0;
}


void fast_io() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
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
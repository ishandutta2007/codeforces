#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;


template<typename Container>
Container read_container(istream& stream = cin);


template<typename Container>
void print_container(const Container& container, ostream& stream = cout);

template< typename ContainerOut, typename ContainerIn, typename Operation>
ContainerOut apply(const ContainerIn& container, Operation op);

template<typename Param>
class add {
private:
  Param value;
public:
  add(Param _value);
  Param operator ()(const Param& a);
};


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

template<typename Graph>
vector<size_t> connected_component(const Graph &graph, size_t node_id);

template<typename Graph>
vector<vector<size_t>> connected_components(const Graph &graph);

template<typename Graph, typename Table>
Graph table_to_graph(const Table& table);


template<typename Sequence>
int signature(const Sequence &seq);


int main() {
  ios_base::sync_with_stdio(false);
  auto permutation = read_container<vector<int>>();
  permutation = apply<vector<int>>(permutation, add<int>(-1));

  int sign = signature(permutation);
  if(permutation.size() % 2 == 0) {
    if(sign == 1)
      cout << "Petr" << endl;
    else
      cout << "Um_nik" << endl;
  }
  else {
    if(sign == 1)
      cout << "Um_nik" << endl;
    else
      cout << "Petr" << endl;
  }
  
  return 0;
}


template<typename Container>
Container read_container(istream& stream) {
  size_t size;
  stream >> size;

  Container res;
  for(size_t i = 0;i < size;i++) {
    typename Container::value_type elem;
    stream >> elem;
    inserter(res, res.end()) = elem;
  }

  return res;
}

template<typename Container>
void print_container(const Container& container, ostream& stream) {
  #ifndef print_hide_size
  stream << container.size() << endl;
  #endif
  
  for(typename Container::value_type elem : container) {
    stream << elem;
    #ifndef print_separator
    stream << " ";
    #endif
  }
  
  #ifndef print_no_endl
  stream << endl;
  #endif
}

template< typename ContainerOut, typename ContainerIn, typename Operation>
ContainerOut apply(const ContainerIn& container, Operation op) {
  ContainerOut res;
  for(auto elem : container) {
    inserter(res, res.end()) = op(elem);
  }
  return res;
}

template<typename Param>
add<Param>::add(Param _value) {
  value = _value;
}

template<typename Param>
Param add<Param>::operator ()(const Param &a) {
  return a + value;
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

template<typename Graph>
vector<size_t> connected_component(const Graph &graph, size_t node_id) {
  vector<bool> viewed(graph.nodes.size(), false);
  
  vector<size_t> component, stacked;
  stacked.push_back(node_id);
  viewed[node_id] = true;

  while(!stacked.empty()) {
    size_t stacked_id = stacked.back();
    stacked.pop_back();

    component.push_back(stacked_id);
    
    for(size_t child : graph.childs[stacked_id]) {
      if(!viewed[child]) {
	viewed[child] = true;
	stacked.push_back(child);
      }
    }

    for(size_t parent : graph.childs[stacked_id]) {
      if(!viewed[parent]) {
	viewed[parent] = true;
	stacked.push_back(parent);
      }
    }
  }
  
  return component;
}

template<typename Graph>
vector<vector<size_t>> connected_components(const Graph &graph) {
  vector<bool> viewed(graph.nodes.size(), false);
  vector<vector<size_t>> components;
  for(size_t id = 0;id < graph.nodes.size();id++) {
    if(!viewed[id]) {
      components.push_back(connected_component(graph, id));
      for(size_t node_id : components.back())
	viewed[node_id] = true;
    }
  }
  return components;
}

template<typename Graph, typename Table>
Graph table_to_graph(const Table& table) {
  Graph graph;
  for(size_t begin = 0;begin < table.size();begin++) {
    graph.add_node(begin);
  }
  for(size_t begin = 0;begin < table.size();begin++) {
    graph.add_edge_id(begin, table[begin]);
  }
  return graph;  
}

template<typename Sequence>
int signature(const Sequence &seq) {
  auto graph = table_to_graph<directed_graph<size_t>>(seq);
  auto components = connected_components(graph);

  size_t parity = seq.size() - components.size();
  if(parity % 2 == 0)
    return 1;
  return -1;
}
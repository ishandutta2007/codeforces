#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

template<typename T>
struct MaxFlowMinCost {
    struct Edge {
        T cap, flow, cost;
        int to;
    };
    vector<Edge> Edges;
    vector<vector<int>> G;
    int src, dest;

    vector<int> Parent, ParentEdge, InQ;
    vector<T> Dist;


    MaxFlowMinCost& Initialize(int n, int m = 0) {
        G.clear();
        G.resize(n);
        Edges.clear();
        Edges.reserve(m);
        Parent.resize(n);
        ParentEdge.resize(n);
        Dist.resize(n);
        InQ.resize(n);

        return *this;
    }

    void _addEdge(int from, int to, T cap, T cost) {
        int ei = Edges.size();
        Edges.push_back(Edge {cap, 0, cost, to});
        G[from].push_back(ei);
    }
    MaxFlowMinCost& AddEdge(int from, int to, T cap, T cost) {
        _addEdge(from, to, cap, cost);
        _addEdge(to, from, 0, -cost);
        return *this;
    }

    MaxFlowMinCost& SetSourceSink(int src, int dest) {
        this->src = src; this->dest = dest;
        return *this;
    }

    bool Bellman() {
        static queue<int> Q;

        fill(Dist.begin(), Dist.end(), numeric_limits<T>::max());
        fill(Parent.begin(), Parent.end(), -1);
        fill(InQ.begin(), InQ.end(), 0);

        Dist[src] = 0;
        Q.push(src);

        while(!Q.empty()) {
            int node = Q.front();
            Q.pop();
            InQ[node] = 0;

            if(Parent[node] != -1 && InQ[Parent[node]])
                continue;

            for(auto ei : G[node]) {
                auto &e = Edges[ei];
                if(e.flow < e.cap && Dist[e.to] > Dist[node] + e.cost) {
                    Dist[e.to] = Dist[node] + e.cost;
                    Parent[e.to] = node;
                    ParentEdge[e.to] = ei;
                    if(!InQ[e.to]) {
                        Q.push(e.to);
                        InQ[e.to] = 1;
                    }
                }
            }
        }

        return Parent[dest] != -1;
    }
    pair<T, T> Compute() {
        T flow = 0, cost = 0;

        while(Bellman()) {
            T m = numeric_limits<T>::max();
            for(int node = dest; node != src; node = Parent[node]) {
                int ei = ParentEdge[node];
                m = min(m, Edges[ei].cap - Edges[ei].flow);
            }
            for(int node = dest; node != src; node = Parent[node]) {
                int ei = ParentEdge[node];
                Edges[ei].flow += m;
                Edges[ei ^ 1].flow -= m;

                cost += Edges[ei].cost * m;
            }
            flow += m;
        }

        return {flow, cost};
    }
};

int const sigma = 26;
int freq[1 + sigma];

int main()
{
  string s, sinit;
  cin >> s;
  sinit = s;
  int n;
  cin >> n;
  MaxFlowMinCost <int>graph;
  graph.Initialize(1 + sigma + n + 2);

  for(int i = 0; i < s.size(); i++)
    freq[s[i] - 'a']++;
  for(int i = 0; i < sigma; i++)
    graph.AddEdge(1, 2 + i, freq[i], 0);

  for(int i = 1;i <= n; i++){
    cin >> s;
    for(int h = 0; h < sigma; h++)
      freq[h] = 0;
    for(int j = 0; j < s.size(); j++)
      freq[s[j] - 'a']++;
    for(int j = 0; j < sigma; j++)
      graph.AddEdge(2 + j, 1 + sigma + i, freq[j], 0);
    int lim;
    cin >> lim;
    graph.AddEdge(1 + sigma + i, 1 + sigma + n + 1, lim, i);
  }
  graph.SetSourceSink(1, 1 + sigma + n + 1);
  pair<int,int> sol =graph.Compute();


  if(sinit.size() != sol.first)
    cout << -1;
  else
    cout << sol.second << '\n';
  return 0;
}
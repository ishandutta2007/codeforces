#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
const int Nmax = 205;

int A[Nmax];

class MaxFlowNetwork {
private:
    typedef long long i64;
    class Edge {
    public:
        int to;
        i64 cap, flow;
        Edge* rev;
        Edge(const int _to, const i64 _cap, const i64 _flow):
            to(_to), cap(_cap), flow(_flow) {}
    };
public:
    MaxFlowNetwork(const int N):
        G(vector<vector<Edge*>>(N)), father(vector<Edge*>(N)), NIL(new Edge(0, 0, 0)) {

        }
    ~MaxFlowNetwork() {
        for (auto& p: G)
            for (Edge* l: p)
                delete l;
        delete NIL;
    }

    void addEdge(int x, int y, i64 cap, i64 flow = 0) {
        Edge* add = new Edge(y, cap, flow);
        Edge* rev = new Edge(x, 0, -flow);
        add->rev = rev; rev->rev = add;
        G[x].push_back(add);
        G[y].push_back(rev);
    }

    i64 maxFlow(int S, int D, bool clearFlow = true) {
        i64 flow = 0;
        while (bfs(S, D)) {
            for (Edge* p: G[D]) {
                if (p->rev->cap == p->rev->flow || father[p->to] == NULL) continue;
                i64 fmin = MaxFlowNetwork::Inf;
                for (int i = D; i != S; i = father[i]->to)
                    fmin = min(fmin, father[i]->rev->cap - father[i]->rev->flow);
                flow += fmin;
                for (int i = D; i != S; i = father[i]->to) {
                    father[i]->rev->flow += fmin;
                    father[i]->flow -= fmin;
                }
            }
        }
        if (clearFlow) {
            fill(father.begin(), father.end(), (Edge*)NULL);
            dfsClear(S);
        }
        return flow;
    }

    vector<vector<int>> getAns() {
        fill(father.begin(), father.end(), (Edge*)NULL);
        vector<vector<int>> ret;
        for (int i = 1; i < int(G.size()) - 1; ++i) {
            if (father[i] == NULL) {
                ret.push_back(vector<int>());
                dfsGet(i, ret.back());
            }
        }
        return ret;
    }
private:
    const static i64 Inf = 1LL << 62;
    vector<vector<Edge*>> G;
    vector<Edge*> father;
    Edge* NIL;

    bool bfs(int S, int D) {
        fill(father.begin(), father.end(), (Edge*)NULL);
        queue<int> Q;
        Q.push(S);
        father[S] = NIL;
        while (!Q.empty()) {
            int node = Q.front();
            Q.pop();

            if (node == D) continue;

            for (Edge* p: G[node]) {
                if (p->cap == p->flow || father[p->to] != NULL) continue;
                father[p->to] = p->rev;
                Q.push(p->to);
            }
        }
        return father[D] != NULL;
    }

    void dfsClear(int node) {
        father[node] = NIL;
        for (Edge* p: G[node]) {
            p->flow = 0;
            if (father[p->to] != NIL)
                dfsClear(p->to);
        }
    }

    void dfsGet(int node, vector<int>& nodes) {
        father[node] = NIL;
        nodes.push_back(node);
        for (Edge* p: G[node]) {
            if (p->to == 0 || p->to == int(G.size()) - 1) continue;
            if (p->flow != 0 && father[p->to] == NULL) {
                dfsGet(p->to, nodes);
            }
        }
    }
};

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE

    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    for (int i = 1; i <= N; ++i)
        cin >> A[i];

    unique_ptr<MaxFlowNetwork> G(new MaxFlowNetwork(N + 2));
    int S = 0, D = N + 1;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            int sum = A[i] + A[j];
            bool isPrime = true;
            for (int k = 2; k * k <= sum; ++k) {
                if (sum % k == 0) {
                    isPrime = false;
                    break;
                }
            }
            if (isPrime && A[i] % 2 == 0 && A[j] % 2 == 1)
                G->addEdge(i, j, 1);
        }
    }

    for (int i = 1; i <= N; ++i) {
        if (A[i] % 2 == 0) G->addEdge(S, i, 2);
        else G->addEdge(i, D, 2);
    }

    int flow = G->maxFlow(S, D, false);
    //cout << flow << '\n';

    if (flow < N) {
        cout << "Impossible\n";
        return 0;
    }

    vector<vector<int>> ans = G->getAns();
    cout << ans.size() << '\n';
    for (auto& p: ans) {
        cout << p.size() << ' ';
        for (int l: p)
            cout << l << ' ';
        cout << '\n';
    }
}
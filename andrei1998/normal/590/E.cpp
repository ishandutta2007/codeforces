#include <iostream>
#include <string>
#include <queue>
#include <bitset>
#include <cassert>

using namespace std;

const int NMAX = 755;

int n;
string strings[NMAX];

bool bad[NMAX];
int adj[NMAX][NMAX];

//Maximum matching
int _left[NMAX];
int _right[NMAX];

bitset <NMAX> vis;

bool PairUp(int node) {
    if (vis[node])
        return false;
    vis[node] = true;

    for (int i = 1; i <= n; ++ i)
        if (adj[node][i] && !_right[i]) {
            _left[node] = i;
            _right[i] = node;
            return true;
        }

    for (int i = 1; i <= n; ++ i)
        if (adj[node][i] && PairUp(_right[i])) {
            _left[node] = i;
            _right[i] = node;
            return true;
        }

    return false;
}

bool _left_in_cover[NMAX];
bool _right_in_cover[NMAX];

void VertexCover(int node) {
    for (int i = 1; i <= n; ++ i)
        if (adj[node][i] && !_right_in_cover[i]) {
            _right_in_cover[i] = true;
            _left_in_cover[_right[i]] = false;
            VertexCover(_right[i]);
        }
}

vector <int> sol;

void HopcroftKarpAndVertexCover() {
    bool ok = true;
    while (ok) {
        ok = false;
        vis &= 0;

        for (int i = 1; i <= n; ++ i)
            if (!bad[i] && !_left[i] && PairUp(i))
                ok = true;
    }

    for (int i = 1; i <= n; ++ i)
        if (_left[i])
            _left_in_cover[i] = true;

    for (int i = 1; i <= n; ++ i)
        if (!bad[i] && !_left_in_cover[i])
            VertexCover(i);

    for (int i = 1; i <= n; ++ i)
        _left_in_cover[i] ^= 1, _right_in_cover[i] ^= 1;

    for (int i = 1; i <= n; ++ i) {
        if (_left_in_cover[i] && _right_in_cover[i])
            sol.push_back(i);
        assert(_left_in_cover[i] || _right_in_cover[i]);
    }
}

void closure() {
    for (int k = 1; k <= n; ++ k)
        for (int i = 1; i <= n; ++ i)
            for (int j = 1; j <= n; ++ j)
                if (i != j && adj[i][k] && adj[k][j])
                    adj[i][j] = true;
}

const int LENMAX = 10000005;

//16:31
struct Node {
    int lit;
    int father;

    int fail;
    int alf[2];

    int word; //index of a word that ends here
    int fail_word; //index of the longest word that ends on the fail-path to the root
} nodes[LENMAX];

int sz;
int new_node(int father = -1, int lit = -1) {
    nodes[sz].father = father;
    nodes[sz].lit = lit;
    nodes[sz].alf[0] = nodes[sz].alf[1] = -1;
    nodes[sz].word = nodes[sz].fail_word = 0;
    return sz ++;
}

void init() {
    new_node(); //root
}

void add(int index) {
    int node = 0;
    for (auto it: strings[index]) {
        if (nodes[node].alf[it - 'a'] == -1)
            nodes[node].alf[it - 'a'] = new_node(node, it - 'a');
        node = nodes[node].alf[it - 'a'];
    }

    if (nodes[node].word)
        bad[index] = true;
    else
        nodes[node].word = index;
}

void run(int index) {
    int node = 0;
    for (auto it: strings[index]) {
        if (nodes[node].fail_word)
            adj[nodes[node].fail_word][index] = true;
        node = nodes[node].alf[it - 'a'];
    }

    if (nodes[nodes[node].fail].fail_word)
        adj[nodes[nodes[node].fail].fail_word][index] = true;

}

void build_fails() {
    queue <int> _queue;
    _queue.push(0);

    int node;
    while (!_queue.empty()) {
        node = _queue.front();
        _queue.pop();

        if (nodes[node].father > 0) {
            //nodes[node].fail edge
            int k = nodes[nodes[node].father].fail;
            while (k && nodes[k].alf[nodes[node].lit] == -1)
                k = nodes[k].fail;

            if (nodes[k].alf[nodes[node].lit] != -1)
                k = nodes[k].alf[nodes[node].lit];
            nodes[node].fail = k;
        }

        //nodes[node].fail_word
        if (nodes[node].word)
            nodes[node].fail_word = nodes[node].word;
        else
            nodes[node].fail_word = nodes[nodes[node].fail].fail_word;

        //Tranzitions
        for (int i = 0; i < 2; ++ i)
            if (nodes[node].alf[i] != -1)
                _queue.push(nodes[node].alf[i]);
    }
}

int main()
{
    ios_base :: sync_with_stdio(false);
    init();

    //Building AHO
    cin >> n;

    for (int i = 1; i <= n; ++ i) {
        cin >> strings[i];
        add(i);
    }

    build_fails();

    //Run AHO
    for (int i = 1; i <= n; ++ i)
        if (!bad[i])
            run(i);

    //Build closure of poset
    closure();

    //Debug
    /*for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= n; ++ j)
            if (adj[i][j])
                cout << i << ' ' << j << ' ' << strings[i] << " e inclus in " << strings[j] << endl;*/

    HopcroftKarpAndVertexCover();

    cout << sol.size() << '\n';
    for (int i = 0; i < sol.size(); ++ i)
        cout << sol[i] << " \n"[i + 1 == sol.size()];
    return 0;
}
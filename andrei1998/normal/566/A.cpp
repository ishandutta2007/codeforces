#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

const int NMAX = 100005;

int ans[NMAX];

class Trie {
public:
    struct node {
        vector <int> normals;
        vector <int> specials;

        int h;
        int father;
        int alf[26];

        node (int _h = 0, int _father = 0): h(_h), father(_father) {
            memset(alf, 0, sizeof(alf));
        }
    };

    vector <node> nodes;

    inline int new_node (int h, int father) {
        nodes.push_back(node(h, father));
        return nodes.size() - 1;
    }

    Trie () {
        new_node(0, 0);
    }

    inline void add_normal (const string &str, int index) {
        int node = 0, aux;

        for (auto it: str) {
            if (!nodes[node].alf[it - 'a']) {
                aux = new_node(nodes[node].h + 1, node);
                nodes[node].alf[it - 'a'] = aux;
            }

            node = nodes[node].alf[it - 'a'];
        }

        nodes[node].normals.push_back(index);
    }

    inline void add_special (const string &str, int index) {
        int node = 0, aux;

        for (auto it: str) {
            if (!nodes[node].alf[it - 'a']) {
                aux = new_node(nodes[node].h + 1, node);
                nodes[node].alf[it - 'a'] = aux;
            }

            node = nodes[node].alf[it - 'a'];
        }

        nodes[node].specials.push_back(index);
    }

    int dfs_solve (int node) {
        //Rezolvam fii
        int return_value = 0;
        for (int i = 0; i < 26; ++ i)
            if (nodes[node].alf[i])
                return_value += dfs_solve(nodes[node].alf[i]);

        //Acum avem chestii de rezolvat aici
        int i;
        for (i = 0; i < nodes[node].normals.size() && i < nodes[node].specials.size(); ++ i) {
            return_value += nodes[node].h;
            ans[nodes[node].normals[i]] = nodes[node].specials[i];
        }

        for (; i < nodes[node].normals.size(); ++ i)
            nodes[nodes[node].father].normals.push_back(nodes[node].normals[i]);
        for (; i < nodes[node].specials.size(); ++ i)
            nodes[nodes[node].father].specials.push_back(nodes[node].specials[i]);

        return return_value;
    }
} trie;

int main()
{
    ios_base :: sync_with_stdio(false);

    int n = 0;
    cin >> n;

    string str;

    //Citim normalele
    for (int i = 1; i <= n; ++ i) {
        cin >> str;
        trie.add_normal(str, i);
    }

    //Citim specialele
    for (int i = 1; i <= n; ++ i) {
        cin >> str;
        trie.add_special(str, i);
    }

    cout << trie.dfs_solve(0) << '\n';
    for (int i = 1; i <= n; ++ i)
        cout << i << ' ' << ans[i] << '\n';
    return 0;
}
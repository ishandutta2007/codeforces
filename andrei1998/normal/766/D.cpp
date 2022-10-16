#include <iostream>
#include <string>
#include <map>

using namespace std;

map <string, int> Map;

const int NMAX = 2 * (100000 + 5);

int father[NMAX];
int h[NMAX];

inline void init() {
    for (int i = 0; i < NMAX; ++ i)
        father[i] = i;
}

int find(int node) {
    if (father[node] != father[father[node]])
        father[node] = find(father[node]);
    return father[node];
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b)
        return ;

    if (h[a] < h[b])
        father[a] = b;
    else {
        if (h[a] == h[b])
            ++ h[a];
        father[b] = a;
    }
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    int N, M, Q;
    cin >> N >> M >> Q;

    init();

    for (int i = 1; i <= N; ++ i) {
        string str;
        cin >> str;

        Map[str] = 2 * i - 1;
        Map["!" + str] = 2 * i;
    }

    for (int i = 1; i <= M; ++ i) {
        int type;
        cin >> type;

        string strA, strB;
        cin >> strA >> strB;

        int a = Map[strA];
        int b = Map[strB];

        string str_a = "!" + strA;
        string str_b = "!" + strB;

        int _a = Map[str_a];
        int _b = Map[str_b];

        if (type == 1) {
            if (find(a) != find(_b)) {
                unite(a, b);
                unite(_a, _b);
                cout << "YES\n";
            }
            else
                cout << "NO\n";
        }
        else {
            if (find(a) != find(b)) {
                unite(a, _b);
                unite(_a, b);
                cout << "YES\n";
            }
            else
                cout << "NO\n";
        }
    }


    for (int i = 1; i <= Q; ++ i) {
        string strA, strB;
        cin >> strA >> strB;

        int a = Map[strA];
        int b = Map[strB];

        string str_a = "!" + strA;
        string str_b = "!" + strB;

        int _a = Map[str_a];
        int _b = Map[str_b];

        if (find(a) == find(b)) {
            cout << "1\n";
        }
        else if (find(a) == find(_b))
            cout << "2\n";
        else
            cout << "3\n";
    }
    return 0;
}
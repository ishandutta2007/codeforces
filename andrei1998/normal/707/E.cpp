#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

#define lint long long int
using namespace std;

class InputReader {
public:
    InputReader() {
        input_file = stdin;
        cursor = 0;
        fread(buffer, SIZE, 1, input_file);
    }
    InputReader(const char *file_name) {
        input_file = fopen(file_name, "r");
        cursor = 0;
        fread(buffer, SIZE, 1, input_file);
    }
    inline InputReader &operator >>(int &n) {
        while(buffer[cursor] < '0' || buffer[cursor] > '9') {
            advance();
        }
        n = 0;
        while('0' <= buffer[cursor] && buffer[cursor] <= '9') {
            n = n * 10 + buffer[cursor] - '0';
            advance();
        }
        return *this;
    }
    inline InputReader &operator >>(string &n) {
        while(buffer[cursor] < 'A' || buffer[cursor] > 'Z') {
            advance();
        }
        n = "";
        while('A' <= buffer[cursor] && buffer[cursor] <= 'Z') {
            n += buffer[cursor];
            advance();
        }
        return *this;
    }
private:
    FILE *input_file;
    static const int SIZE = 1 << 17;
    int cursor;
    char buffer[SIZE];
    inline void advance() {
        ++ cursor;
        if(cursor == SIZE) {
            cursor = 0;
            fread(buffer, SIZE, 1, input_file);
        }
    }
};

int n, m, k;

struct Bulb {
    int lin, col, w;
};

const int GMAX = 2000 + 5;

vector <Bulb> garlands[GMAX];
bool garland_states[GMAX];

struct GarlandQuery {
    int lin1, col1;
    int lin2, col2;
    int where;
};

vector <GarlandQuery> garland_queries[GMAX];

const int QMAX = 1000000 + 5;

lint anss[QMAX];

//AIB2D
#define lsb(i) ((i) & (-(i)))
vector <pair <int, int> > modified_cells;

lint aib[GMAX][GMAX];

void init() {
    for (auto it: modified_cells)
        aib[it.first][it.second] = 0;
    modified_cells.clear();
}

void update(int lin, int col, int val) {
    for (int i = lin; i <= n; i += lsb(i))
        for (int j = col; j <= m; j += lsb(j)) {
            modified_cells.push_back(make_pair(i, j));
            aib[i][j] += val;
        }
}

lint query(int lin, int col) {
    lint ans = 0;
    for (int i = lin; i; i -= lsb(i))
        for (int j = col; j; j -= lsb(j))
            ans += aib[i][j];
    return ans;
}

inline lint query(int lin1, int col1, int lin2, int col2) {
    return query(lin2, col2) - query(lin2, col1 - 1) - query(lin1 - 1, col2) + query(lin1 - 1, col1 - 1);
}

int main()
{
    //freopen("input.in", "r", stdin);
    //InputReader cin("input.in");
    InputReader cin;
    //ios_base :: sync_with_stdio(false);

    cin >> n >> m >> k;

    for (int i = 1; i <= k; ++ i) {
        int len = 0;
        cin >> len;

        garlands[i].resize(len);
        for (int j = 0; j < len; ++ j)
            cin >> garlands[i][j].lin >> garlands[i][j].col >> garlands[i][j].w;
        garland_states[i] = true;
    }

    int q = 0;
    cin >> q;

    string op;
    int who;
    int lin1, col1;
    int lin2, col2;

    int asks = 0;
    for (int i = 1; i <= q; ++ i) {
        cin >> op;
        if (op == "SWITCH") {
            cin >> who;
            garland_states[who] ^= 1;
        }
        else {
            ++ asks;
            cin >> lin1 >> col1 >> lin2 >> col2;

            for (int j = 1; j <= k; ++ j)
                if (garland_states[j]) {
                    GarlandQuery gq;

                    gq.col1 = col1;
                    gq.lin1 = lin1;
                    gq.col2 = col2;
                    gq.lin2 = lin2;
                    gq.where = asks;

                    garland_queries[j].push_back(gq);
                }
        }
    }

    //Process queries offline
    for (int i = 1; i <= k; ++ i) {
        init();
        for (auto it: garlands[i])
            update(it.lin, it.col, it.w);

        for (auto it: garland_queries[i])
            anss[it.where] += query(it.lin1, it.col1, it.lin2, it.col2);
    }

    for (int i = 1; i <= asks; ++ i)
        cout << anss[i] << '\n';
    return 0;
}
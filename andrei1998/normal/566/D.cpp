#include <iostream>
#include <algorithm>

using namespace std;

const int NMAX = 200005;

class InputReader {
    public:
        InputReader() {
            cursor = 0;
            fread(buffer, SIZE, 1, stdin);
        }
        inline InputReader &operator >>(int &n) {
            while(buffer[cursor] < '0' || buffer[cursor] > '9')
                advance();
            n = 0;
            while('0' <= buffer[cursor] && buffer[cursor] <= '9') {
                n = n * 10 + buffer[cursor] - '0';
                advance();
            }
            return *this;
        }
    private:
        static const int SIZE = 1 << 17;
        int cursor;
        char buffer[SIZE];
        inline void advance() {
            ++ cursor;
            if(cursor == SIZE) {
                cursor = 0;
                fread(buffer, SIZE, 1, stdin);
            }
        }
};

class DisjointSets {
public:
    int father[NMAX];
    int h[NMAX];
    int left[NMAX];

    void init (int n) {
        for (int i = 1; i <= n; ++ i)
            father[i] = left[i] = i, h[i] = 1;
    }

    int find (int node) {
        if (father[node] != father[father[node]])
            father[node] = find(father[node]);
        return father[node];
    }

    inline void unite (int a, int b) {
        a = find(a), b = find(b);
        if (a == b)
            return ;

        if (h[a] < h[b]) {
            father[a] = b;
            if (left[a] > left[b])
                left[b] = left[a];
        }
        else {
            if (h[a] == h[b])
                ++ h[a];
            father[b] = a;
            if (left[b] > left[a])
                left[a] = left[b];
        }
    }
} normal, contiguous;

int main()
{
    //ios_base :: sync_with_stdio(false);
    InputReader cin;

    int n = 0, q = 0;
    cin >> n >> q;

    normal.init(n);
    contiguous.init(n);

    int type;
    int x, y;

    while (q --) {
        cin >> type >> x >> y;

        if (type == 1)
            normal.unite(x, y);
        else if (type == 2) {
            for (x = contiguous.left[contiguous.find(x)]; x + 1 <= y; x = contiguous.left[contiguous.find(x)]) {
                contiguous.unite(x, x + 1);
                normal.unite(x, x + 1);
            }
        }
        else {
            if (normal.find(x) == normal.find(y))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }

    return 0;
}
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

class InputReader {
    public:
        InputReader() {
            cursor = 0;
            fread(buffer, SIZE, 1, stdin);
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

int n;
int mat[2005][2005];

bool vis1[2005];
void dfs1(int node) {
    vis1[node] = true;

    for (int i = 1; i <= n; ++ i)
        if (mat[node][i] && !vis1[i])
            dfs1(i);
}


bool vis2[2005];
void dfs2(int node) {
    vis2[node] = true;

    for (int i = 1; i <= n; ++ i)
        if (mat[i][node] && !vis2[i])
            dfs2(i);
}

int main()
{
    InputReader cin;

    cin >> n;
    for (int i = 1, j; i <= n; ++ i)
        for (j = 1; j <= n; ++ j)
            cin >> mat[i][j];

    dfs1(1);
    dfs2(1);

    int ans = 0;
    for (int i = 1; i <= n; ++ i)
        ans += vis1[i] + vis2[i];

    if (ans == 2 * n)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
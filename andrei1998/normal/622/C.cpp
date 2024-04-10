#include <iostream>
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

const int NMAX = 1000005;

int n;
int v[NMAX];
int extend[NMAX];

int main()
{
    InputReader cin;

    int m = 0;
    cin >> n >> m;

    for (int i = 1; i <= n; ++ i)
        cin >> v[i];

    for (int i = 1; i <= n; ++ i)
        if (v[i] == v[i - 1])
            extend[i] = extend[i - 1];
        else
            extend[i] = i;

    int l, r, x;
    while (m --) {
        cin >> l >> r >> x;

        if (v[r] != x)
            cout << r << '\n';
        else if (extend[r] <= l)
            cout << "-1\n";
        else
            cout << extend[r] - 1 << '\n';
    }

    return 0;
}
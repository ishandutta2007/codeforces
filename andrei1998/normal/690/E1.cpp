#include <iostream>
#include <cstdio>
#include <cstdlib>

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

int mat[605][605];

int main()
{
    //freopen("sample.in", "r", stdin);

    InputReader cin;

    int q = 0;
    cin >> q;

    while (q --) {
        int h, w;
        cin >> h >> w;

        for (int i = 1; i <= h; ++ i)
            for (int j = 1; j <= w; ++ j)
                cin >> mat[i][j];

        int cate = 0;
        for (int j = 1; j <= w; ++ j)
            cate += abs(mat[h / 2][j] - mat[h / 2 + 1][j]) > 10;

        if (cate >= w / 2)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
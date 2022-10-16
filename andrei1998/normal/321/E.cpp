#include <iostream>
#include <cstdio>

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

const int NMAX = 4005;
const int KMAX = 805;
const int INF = 1e9 + 15;

int n, k;
int mat[NMAX][NMAX];
int c[NMAX][NMAX];

int dp[KMAX][NMAX];
int where[NMAX];

void compute(int index, int l, int r) {
    if (r < l)
        return ;

    int mid = (l + r) >> 1;

    dp[index][mid] = INF;
    where[mid] = mid - 1;

    for (int i = where[l - 1]; i <= where[r + 1] && i < mid; ++ i)
        if (dp[index - 1][i] + c[i + 1][mid] < dp[index][mid]) {
            dp[index][mid] = dp[index - 1][i] + c[i + 1][mid];
            where[mid] = i;
        }

    compute(index, l, mid - 1);
    compute(index, mid + 1, r);
}

int main()
{
    //ios_base :: sync_with_stdio(false);
    InputReader cin;

    cin >> n >> k;
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= n; ++ j) {
            cin >> mat[i][j];
            mat[i][j] += (mat[i - 1][j] - mat[i - 1][j - 1] + mat[i][j - 1]);
        }

    for (int i = 1; i <= n; ++ i)
        for (int j = i; j <= n; ++ j)
            c[i][j] = mat[j][j] - mat[i - 1][j] - mat[j][i - 1] + mat[i - 1][i - 1];

    dp[1][0] = INF;
    for (int i = 1; i <= n; ++ i)
        dp[1][i] = c[1][i];

    where[n + 1] = n;
    for (int i = 2; i <= k; ++ i)
        compute(i, 1, n);

    cout << dp[k][n] / 2 << '\n';
    return 0;
}
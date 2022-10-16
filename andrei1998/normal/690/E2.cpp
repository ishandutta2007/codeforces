#include <iostream>
#include <cstdio>
#include <algorithm>

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

const int NMAX = 605;
const int KMAX = 17;

int h, w, k;
int img[NMAX][NMAX];

InputReader fin;
void read_img() {
    fin >> h >> w >> k;
    for (int i = 1; i <= h; ++ i)
        for (int j = 1; j <= w; ++ j)
            fin >> img[i][j];
}

int s_part[NMAX][NMAX];

void compute_s_part() {
    for (int i = 1; i <= h; ++ i)
        for (int j = 1; j <= w; ++ j)
            s_part[i][j] = img[i][j] + s_part[i][j - 1] + s_part[i - 1][j] - s_part[i - 1][j - 1];
}

int average(int l1, int c1, int l2, int c2) {
    int sum = s_part[l2][c2] - s_part[l2][c1 - 1] - s_part[l1 - 1][c2] + s_part[l1 - 1][c1 - 1];
    int area = (l2 - l1 + 1) * (c2 - c1 + 1);
    return sum / area;
}

int new_img[NMAX][NMAX];

void blur() {
    int lat = 3;
    for (int i = 1; i <= k; ++ i) {
        int u = (i - 1) * (h / k) + 1;
        int d = i * (h / k);

        for (int lin = u; lin <= d; ++ lin)
            for (int col = 1; col <= w; ++ col)
                new_img[lin][col] = average(max(u, lin - lat), max(1, col - lat), min(d, lin + lat), min(w, col + lat));
    }
}

int cost[KMAX][KMAX];

int compute_cost(int u1, int d1, int u2, int d2) {
    int ans = 0;
    for (int col = 1; col <= w; ++ col)
        ans += abs(new_img[d1][col] - new_img[u2][col]);// * (new_img[d1][col] - new_img[u2][col]);
    return ans;
}

const int INF = 1e9 + 15;
int dp[1 << KMAX][KMAX];
int father[1 << KMAX][KMAX];

int compute_dp() {
    for (int i = 0; i < (1 << k); ++ i)
        for (int j = 0; j < k; ++ j)
            dp[i][j] = INF;

    for (int i = 0; i < k; ++ i)
        dp[1 << i][i] = 0;

    for (int i = 0; i < (1 << k); ++ i)
        for (int j = 0; j < k; ++ j)
            if ((i & (1 << j)) && dp[i][j] < INF)
                for (int l = 0; l < k; ++ l)
                    if (!(i & (1 << l)))
                        if (dp[i][j] + cost[j + 1][l + 1] < dp[i | (1 << l)][l]) {
                            dp[i | (1 << l)][l] = dp[i][j] + cost[j + 1][l + 1];
                            father[i | (1 << l)][l] = j;
                        }

    int ans = INF;
    int node;
    for (int j = 0; j < k; ++ j)
        if (dp[(1 << k) - 1][j] < ans) {
            ans = dp[(1 << k) - 1][j];
            node = j + 1;
        }

    return node;
}

int p[KMAX];
int p_inv[KMAX];

void solve() {
    int state = (1 << k) - 1;
    int node = compute_dp();

    int pos = 0;
    p[++ pos] = node;

    while (state & (state - 1)) {
        p[++ pos] = father[state][node - 1] + 1;
        state ^= (1 << (node - 1));
        node = p[pos];
    }

    reverse(p + 1, p + k + 1);
    for (int i = 1; i <= k; ++ i)
        p_inv[p[i]] = i;

    for (int i = 1; i <= k; ++ i)
        cout << p_inv[i] << " \n"[i == k];
}

int main()
{
    //freopen("sample.in", "r", stdin);

    int q = 0;
    fin >> q;

    while (q --) {
        read_img();
        compute_s_part();
        blur();

        for (int i = 1; i <= k; ++ i) {
            int ui = (i - 1) * (h / k) + 1;
            int di = i * (h / k);

            for (int j = 1; j <= k; ++ j) {
                int uj = (j - 1) * (h / k) + 1;
                int dj = j * (h / k);
                cost[i][j] = compute_cost(ui, di, uj, dj);
            }
        }

        solve();
    }

    return 0;
}
#include <iostream>
#include <cstdio>
#include <algorithm>

//16:55
using namespace std;

class InputReader {
public:
    InputReader() {
        input_file = stdin;
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

const int NMAX = 100000 + 5;

typedef long long int lint;

struct Query {
    int x, y;
    int pos;

    friend bool operator<(const Query &a, const Query &b) {
        return a.y < b.y;
    }
} queries[NMAX];

int N;
int a[NMAX];
int sp[NMAX];

long double intersect(int j1, int j2) {
    return 1.0L * (sp[j2] - sp[j1] + 1LL * j1 * a[j1] - 1LL * j2 * a[j2]) / (a[j2] - a[j1]);
}

lint eval(int i, int j, int cnt) {
    return 1LL * (cnt - i + j) * a[j] + sp[i] - sp[j];
}

int answers[NMAX];

int stk[NMAX];
int sz;

int main()
{
    InputReader cin;

    cin >> N;
    for (int i = 1; i <= N; ++ i) {
        cin >> a[i];
        sp[i] = a[i] + sp[i - 1];
    }

    int Q = 0;
    cin >> Q;

    for (int i = 1; i <= Q; ++ i) {
        cin >> queries[i].x >> queries[i].y;
        queries[i].pos = i;
    }
    sort(queries + 1, queries + Q + 1);

    for (int i = 1, j = 1; i <= N && j <= Q; ++ i) {
        //Destroy useless lines
        while (sz > 0 && a[stk[sz]] >= a[i])
            -- sz;
        while (sz > 1 && intersect(stk[sz - 1], stk[sz]) <= intersect(stk[sz], i))
            -- sz;
        stk[++ sz] = i;

        //Solve queries
        while (j <= Q && queries[j].y == i) {
            int cnt = queries[j].x;

            int st = 1;
            int dr = sz - 1;
            int ans = 0;

            while (st <= dr) {
                int mid = (st + dr) >> 1;
                if (eval(i, stk[mid], cnt) >= eval(i, stk[mid + 1], cnt)) {
                    ans = mid;
                    st = mid + 1;
                }
                else
                    dr = mid - 1;
            }

            answers[queries[j ++].pos] = eval(i, stk[ans + 1], cnt);
        }
    }

    for (int i = 1; i <= Q; ++ i)
        cout << answers[i] << '\n';
    return 0;
}
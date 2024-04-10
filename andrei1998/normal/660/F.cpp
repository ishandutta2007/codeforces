#include <bits/stdc++.h>

using namespace std;

class InputReader {
public:
    InputReader() {
        input_file = stdin;
        fread(buffer, SIZE, 1, input_file);
        cursor = 0;
    }
    inline InputReader &operator >>(int &n) {
        while ((buffer[cursor] < '0' || buffer[cursor] > '9') && buffer[cursor] != '-')
            advance();
        int sign = 1;
        if (buffer[cursor] == '-') {
            sign = -1;
            advance();
        }
        n = 0;
        while('0' <= buffer[cursor] && buffer[cursor] <= '9') {
            n = n * 10 + buffer[cursor] - '0';
            advance();
        }
        n *= sign;
        return *this;
    }
private:
    FILE *input_file;
    static const int SIZE = 1 << 17;
    int cursor;
    char buffer[SIZE];
    inline void advance() {
        if (++cursor == SIZE) {
            cursor = 0;
            fread(buffer, SIZE, 1, input_file);
        }
    }
};

typedef long long int lint;
const lint INF = 1E18 + 15;

struct Line {
    lint A, B;
    mutable lint x;

    Line(lint _A, lint _B):
        A(_A), B(_B), x(INF) {}

    Line(lint _x = 0):
        A(-1), B(-1), x(_x) {}

    lint getVal(lint _x) const {
        return 1LL * A * _x + B;
    }

    static bool slopeCompare;
    friend bool operator<(const Line &a, const Line &b) {
        if (slopeCompare) {
            if (a.A != b.A)
                return a.A < b.A;
            else
                return a.B < b.B;
        }
        else
            return a.x < b.x;
    }

    friend long double intersect(const Line &a, const Line &b) {
        return 1.0L * (-a.B + b.B) / (a.A - b.A);
    }
};

bool Line :: slopeCompare = true;

class CHT : public set <Line> {
public:
    void Insert(const Line &l) {
        iterator it = insert(l).first;
        while (next(it) != end() && bad(next(it)))
            erase(next(it));
        refresh(it);
        if (it != begin())
            refresh(prev(it));
    }

    lint query(lint x) {
        Line :: slopeCompare = false;
        iterator it = lower_bound(Line(x));
        Line :: slopeCompare = true;

        return it -> getVal(x);
    }

private:
    bool bad(iterator it) {
        iterator nxt = next(it);
        if (nxt == end())
            return false;

        iterator prv = prev(it);
        return intersect(*prv, *nxt) + 1E-20 >= intersect(*it, *nxt);
    }

    void refresh(iterator it) {
        iterator nxt = next(it);
        if (nxt == end())
            it -> x = INF;
        else
            it -> x = intersect(*it, *nxt);
    }
};

const int NMAX = 2 * 100000 + 5;

int N;
int a[NMAX];
lint s1[NMAX], s2[NMAX];

int main()
{
    //ios_base :: sync_with_stdio(false);
    InputReader cin;

    cin >> N;
    for (int i = 1; i <= N; ++ i) {
        cin >> a[i];
        s1[i] = s1[i - 1] + a[i];
        s2[i] = s2[i - 1] + 1LL * i * a[i];
    }

    CHT c;
    lint ans = 0;
    for (int i = 1; i <= N; ++ i) {
        c.Insert(Line(-(i - 1), 1LL * (i - 1) * s1[i - 1] - s2[i - 1]));
        ans = max(ans, s2[i] + c.query(s1[i]));
    }

    cout << ans << '\n';
    return 0;
}
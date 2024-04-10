#include <bits/stdc++.h>

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

int N, P;
int a[NMAX];
int b[NMAX];

static inline bool check(double X) {
    double sum = P * X;
    for (int i = 1; i <= N && sum >= 0; ++ i) {
        double aux = b[i] - X * a[i];
        sum += (aux < 0 ? aux : 0);
    }
    return sum >= 0;
}

int main()
{
    InputReader cin;
    cin >> N >> P;

    long long int sumA = 0, sumB = 0;
    for (int i = 1; i <= N; ++ i) {
        cin >> a[i] >> b[i];
        sumA += a[i];
        sumB += b[i];
    }

    if (sumA <= P) {
        cout << "-1\n";
        return 0;
    }

    double st = 0;
    if (check(1)) {
        st = 1;
        double dr = sumB + 1;
        for (int step = 0; step < 18; ++ step) {
            double X = sqrt(st * dr);
            if (check(X))
                st = X;
            else
                dr = X;
        }
    }
    else {
        st = 0;
        double dr = 1;
        for (int step = 0; step < 15; ++ step) {
            double X = (st + dr) * 0.5;
            if (check(X))
                st = X;
            else
                dr = X;
        }
    }
    cout << fixed << setprecision(10) << st << '\n';
    return 0;
}
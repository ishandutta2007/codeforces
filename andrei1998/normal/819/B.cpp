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

const int NMAX = 1000000 + 5;
typedef long long int lint;

int N;
int v[2 * NMAX];

int freq[3 * NMAX];

int main()
{
    InputReader cin;
    //freopen("data.in", "r", stdin);
    //ios_base :: sycn_with_stdio(false);
    //cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; ++ i) {
        cin >> v[i];
        v[N + i] = v[i];
    }

    for (int i = 1; i <= 2 * N; ++ i) {
        v[i] -= i;
        v[i] += 2 * N;
    }

    int val = 2 * N - 1;
    lint sumDown = 0;
    lint sumUp = 0;
    int cntDown = 0;
    int cntUp = 0;

    lint best = 5E18 + 15;
    int who = -1;

    for (int i = 1; i <= 2 * N; ++ i) {
        freq[v[i]] ++;
        if (v[i] >= val) {
            ++ cntUp;
            sumUp += v[i];
        }
        else {
            ++ cntDown;
            sumDown += v[i];
        }

        if (i - N >= 1) {
            freq[v[i - N]] --;
            if (v[i - N] >= val) {
                -- cntUp;
                sumUp -= v[i - N];
            }
            else {
                -- cntDown;
                sumDown -= v[i - N];
            }
        }

        if (i > N) {
            lint aux = sumUp - 1LL * val * cntUp + 1LL * val * cntDown - sumDown;

            if (aux < best) {
                best = aux;
                who = 2 * N - i;
            }

            val --;
            //Update
            cntUp += freq[val];
            sumUp += 1LL * freq[val] * val;

            cntDown -= freq[val];
            sumDown -= 1LL * freq[val] * val;
        }
    }

    cout << best << ' ' << who << '\n';
    return 0;
}
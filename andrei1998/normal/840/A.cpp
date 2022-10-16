#include <bits/stdc++.h>

using namespace std;

const int NMAX = 200000 + 5;

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

vector <pair <int, int> > a;
vector <pair <int, int> > b;

int sol[NMAX];

int main()
{
    //ios_base :: sync_with_stdio(false);
    //cin.tie(nullptr);
    InputReader cin;

    int N;
    cin >> N;

    a.resize(N);
    b.resize(N);

    for (int i = 0; i < N; ++ i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    for (int i = 0; i < N; ++ i) {
        cin >> b[i].first;
        b[i].second = i;
    }

    sort(a.begin(), a.end(), greater <pair <int, int> >());
    sort(b.begin(), b.end());

    for (int i = 0; i < N; ++ i)
        sol[b[i].second] = a[i].first;
    for (int i = 0; i < N; ++ i)
        cout << sol[i] << " \n"[i + 1 == N];
    return 0;
}
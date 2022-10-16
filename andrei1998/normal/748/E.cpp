#include <bits/stdc++.h>

using namespace std;

class InputReader {
  public:
    InputReader() {
        in = stdin;
        cursor = 0;
        fread(buffer, 1, SIZE, in);
    }
    InputReader(const char *input_file) {
        in = fopen(input_file, "r");
        cursor = 0;
        fread(buffer, 1, SIZE, in);
    }
    template <typename T>
    InputReader& operator>>(T &nr) {
        while (!isdigit(buffer[cursor]))
            advance();
        nr = 0;
        while (isdigit(buffer[cursor])) {
            nr *= 10;
            nr += buffer[cursor] - '0';
            advance();
        }
        return (*this);
    }
  private:
    FILE *in;
    static const int SIZE = (1 << 17);
    char buffer[SIZE];
    int cursor;
    void advance() {
        ++ cursor;
        if (cursor == SIZE) {
            cursor = 0;
            fread(buffer, 1, SIZE, in);
        }
    }
};

const int NMAX = 1000000 + 5;
typedef long long int lint;

int N;
lint K;
int a[NMAX];

lint get_cnt(int a, int b) {
    if (a < b) {
        return 0;
    }
    int val = a;
    lint cnt0 = 1, cnt1 = 0;
    while (val / 2 >= b) {
        lint new_cnt0 = cnt0;
        lint new_cnt1 = cnt1;
        if ((val + 1) / 2 == val / 2)
            new_cnt0 += cnt0 + cnt1;
        else
            new_cnt1 += cnt0 + cnt1;
        cnt0 = new_cnt0;
        cnt1 = new_cnt1;
        val = val / 2;
    }
    lint ans = cnt0 + cnt1;
    if ((val + 1) / 2 >= b) {
        ans += cnt1;
    }
    return ans;
}

bool works(const int b) {
    lint sum = 0;
    for (int i = 1; i <= N; ++i) {
        sum += get_cnt(a[i], b);
        if (sum >= K) {
            return true;
        }
    }
    return false;
}

int main() {
    InputReader cin;
    //ios_base :: sync_with_stdio(false);
    cin >> N >> K;
    lint sum = 0;
    int max_a = 1;
    for (int i = 1; i <= N; ++i) {
        cin >> a[i];
        max_a = max(max_a, a[i]);
        sum += a[i];
    }
    if (sum < K) {
        cout << "-1\n";
        return 0;
    }
    int l = 2, r = max_a;
    while (l <= r) {
        const int mid = (l + r) / 2;
        if (works(mid)) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    cout << l - 1 << endl;
    return 0;
}
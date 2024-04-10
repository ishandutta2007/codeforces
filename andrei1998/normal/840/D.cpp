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

const int NMAX = 300000 + 5;

vector <int> where[NMAX];
int getCnt(int val, int l, int r) {
    int itL = lower_bound(where[val].begin(), where[val].end(), l) - where[val].begin();
    int itR = upper_bound(where[val].begin(), where[val].end(), r) - where[val].begin();
    return itR - itL;
}

int N, Q;
int a[NMAX];
int l[NMAX], r[NMAX], k[NMAX], sol[NMAX];
vector <int> toTry[NMAX];

vector <int> starts[NMAX];
vector <int> endss[NMAX];

int freq[NMAX];
bool isInV[NMAX];
int whereInV[NMAX];

void divide(int st, int dr) {
    int mid = (st + dr) >> 1;

    for (int i = mid; i >= st; -- i) {
        freq[a[i]] = 0;
        isInV[a[i]] = 0;
        whereInV[a[i]] = 0;
    }

    vector <pair <int, int> > v;
    for (int i = mid; i >= st; -- i) {
        ++ freq[a[i]];

        if (!isInV[a[i]]) {
            whereInV[a[i]] = v.size();
            isInV[a[i]] = true;
            v.push_back({freq[a[i]], -a[i]});
        }
        else
            ++ v[whereInV[a[i]]].first;

        int pos = whereInV[a[i]];

        while (pos && v[pos] > v[pos - 1]) {
            swap(v[pos], v[pos - 1]);
            swap(whereInV[abs(v[pos].second)], whereInV[abs(v[pos - 1].second)]);
            pos --;
        }

        if (v.size() > 4) {
            isInV[abs(v.back().second)] = false;
            v.pop_back();
        }

        for (auto qr: starts[i]) {
            if (r[qr] > mid && r[qr] <= dr)
                for (auto it: v)
                    toTry[qr].push_back(abs(it.second));
        }
    }

    for (int i = mid + 1; i <= dr; ++ i) {
        freq[a[i]] = 0;
        isInV[a[i]] = 0;
        whereInV[a[i]] = 0;
    }

    v.clear();
    for (int i = mid + 1; i <= dr; ++ i) {
        ++ freq[a[i]];

        if (!isInV[a[i]]) {
            whereInV[a[i]] = v.size();
            isInV[a[i]] = true;
            v.push_back({freq[a[i]], -a[i]});
        }
        else
            ++ v[whereInV[a[i]]].first;

        int pos = whereInV[a[i]];

        while (pos && v[pos] > v[pos - 1]) {
            swap(v[pos], v[pos - 1]);
            swap(whereInV[abs(v[pos].second)], whereInV[abs(v[pos - 1].second)]);
            pos --;
        }

        if (v.size() > 4) {
            isInV[abs(v.back().second)] = false;
            v.pop_back();
        }

        for (auto qr: endss[i])
            if (l[qr] <= mid && l[qr] >= st)
                for (auto it: v)
                    toTry[qr].push_back(abs(it.second));
    }

    if (st != dr) {
        divide(st, mid);
        divide(mid + 1, dr);
    }
}

int main()
{
    InputReader cin;
    //freopen("data.in", "r", stdin);
    //ios_base :: sync_with_stdio(false);
    //cin.tie(nullptr);

    cin >> N >> Q;
    for (int i = 1; i <= N; ++ i) {
        cin >> a[i];
        where[a[i]].push_back(i);
    }

    for (int i = 1; i <= Q; ++ i) {
        cin >> l[i] >> r[i] >> k[i];
        if (l[i] < r[i]) {
            starts[l[i]].push_back(i);
            endss[r[i]].push_back(i);
        }
        else
            sol[i] = a[l[i]];
    }

    divide(1, N);
    for (int i = 1; i <= Q; ++ i)
        if (!sol[i]) {
            sort(toTry[i].begin(), toTry[i].end());
            sol[i] = -1;
            for (auto it: toTry[i])
                if (1LL * k[i] * getCnt(it, l[i], r[i]) > (r[i] - l[i] + 1)) {
                    sol[i] = it;
                    break;
                }
        }

    for (int i = 1; i <= Q; ++ i)
        cout << sol[i] << '\n';
    return 0;
}
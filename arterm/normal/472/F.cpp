#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define M 10100
#define A 31

int n, a[M], y[M], initial[M], initialY[M];
int basis[A], e;
bool inBasis[M];
bool w[A][A];
vector<pair<int, int>> ans;
vector<pair<int, int>> after_ans;

void add(int x, int y) {
    a[x] ^= a[y];
    ans.push_back(make_pair(x + 1, y + 1));
}

void swp(int x, int y) {
    if (x == y)
        return;
    ans.push_back(make_pair(x + 1, y + 1));
    ans.push_back(make_pair(y + 1, x + 1));
    ans.push_back(make_pair(x + 1, y + 1));
    swap(a[x], a[y]);
}

void addToBasis(int x) {
    int i = A - 1;
    while (((a[x] >> i) & 1) == 0)
        --i;
    basis[i] = x;
    for (int j = A - 1; j > i; --j)
        if (basis[j] != -1 && (a[basis[j]] >> i) & 1)
            add(basis[j], basis[i]);
}

void normalize(int x) {
    for (int i = A - 1; i >= 0; --i)
        if (basis[i] != -1 && (a[x] >> i) & 1) {
            add(x, basis[i]);
        }
}

bool makeY(int num, bool toAns) {
    int Y = y[num];
    for (int i = A - 1; i >= 0; --i)
        if (basis[i] != -1 && (Y >> i) & 1) {
            Y ^= a[basis[i]];
            if (toAns)
                add(num, basis[i]);
        }
    return Y == 0;
}



void read() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        initial[i + 1] = a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> y[i];
        initialY[i + 1] = y[i];
    }
}

void gaub() {
    fill(basis, basis + A, -1);
    for (int i = 0; i < n; ++i) {
        normalize(i);
        if (a[i] > 0) {
            addToBasis(i);
            inBasis[i] = true;
        }
    }
}

bool check() {
    for (int i = 0; i <= n; ++i)
        if (!makeY(i, !inBasis[i]))
            return false;
    return true;
}


void finish_him() {
    for (int i = A - 1; i >= 0; --i)
        if (basis[i] != -1) {
            int need = -1;
            for (int j = i; j >= 0; --j)
                if (basis[j] != -1 && (y[basis[j]] >> i) & 1)
                    need = j;

            if (need == -1) {
                add(basis[i], basis[i]);
                int Y = y[basis[i]];
                for (int j = i - 1; j >= 0; --j)
                    if (basis[j] != -1 && (Y >> j) & 1) {
                        Y ^= a[basis[j]];
                        add(basis[i], basis[j]);
                    }   
            }
            else {
                swp(basis[i], basis[need]);
                swap(basis[i], basis[need]);
                int Y = y[basis[i]];
                for (int j = i - 1; j >= 0; --j)
                    if (basis[j] != -1 && (Y >> j) & 1) {
                        Y ^= a[basis[j]];
                        add(basis[i], basis[j]);
                    }  

                for (int j = i - 1; j >= 0; --j)
                    if (basis[j] != -1 && (y[basis[j]] >> i) & 1) {
                        y[basis[j]] ^= a[basis[i]];
                        after_ans.push_back(make_pair(basis[j] + 1, basis[i] + 1));
                    }
            }
        }

    reverse(after_ans.begin(), after_ans.end());

    cout << ans.size() + after_ans.size() << "\n";

    for (auto & x : ans)
        cout << x.first << " " << x.second << "\n";
    for (auto & x : after_ans)
        cout << x.first << " " << x.second << "\n";
}

void doit() {
    for (auto & x : ans) {
        int a = x.first;
        int b = x.second;
        initial[a] ^= initial[b];
    }
    for (auto & x : after_ans) {
        int a = x.first;
        int b = x.second;
        initial[a] ^= initial[b];
    }

    for (int i = 1; i <= n; ++i, cout << " ")
        cout << initial[i];
    cout << "!\n";
    for (int i = 1; i <= n; ++i, cout << " ")
        cout << initialY[i];

}

int main() {
#ifdef TROLL
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    read();
    gaub();

    if (!check()) {
        cout << "-1\n";
        return 0;
    }
    
    finish_him();

    //doit();

    return 0;
}
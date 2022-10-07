#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 

#define equal equalll
#define less lesss
const int N = 7;
const int INF = 1e9 + 19;
const int MOD = 1e9 + 7;


const int n = 7;
const int sz = 1 << n;

void add(int & a, int b) {
    a = (a + b);
    if (a >= MOD) a -= MOD;
    //a = (a + b) % MOD;
}

int tmp[sz];

struct Matrix {
    vector < vector < int > > data;
    int size;
    Matrix(int size):size(size) { 
        data.assign(size, vector < int > (size, 0));
        //memset(data, 0, sizeof(data));
    }
    Matrix operator * (const Matrix & other) {
        assert(other.size == size);
        Matrix res(size);
        for (int j = 0; j < size; j++) {
            for (int i = 0; i < size; i++)
                tmp[i] = other.data[i][j];
            for (int i = 0; i < size; i++) {
                long long sum = 0;
                for (int k = 0; k < size; k++)
                    sum += (data[i][k] * 1ll * tmp[k]) % MOD;
                res.data[i][j] = sum % MOD;
            }
        }
        return res;
    }
    void print(int sz) {
        cerr << "matrix =====================\n";
        for (int i = 0; i < sz; i++, cerr << endl)
            for (int j = 0; j < sz; j++)
                cerr << data[i][j] << " ";
    }
};

int w[N];
int use[n];
int cur;


void read() {
    for (int i = 0; i < n; i++)
        scanf("%d", &w[i]);
}

Matrix binPow(Matrix a, long long b) {
    Matrix res(a.size);
    for (int i = 0; i < a.size; i++)
        res.data[i][i] = 1;
    for (; b > 0; b /= 2) {
        if (b % 2 == 1) 
            res = res * a;
        a = a * a;
    }
    return res;
}



void solve() {
    Matrix st(1); 
    st.data[0][0] = 1;
    for (int step = 1; step <= n; step++) {
        //db(step);
        Matrix go(1 << step);
        for (int mask = 0; mask < (1 << (step * 3 - 1)); mask++) {
            cur++;             
            int mask1 = mask & ((1 << step) - 1);
            int mask2 = (mask >> step) & ((1 << (step - 1)) - 1);
            int mask3 = (mask >> (step * 2 - 1)) & ((1 << step) - 1);
            for (int i = 0; i < step; i++) {
                if ((mask1 >> i) & 1)
                    use[i] = cur;
                if ((mask3 >> i) & 1)
                    use[i] = cur;
            }
            for (int i = 0; i < step - 1; i++) 
                if ((mask2 >> i) & 1) 
                    use[i] = use[i + 1] = cur;
            bool flag = 1;
            for (int i = 0; i < step; i++)
                flag &= use[i] == cur;
            if (flag) {
                //db("r1");
                //db2(mask1, mask3);
                go.data[mask1][mask3]++;
                //db("r2");
            }
        } 
        Matrix res = binPow(go, w[step - 1]);
        //go.print(10);
        Matrix tmp(1 << step);
        for (int i = 0; i < st.size; i++)
            for (int j = 0; j < st.size; j++)
                tmp.data[i][j] = st.data[i][j]; 

        st = tmp * res;
    }
    //db("here");
    printf("%d\n", st.data[0][0]);
    

}

void printAns() {

}

void stress() {

}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        int k = 1;
        for (int tt = 0; tt < k; tt++) {
            read();
            solve();
            printAns();
        }
    }
    else {
        stress();
    }

    return 0;
}
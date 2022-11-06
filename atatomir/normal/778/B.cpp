#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <unordered_map>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 5055
#define maxDim 1111

int n, m, i;
char data[maxN][maxDim];
int dim[maxN];

int nmax[maxN], nmin[maxN];
unordered_map<string, int> M;

int cnt;
int mem[maxN];

vector<int> ids[maxN];


bool is_char(char c) {
    return 'a' <= c && c <= 'z';
}

bool is_digit(char c) {
    return '0' <= c && c <= '9';
}

string get_name(char* &pos) {
    static string aux;

    aux.clear();
    while (is_char(*pos)) {
        aux.pb(*pos);
        pos++;
    }

    return aux;
}

int map_it(string &aux) {
    if (M[aux] == 0) M[aux] = ++cnt;
    return M[aux];
}

int check(int bit, int v) {
    int i, id;
    char* pos;
    string var, aux;

    int v1, v2, tp;
    int sol = 0;


    for (i = 1; i <= n; i++) {
        pos = data[i] + 1;

        var = get_name(pos); id = map_it(var);
        pos += 4;

        if (is_digit(*pos)) {
            pos += bit;
            mem[id] = *pos - '0';
            sol += mem[id];
        } else {

            if (*pos == '?') {
                v1 = v;
                pos += 2;
            } else {
                aux = get_name(pos);
                v1 = mem[M[aux]];
                pos++;
            }

            if (*pos == 'X') {
                tp = 0;
                pos += 4;
            }

            if (*pos == 'O') {
                tp = 1;
                pos += 3;
            }

            if (*pos == 'A') {
                tp = 2;
                pos += 4;
            }

            if (*pos == '?') {
                v2 = v;
                pos += 2;
            } else {
                aux = get_name(pos);
                v2 = mem[M[aux]];
                pos++;
            }


            if (tp == 0)
                v1 ^= v2;

            if (tp == 1)
                v1 |= v2;

            if (tp == 2)
                v1 &= v2;

            mem[id] = v1;
            sol += v1;
        }
    }

    return sol;
}

int main()
{
   // freopen("test.in","r",stdin);

    scanf("%d%d\n", &n, &m);
    for (i = 1; i <= n; i++) gets(data[i] + 1), dim[i] = strlen(data[i] + 1);

    for (int bit = 0; bit < m; bit++) {
        ll mini = check(bit, 0);
        ll maxi = check(bit, 1);

        if (mini < maxi) {
            nmin[bit] = 0;
            nmax[bit] = 1;
        }

        if (mini == maxi) {
            nmin[bit] = 0;
            nmax[bit] = 0;
        }

        if (mini > maxi) {
            nmin[bit] = 1;
            nmax[bit] = 0;
        }
    }

    for (i = 0; i < m; i++) printf("%d", nmin[i]); printf("\n");
    for (i = 0; i < m; i++) printf("%d", nmax[i]);


    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int n, m;
int fie[100][100], co[100], ro[100];
set <pair <int, int> > row, col;

void checkrow(int a, int b, int c){
    for (int i = 0; i < n - 2; i ++){
        for (int j = i + 1; j < n - 1; j++){
            int sum2 = 0, sum = 0, sum3 = 0;
            for (int k = 0; k <= i; k ++)
                sum += ro[k];
            if (sum == a){
                for (int k = i + 1; k <= j; k ++)
                    sum2 += ro[k];
                if (sum2 == b){
                    for (int k = j + 1; k < n; k ++)
                        sum3 += ro[k];
                    if (sum3 == c){
                        row.insert(make_pair(i, j));
                    }
                }

            }
        }
    }
}

void check(int a, int b, int c){
    for (int i = 0; i < m - 2; i ++){
        for (int j = i + 1; j < m - 1; j++){
            int sum2 = 0, sum = 0, sum3 = 0;
            for (int k = 0; k <= i; k ++)
                sum += co[k];
            if (sum == a){
                for (int k = i + 1; k <= j; k ++)
                    sum2 += co[k];
                if (sum2 == b){
                    for (int k = j + 1; k < m; k ++){
                        sum3 += co[k];
                    }
                    if (sum3 == c){
                        col.insert(make_pair(i, j));
                    }
                }

            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    fin >> n >> m;
    int a, b, c;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            fin >> fie[i][j];
            ro[i] += fie[i][j];
            co[j] += fie[i][j];
        }
    }
    fin >> a >> b >> c;
    checkrow(a, b, c);
    checkrow(a, c, b);
    checkrow(b, a, c);
    checkrow(b, c, a);
    checkrow(c, a, b);
    checkrow(c, b, a);
    check(a, b, c);
    check(a, c, b);
    check(b, a, c);
    check(b, c, a);
    check(c, a, b);
    check(c, b, a);
    fout << row.size() + col.size() << endl;
}
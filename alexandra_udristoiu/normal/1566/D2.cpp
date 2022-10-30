#include<iostream>
#include<algorithm>
using namespace std;
int t, n, i, sol, j, m, lst, nr, x, y, jj;
int v[100000];
pair<int, int > w[100005];
int a[305][305];
int main(){
    cin>> t;
    for (; t; t--) {
        cin>> n >> m;
        for (i = 1; i <= n * m; i++) {
            cin>> v[i];
            w[i] = make_pair(v[i], i);
        }
        sol = 0;
        lst = 1;
        nr = 0;
        sort(w + 1, w + n * m + 1);
        for (i = 1; i <= n * m; i++) {
            for (j = lst; j < i; j++) {
                if (w[j].second < w[i].second && w[i].first != w[j].first) {
                    sol++;
                }
            }
            if (i % m == 0) {
                lst = i + 1;
            }
        }
        cout<< sol <<"\n";
    }
}
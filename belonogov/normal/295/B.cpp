#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define fr first
#define sc second
#define epr(...) fprintf(stderr, __VA_ARGS__)


const int maxn = 600;

int a[maxn][maxn];
bool use[maxn];
long long ans[maxn];
int b[maxn];



int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n, v;
    long long sum = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    for(int i = 0; i < n; i++)
        scanf("%d", &b[i]), b[i]--;

    for(int k = n - 1; k >= 0; k--){
        use[b[k]] = 1;
        v = b[k];
        for(int i = 0; i < n; i++)
            if (use[i])
                for(int j = 0; j < n; j++)
                    if (use[j]){
                        a[v][i] = min(a[v][j] + a[j][i], a[v][i]);
                        a[i][v] = min(a[i][j] + a[j][v], a[i][v]);
                    }
        for(int i = 0; i < n; i++)
            if (use[i])
                for(int j = 0; j < n; j++)
                    if (use[j])
                         a[i][j] = min(a[i][v] + a[v][j], a[i][j]);
        sum = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                sum += (use[i] && use[j]) ? a[i][j] : 0;
        ans[k] = sum;
    }

    for(int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << "\n";



    return 0;

}
/*
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                a[i][j] = min(a[i][k] + a[k][j], a[i][j]);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            sum += a[i][j];

    for(int i = 0; i < n; i++){
        cout << sum << " ";
        scanf("%d", &v); v--;
        for(int j = 0; j < n; j++)
            if (!use[v][j]){
                sum -= a[v][j];
                use[v][j] = 1;
            }

        for(int j = 0; j < n; j++)
            if (!use[j][v]){
                sum -= a[j][v];
                use[j][v] = 1;
            }

    }
    printf("\n");*/
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int  maxn = 5e4 + 100;
struct node{
    int v, next;
};

node a[maxn * 2];
int head[maxn];
int uk = 0;
long long cnt = 0;
int b[maxn][510];
bool use[maxn];
int k;

void add(int v, int u){
    a[uk].v = u;
    a[uk].next = head[v];
    head[v] = uk;
    uk++;
}

void dfs(int v, int p){
    use[v] = true;
    int d = head[v];
    int j;
    while (d != -1){
        if (! use[a[d].v]){
            dfs(a[d].v, v);
            for (j = 0; j < k; j++)
                b[v][j + 1] += b[a[d].v][j]; 
        }
        d = a[d].next;
    }
    cnt = cnt + 2 * b[v][k];
    d = head[v];
    while (d != -1){
        if (a[d].v != p){
            for (j = 0; j < k - 1; j++)
                cnt = cnt + b[a[d].v][j] * (b[v][k - j - 1] - b[a[d].v][k - j - 2]);   
                
        }
        d = a[d].next;
    }

}


int main(){
    int n, i, x, y;
    cin >> n >> k;
    memset(head, -1, sizeof head);
    memset(use, 0, sizeof use);
    for (i = 0; i < n - 1; i++){
        cin >> x >> y;
        y--; 
        x--;
        add(x, y);
        add(y, x);
    }
    for (i = 0; i < n; i++)
        b[i][0] = 1;
    dfs(0, -1);
    cout << cnt / 2 ;

    return 0;
}
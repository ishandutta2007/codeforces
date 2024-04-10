#include<bits/stdc++.h>
 
#define ll long long
#define INF 2147483647
 
int inp(){
    char c = getchar();
    while(c < '0' || c > '9')
        c = getchar();
    int sum = 0;
    while(c >= '0' && c <= '9'){
        sum = sum * 10 + c - '0';
        c = getchar();
    }
    return sum;
}
 
std::vector<int> vec[100010];
 
bool used[100010];
int c[100010];
ll sum = 0, n;
 
void work(int x, int col){
    memset(used, false, sizeof(used));
    for(int i = 0; i < vec[x].size(); i++)
        used[vec[x][i]] = true;
    int size = 1;
    c[x] = col;
    for(int i = 1; i <= n; i++)
        if(!used[i] && i != x){
            if(c[i]){
                // printf("i = %d, x = %d, col = %d, c[i] = %d\n", i, x, col, c[i]);
                printf("-1\n");
                exit(0);
            }
            size++;
            c[i] = col;
        }
    sum += (ll)(size) * (ll)(n - size);
}
 
int main(){
    n = inp();
    int m = inp();
    int rt = 0;
    for(int i = 1; i <= m; i++){
        int u = inp();
        int v = inp();
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++)
        if(!c[i]){
            work(i, ++cnt);
            if(cnt > 3){
                puts("-1");
                return 0;
            }
        }
    // printf("cnt = %d, sum = %lld\n", cnt, sum);
    if(cnt != 3){
        printf("-1\n");
        return 0;
    }
    sum >>= 1;
    if(sum != m){
        printf("-1\n");
        return 0;
    }
    for(int i = 1; i <= n; i++)
        for(int j = 0; j < vec[i].size(); j++)
            if(c[i] == c[vec[i][j]]){
                printf("-1\n");
                return 0;
            }
    for(int i = 1; i <= n; i++)
        printf("%d ", c[i]);
    putchar('\n');
}
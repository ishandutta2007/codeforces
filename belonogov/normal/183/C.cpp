#include <iostream>
#include <cstdio>

using namespace std;
#define forn(i, n) for(i = 0; i < n; i++)
#define forab(i, a, b) for(i = a; i < b; i++)
#define forba(i, b, a) for(i = b; i > a; i--)

typedef long long ll;
typedef long double ld;
const int maxn = 2e5 + 2;
struct node{
    node * next;
    int v;
    int m;
};
node a[maxn];
node * head[maxn];
int b[maxn];
int uk;
int n, m, ans;
bool check1 = true;

void add(int v, int u, int m){
    node * q = & a[uk++];
    q->next = head[v];
    q->v = u;
    q->m = m;
    head[v] = q;
}

int evkl(int a, int b){
    if (b != 0) 
        return evkl(b, a % b); 
    return a;
}

bool dfs(int v, int col){
    node * q;
    //b[v] = col;
    for(q = head[v]; q != NULL; q = q->next){
        if (b[q->v] != -1){
            if (b[q->v] % ans != (b[v] + q->m) % ans){
                if (check1){
                    ans = abs(b[q->v] - (b[v] + q->m));
                    check1 = false;
                }
                else
                ans = evkl(ans, abs(b[q->v] - (b[v] + q->m)));
                return true;
            }
        }
        else{
            b[q->v] = b[v] + q->m;
            if (dfs(q->v, col + 1))
                return true;
        }
    }
    return false;

}





int main(){
    int i, x, y, v;
    bool check;
    memset(head, NULL, sizeof(head));
    cin >> n >> m;
    ans = n;
    forn(i, m){
        scanf("%d%d", &x, &y);
        if (x == y){
            cout << 1;
            return 0;
        }
        add(x - 1, y - 1, 1);
        add(y - 1, x - 1, -1); 
    }

    while(true){
        memset(b, -1, sizeof(b));
        check = true;
        forn(i, n)
            if (b[i] == -1){
                b[i] = ans * (n / ans + 1);
                if (dfs(i, ans * (n / ans + 1))){
                    check = false;
                    break;
                }
            }

        if (check){
            cout << ans;
            return 0;
        }
    }




    return 0;

}
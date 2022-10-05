#include <bits/stdc++.h>

using namespace std;

#define f first 
#define s second
#define pb push_back

typedef long long ll;      
typedef pair<int, int> pii;
typedef pair<long, long> pll;

const int N = 500500;

int n, m, k, s, a[N], cnt[N], was[N], cur[N];
vector< int > q[N];

void no(){
    printf("-1");
    exit(0);
}

int main(){
    scanf("%d%d%d%d", &m, &k, &n, &s);
    for(int i = 0; i < m; i++){
        scanf("%d", &a[i]);
    }
    for(int i = m - 1; i >= 0; i--)
        q[a[i]].pb(i);   
    
    for(int i = 0; i < s; i++){
        int x;
        scanf("%d", &x);
        cnt[x]++;
    }
    
    int mxdel = m - k * n;
    int mx = -1;

    for(int i = 0; i < m; i++){
        if(i == 0){
            for(int j = 0; j < N; j++)
                while(cur[j] < cnt[j]){
                    if(q[j].empty())
                        no();
                    mx = max(mx, q[j].back());
                    was[q[j].back()] = 1;
                    q[j].pop_back();
                    cur[j]++;
                }
            int cntdel = max(0, mx - i + 1 - k);
            if(cntdel <= mxdel){
                printf("%d\n", cntdel);
                for(int j = i; j < m; j++)
                    if(cntdel && !was[j]){
                        printf("%d ", j + 1);
                        cntdel--;
                    }  
                return 0;
            }
        }else{
            if(was[i - 1]){
                was[i - 1] = 0;
                int x = a[i - 1];
                if(q[x].empty())
                    no();
                mx = max(mx, q[x].back());
                was[q[x].back()] = 1;
                q[x].pop_back();
            }
            int cntdel = max(0, mx - i + 1 - k) + i % k;
            if(cntdel <= mxdel){
                printf("%d\n", cntdel);
                for(int j = 0; j < i % k; j++){
                    printf("%d ", j + 1);
                    cntdel--;
                }  
                for(int j = i; j < m; j++)
                    if(cntdel && !was[j]){
                        printf("%d ", j + 1);
                        cntdel--;
                    }  
                return 0;
            }
        }
    }
    return 0;
}
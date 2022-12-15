#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

int n,m,A,B,arr[3000][3000],ma[3000][3000];
void read() {
    scanf("%d%d%d%d",&n,&m,&A,&B);
    
    int g,x,y,z;
    scanf("%d%d%d%d",&g,&x,&y,&z);
    for(int i=0;i<n;i++)for(int j=0;j<m;j++) {
        if(!i && !j) arr[i][j]=g;
        else arr[i][j] = (1ll*g*x + y)%z, g = arr[i][j];
    }
}

int main() {
    read();

    for(int i=0;i<n;i++) {
        deque<pii> que;
        for(int j=0;j<m;j++) {
            while(!que.empty() && que.back().first >= arr[i][j]) que.pop_back();
            que.push_back({arr[i][j], j});
            if(j>=B-1) {
                while(!que.empty() && que.front().second <= j-B) que.pop_front();
                ma[i][j-B+1] = que.front().first;
            }
        }
    }
    
    long long ans=0;
    for(int j=0;j<=m-B;j++) {
        deque<pii> que;
        for(int i=0;i<n;i++) {
            while(!que.empty() && que.back().first >= ma[i][j]) que.pop_back();
            que.push_back({ma[i][j], i});
            if(i>=A-1) {
                while(!que.empty() && que.front().second <= i-A) que.pop_front();
                ans += que.front().first;
            }
        }
    }
    printf("%lld\n",ans);

    return 0;
}
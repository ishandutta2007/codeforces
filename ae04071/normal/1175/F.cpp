#include <bits/stdc++.h>
using namespace std;

int n,arr[300001],vis[300001],cnt[600001];

struct td{
    int l,r,v;
    td() {}
    td(int l,int r,int v):l(l),r(r),v(v) {}
};

int main() {
    scanf("%d",&n);
    
    deque<td> que;
    long long ans=0;
    for(int i=0;i<n;i++) {
        scanf("%d",arr+i);
        while(vis[arr[i]]) {
            td cur=que.front(); que.pop_front();
            vis[arr[cur.l]]=0;
            cnt[cur.v+cur.l-1]--;
            if(cur.l!=cur.r) que.push_front(td(cur.l+1,cur.r,cur.v)),cnt[cur.v+cur.l]++;
        }
        int ml=i;
        while(!que.empty() && que.back().v < arr[i])  {
            ml = que.back().l;
            cnt[que.back().v+que.back().l-1]--;
            que.pop_back();
        }
        que.push_back(td(ml,i,arr[i]));
        vis[arr[i]]=1;
        cnt[ml+arr[i]-1]++;
        ans += cnt[i];
    }
    printf("%lld\n",ans);
    return 0;
}
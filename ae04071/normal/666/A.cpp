#include <bits/stdc++.h>
using namespace std;

char str[50100];
set<string> ans;
int n,vis[50100];
int chk[50100][4];

int main() {
    scanf("%s",str);
    n=strlen(str);

    priority_queue<int> que;
    que.push(n);
    chk[n][2] = chk[n][3] = 1;
    vis[n]=1;
    while(!que.empty()) {
        int cur=que.top();que.pop();
        for(int d=2;d<=3;d++) if(cur-d>=5) {
            if(!chk[cur][d^1] && string(str+cur-d,str+cur)==string(str+cur,str+cur+d)) continue;

            ans.insert(string(str+cur-d,str+cur));
            chk[cur-d][d]=1;
            if(!vis[cur-d]) {
                vis[cur-d]=1;
                que.push(cur-d);
            }
        }
    }
    printf("%lu\n",ans.size());
    for(auto &it:ans) printf("%s\n",it.c_str());
    return 0;
}
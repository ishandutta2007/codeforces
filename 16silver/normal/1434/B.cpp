#include <bits/stdc++.h>
using namespace std;
int n;
char s[15];
vector<int> stk;
int ans[100000];
int cnt;
int inp[200000];
priority_queue<int> pq;
int main(){
    scanf("%d",&n);
    for(int i=0;i<2*n;i++){
        scanf("%s",s);
        if(s[0]=='-'){
            if(stk.empty()){
                puts("NO");
                return 0;
            }
            else{
                int tmp;
                scanf("%d",&tmp);
                ans[stk.back()] = tmp;
                stk.pop_back();
                inp[i] = -tmp;
            }
        }
        else{
            stk.push_back(cnt);
            inp[i] = cnt;
            cnt++;
        }
    }
    for(int i=0;i<2*n;i++){
        if(inp[i]<0){
            int tmp = pq.top();
            pq.pop();
            if(tmp != inp[i]){
                puts("NO");
                return 0;
            }
        }
        else{
            pq.push(-ans[inp[i]]);
        }
    }
    puts("YES");
    for(int i=0;i<n;i++){
        printf("%d ",ans[i]);
    }
}
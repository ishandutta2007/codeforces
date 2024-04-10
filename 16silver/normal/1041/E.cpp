#include <cstdio>
#include <vector>
#include <utility>
using namespace std;
vector<int> path[1001];
int cnt[1001];
int a[1001],b[1001];
int main(){
    int n,st,curridx,i;
    scanf("%d",&n);
    for(i=1;i<n;i++){
        scanf("%d%d",&a[i],&b[i]);
    }
    for(i=1;i<n;i++){
        if(b[i]!=n) break;
        cnt[a[i]]++;
    }
    if(i!=n || cnt[n-1] == 0){
        printf("NO\n");
    }
    else{
        cnt[n-1]--;
        path[n-1].push_back(n-1);
        st=cnt[n-1];
        curridx=n-1;
        for(i=n-2;i>=1;i--){
            if(cnt[i]==0){
                if(st==0) break;
                st--;
                path[curridx].push_back(i);
                cnt[curridx]--;
                for(;cnt[curridx]==0 && curridx > 0;curridx--);
            }
            else{
                path[i].push_back(i);
                cnt[i]--;
                st+=cnt[i];
                for(;cnt[curridx]==0 && curridx > 0;curridx--);
            }
        }
        if(i!=0){
            printf("NO\n");
        }
        else{
            printf("YES\n");
            for(i=n-1;i>=1;i--){
                if(path[i].size()>0){
                    for(int j=0;j<path[i].size()-1;j++){
                        printf("%d %d\n",path[i][j],path[i][j+1]);
                    }
                    printf("%d %d\n",path[i][path[i].size()-1],n);
                }
            }
        }
    }
}
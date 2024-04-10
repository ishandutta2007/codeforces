#include<cstdio>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
map<int,int>Map;
int n, w[101000], P[101000];
int v[101000];
vector<vector<int> >V;
int main(){
    int i, j;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
        Map[w[i]] = i;
    }
    sort(w+1,w+n+1);
    for(i=1;i<=n;i++){
        P[i] = Map[w[i]];
    }
    for(i=1;i<=n;i++){
        if(v[i])continue;
        int x = i;
        vector<int>TP;
        while(1){
            TP.push_back(x);
            v[x] = 1;
            x = P[x];
            if(x==i)break;
        }
        sort(TP.begin(),TP.end());
        V.push_back(TP);
    }
    printf("%d\n",V.size());
    for(i=0;i<V.size();i++){
        printf("%d ",V[i].size());
        for(j=0;j<V[i].size();j++)printf("%d ",V[i][j]);
        printf("\n");
    }
}
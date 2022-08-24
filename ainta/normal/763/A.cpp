#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>E[101000];
int w[101000], UF[101000], n, cnt;
bool v[101000];
int Find(int a){
    if(a==UF[a])return a;
    return UF[a] = Find(UF[a]);
}
void Merge(int a, int b){
    a = Find(a), b = Find(b);
    if(a!=b)UF[a] = b;
}
int main(){
    int i, a, b, j;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        UF[i] = i;
    }
    for(i=1;i<n;i++){
        scanf("%d%d",&a,&b);
        E[a].push_back(b);
        E[b].push_back(a);
    }
    for(i=1;i<=n;i++)scanf("%d",&w[i]);
    for(i=1;i<=n;i++){
        for(j=0;j<E[i].size();j++){
            a = E[i][j];
            if(w[a] == w[i]){
                Merge(a, i);
            }
        }
    }
    for(i=1;i<=n;i++){
        if(!v[Find(i)]){
            v[Find(i)] = true;
            cnt++;
        }
    }
    for(i=1;i<=n;i++){
        v[i]=false;
    }
    for(i=1;i<=n;i++){
        v[Find(i)] = true;
        int c = 1;
        for(j=0;j<E[i].size();j++){
            a = E[i][j];
            if(!v[Find(a)]){
                v[Find(a)] = true;
                c++;
            }
        }
        if(c==cnt){
            printf("YES\n%d\n",i);
            return 0;
        }
        v[Find(i)]=false;
        for(j=0;j<E[i].size();j++){
            a = E[i][j];
            v[Find(a)] = false;
        }
    }
    printf("NO\n");
}
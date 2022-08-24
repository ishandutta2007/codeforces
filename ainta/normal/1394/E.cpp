#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int w[101000], n, D[101000], S, Right[101000];
vector<int>G[101000];
vector<int>V[101000];
int main(){
    int i, Q;
    scanf("%d",&Q);
    while(Q--){
        n++;
        scanf("%d",&w[n]);
        if(n>1 && w[n]==w[n-1])V[n].push_back(n-1);
        for(auto &t : V[n-1]){
            if(w[n] != w[t-1])continue;
            V[n].push_back(t-1);
        }
        for(auto &t : V[n]){
            if(!Right[t-1]){
                Right[t-1] = n;
                G[n].push_back(t-1);
            }
        }
        while(1){
            int r = -1;
            for(auto &t : V[n]){
                int l = (n-t+1)/2;
                int x = n-l, ck = 0;
                for(auto &y : V[x]){
                    if(x-y == n-t){
                        ck=1;
                        break;
                    }
                }
                if(ck){
                    r=l*2;
                    break;
                }
            }
            if(r==-1)break;
            for(i=0;i<r;i++){
                for(auto &t : G[n])Right[t] = 0;
                G[n].clear();
                V[n].clear();
                n--;
            }
            S+=2;
        }
        int rr = n, c = 0;
        while(!V[rr].empty()){
            rr -= (rr-V[rr][0]+1)/2;
            c++;
        }
        int l = 0;
        while(Right[l] && Right[l]<=rr){
            l+=(Right[l]-l)/2;
            c++;
        }
        printf("%d ",S+c);
    }
}
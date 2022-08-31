#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#define pii pair<int,int>
using namespace std;
vector<pii>E[100100];
priority_queue<int>PQ;
int C[100100], CC[100100];
int In[101000], L[1010], CL, R[2010];
int n, w[101000], Q, cnt;
long long Ans[101000];
void Ins(int a, int b){
    CC[C[a]]--;
    C[a]+=b;
    CC[C[a]]++;
    if(C[a] >= 600 && !In[a]){
        In[a] = 1;
        L[++CL] = a;
    }
}
void Do(int pb, int b, int num){
    int i, j;
    for(i=pb;i<b;i++){
        Ins(w[i],-1);
    }
    for(i=1;i<=CL;i++){
        if(C[L[i]] >= 600){
            PQ.push(-C[L[i]]);
        }
    }
    long long Res = 0;
    for(i=1;i<600;i++){
        R[i] = CC[i];
    }
    for(i=600;i<=1200;i++)R[i] = 0;
    for(i=1;i<600;i++){
        R[i*2] += R[i]/2;
        Res += (R[i]/2)*2*i;
        R[i]%=2;
        if(R[i]){
            for(j=i+1;j<600;j++)if(R[j])break;
            if(j != 600){
                R[j]--;R[i]--;
                R[i+j]++;
                Res += i+j;
                i = j-1;
                continue;
            }
            else{
                PQ.push(-i);
                break;
            }
        }
    }
    for(i=600;i<=1200;i++){
        while(R[i]){
            R[i]--;
            PQ.push(-i);
        }
    }
    while(PQ.size() > 1){
        int t1 = PQ.top();
        PQ.pop();
        int t2 = PQ.top();
        PQ.pop();
        Res += (-t1-t2);
        PQ.push(t1+t2);
    }
    while(!PQ.empty())PQ.pop();
    Ans[num] = Res;
    for(i=pb;i<b;i++){
        Ins(w[i],1);
    }
}
int main(){
    int i, b, e, j, k;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
    }
    scanf("%d",&Q);
    for(i=1;i<=Q;i++){
        scanf("%d%d",&b,&e);
        E[e].push_back(pii(b,i));
    }
    for(i=1;i<=n;i+=300){
        for(j=0;j<=100000;j++)C[j] = CC[j] = In[j] = 0;
        CL = 0;
        for(j=i;j<=n;j++){
            Ins(w[j], 1);
            for(k=0;k<E[j].size();k++){
                if(E[j][k].first >= i && E[j][k].first < i+300){
                    Do(i, E[j][k].first, E[j][k].second);
                }
            }
        }
    }
    for(i=1;i<=Q;i++){
        printf("%lld\n",Ans[i]);
    }
}
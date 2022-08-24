#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
int n, cc;
struct point{
    char p[11];
    int ck, s, x;
}w[101000];
vector<int>A;
vector<int>B;
vector<int>P1, P2;
set<int>Set;
void Move(int num, int t){
    printf("move %s %d\n",w[num].p, t);
    if(w[num].s >= 1 && w[num].s <= n) Set.insert(w[num].s);
    w[num].s = t;
    if(t)Set.erase(t);
}
void Do(int num, int ck){
    int t = 0;
    if(ck == 1) t = *Set.lower_bound(1);
    else t = *Set.lower_bound(cc + 1);
    Move(num, t);
}
int main(){
    int i, j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)Set.insert(i);
    for(i=1;i<=n;i++){
        scanf("%s%d",w[i].p,&w[i].ck);
        int s = 0, chk = 0;
        for(j=0;w[i].p[j];j++) {
            if(w[i].p[j]>='0' && w[i].p[j]<='9'){
                s=s*10 + w[i].p[j]-'0';
                if(!s)chk = 1;
            }
            else break;
        }
        if(w[i].p[j] || chk || s > n || s <= 0){
            w[i].s = -1;
            if(w[i].ck)P1.push_back(i);
            else P2.push_back(i);
        }
        else{
            w[i].s = s;
            Set.erase(s);
        }
        if(w[i].ck)cc++;
    }
    for(i=1;i<=n;i++){
        if(w[i].s != -1){
            if(w[i].s <= cc && w[i].ck)continue;
            if(w[i].s > cc && !w[i].ck)continue;
            if(w[i].s <= cc){
                A.push_back(i);
            }
            else{
                B.push_back(i);
            }
        }
    }
    if(!P1.empty() || !P2.empty()){
        printf("%d\n",A.size()+B.size()+P1.size()+P2.size());
        while(!A.empty() || !B.empty()){
            if(!A.empty() && Set.lower_bound(cc+1) != Set.end()){
                Do(A.back(), 2);
                A.pop_back();
            }
            else{
                Do(B.back(), 1);
                B.pop_back();
            }
        }
        while(!P1.empty()){
            Do(P1.back(),1);
            P1.pop_back();
        }
        while(!P2.empty()){
            Do(P2.back(),2);
            P2.pop_back();
        }
    }
    else{
        if(A.empty()){
            printf("0\n");
            return 0;
        }
        printf("%d\n",A.size()+B.size()+1);
        int tp = A.back();
        Move(tp, 0);
        A.pop_back();
        while(!A.empty() || !B.empty()){
            if(!A.empty() && Set.lower_bound(cc+1) != Set.end()){
                Do(A.back(), 2);
                A.pop_back();
            }
            else{
                Do(B.back(), 1);
                B.pop_back();
            }
        }
        printf("move 0 %d\n",*Set.lower_bound(cc+1));
    }
}
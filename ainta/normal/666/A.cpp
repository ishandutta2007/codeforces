#include<stdio.h>
#include<algorithm>
#include<set>
#include<string>
using namespace std;
set<string>Set;
char p[10100], q[10];
int Pos[10100][4];
int n;
int main(){
    int i, j;
    scanf("%s",p);
    for(i=0;p[i];i++);
    n = i;
    Pos[n][2]=Pos[n][3] = 1;
    for(i=n-2;i>=0;i--){
        int ck1=0,ck2=0;
        if(Pos[i+2][2])ck1 = 1;
        if(Pos[i+3][3])ck2 = 1;
        if(n-i>=4){
            for(j=0;j<2;j++){
                if(p[i+j]!=p[i+2+j])break;
            }
            if(j==2)ck1 = 0;
        }
        if(n-i>=6){
            for(j=0;j<3;j++){
                if(p[i+j]!=p[i+3+j])break;
            }
            if(j==3)ck2 = 0;
        }
        if(Pos[i+2][3])ck1 = 1;
        if(Pos[i+3][2])ck2 = 1;
        if(ck1) Pos[i][2]=1;
        if(ck2) Pos[i][3]=1;
    }
    for(i=5;i<n;i++){
        if(Pos[i][2]){
            for(j=0;j<2;j++)q[j] = p[i+j];
            q[j]=0;
            Set.insert(q);
        }
        if(Pos[i][3]){
            for(j=0;j<3;j++)q[j] = p[i+j];
            q[j]=0;
            Set.insert(q);
        }
    }
    set<string>::iterator it;
    int cnt = 0;
    for(it = Set.begin();it!=Set.end();it++)cnt++;
    printf("%d\n",cnt);
    for(it = Set.begin();it!=Set.end();it++)printf("%s\n",(*it).c_str());
}
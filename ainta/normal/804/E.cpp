#include<cstdio>
#include<algorithm>
using namespace std;
int w5[10][2]={{1,2},{1,3},{1,4},{2,3},{2,5},{3,5},{1,5},{3,4},{2,4},{4,5}};
int w4[6][2]={{1,2},{3,4},{1,3},{2,4},{1,4},{2,3}};
int w8[16][2]={{1,1},{2,2},{3,3},{4,4},{1,2},{2,1},{3,4},{4,3},{1,3},{3,1},{2,4},{4,2},{1,4},{4,1},{2,3},{3,2}};
void Put(int a, int b){
    printf("%d %d\n",a,b);
}
void Print4(int b){
    int i;
    for(i=0;i<6;i++)Put(b+w4[i][0],b+w4[i][1]);
}
void Print8(int a, int b){
    int i;
    for(i=0;i<16;i++)Put(a+w8[i][0],b+w8[i][1]);
}
void Print5(int a, int b){
    int i, s, t;
    for(i=0;i<10;i++){
        s = w5[i][0]+a, t = w5[i][1];
        if(t == 5) t = b;
        else t+=a;
        Put(s,t);
    }
}
void Do(int n){
    if(n==1)return;
    if(n==4){
        Print4(0);
        return;
    }
    if(n==5){
        Print5(0,5);
        return;
    }
    int i;
    for(i=0;i<n-5;i+=4){
        Print8(i, n-4);
    }
    if(n%4==0)Print4(n-4);
    else Print5(n-5,n);
    Do(n-4);
}
int main(){
    int n;
    scanf("%d",&n);
    if(n%4>1){
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    Do(n);
}
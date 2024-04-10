#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <vector>
#include <ctime>
#include <map>

using namespace std;
#define PB push_back
#define MP make_pair
#define eps 1e-8

struct point{
    double x,y;
    point(double x=0.,double y=0.):x(x),y(y){}
    point operator+(point b){return point(x+b.x,y+b.y);}
    point operator-(point b){return point(x-b.x,y-b.y);}
    point operator*(double t){return point(x*t,y*t);}
    point operator/(double t){return point(x/t,y/t);}
    double dis(){return x*x+y*y;}
    double dist(){return sqrt(dis());}
    void get(){scanf("%lf%lf",&x,&y);}
    void show(){printf("%.3f %.3f\n",x,y);}
};
double det(point a,point b){return a.x*b.y-a.y*b.x;}
double dot(point a,point b){return a.x*b.x+a.y*b.y;}

string s;
int n;
int num[26];
int f[2000];
int cnt[2000];

bool isprime(int i){
    for (int j=2;j<i;j++) if (i%j==0) return false;
    return true;
}
void add(int i,int j){
    i--;j--;
    if (f[i]==f[j]) return;
    int t=f[i];
    for (int z=0;z<n;z++) if (f[z]==t) f[z]=f[j];
}
int main(){
    cin>>s;
    n=s.size();
    for (int i=0;i<n;i++) f[i]=i;
    for (int i=2;i<=n;i++) if (isprime(i)){
        for (int j=i+i;j<=n;j+=i) add(i,j);
    }
    memset(num,0,sizeof(num));
    for (int i=0;i<n;i++) num[s[i]-'a']++;
    //for (int i=0;i<n;i++) printf("%d ",f[i]);puts("");
    memset(cnt,0,sizeof(cnt));
    for (int i=0;i<n;i++) cnt[f[i]]++;
    int t=0;
    for (int i=0;i<n;i++) if (cnt[i]>cnt[t]) t=i;
    int co=0;
    for (int i=1;i<26;i++) if (num[i]>num[co]) co=i;
    if (num[co]<cnt[t]){
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    num[co]-=cnt[t];
    for (int i=0,j=0;i<n;i++) if (f[i]==t) printf("%c",'a'+co);
    else{
        for (;num[j]==0;j++);
        num[j]--;
        printf("%c",'a'+j);
    }
    puts("");
}
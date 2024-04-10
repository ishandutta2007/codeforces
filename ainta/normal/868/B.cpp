#include<cstdio>
#include<algorithm>
using namespace std;
struct A{
    double a;
    int num;
    bool operator <(const A &p)const{
        return a<p.a;
    }
}w[6];
int main(){
    int hh, mm, ss, p1, p2, i;
    scanf("%d%d%d%d%d",&hh,&mm,&ss,&p1,&p2);
    double hA = ((hh%12)*3600+mm*60+ss) * 360.0 /43200;
    double mA = (mm*60+ss) * 360.0 / 3600;
    double sA = ss * 360.0 / 60;
    double A1 = p1*30.0, A2 = p2*30.0;
    w[0]={hA,1};
    w[1]={mA,2};
    w[2]={sA,3};
    w[3]={A1,4};
    w[4]={A2,5};
    sort(w,w+5);
    for(i=0;i<5;i++){
        if(w[i].num+w[(i+1)%5].num == 9){
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    
}
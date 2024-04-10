#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<utility>
#include<algorithm>
#include<cstring>
#include<cassert>
#define N 1010
#define X first
#define Y second
using namespace std;
struct point{
    long long x,y;
    point(){}
    point(long long _x,long long _y):x(_x),y(_y){}
    point operator+(point r)const{return point(x+r.x,y+r.y);}
    point operator-(point r)const{return point(x-r.x,y-r.y);}
    long long operator^(point r)const{return x*r.y-y*r.x;}
    double len()const{return sqrt(1.0*x*x+1.0*y*y);}
}p[N];
typedef pair<double,double> pdd;
long long get_input(){
    char s[100];
    scanf("%s",s);
    int a,b=0,now=0,sign=1;
    if(s[0]=='-') sign=-1;
    while(s[now]&&s[now]!='.') now++;
    if(s[now]=='.'){
        if(s[now+1]&&s[now+2]) b=(s[now+1]-'0')*10+(s[now+2]-'0');
        else if(s[now+1]) b=(s[now+1]-'0')*10;
    }
    s[now]=0;
    if(now) a=atoi(s);
    else a=0;
    return (a*100+b*sign);
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        p[i].x=get_input();
        p[i].y=get_input();
    }
    for(int k=0;k<m;k++){
        point la,lb;
        vector<pdd> v1,v2;
        la.x=get_input();
        la.y=get_input();
        lb.x=get_input();
        lb.y=get_input();
        double ans=0;
        for(int i=0;i<n;i++){
            int j=(i+1)%n;
            long long ai=(la-lb)^(p[i]-lb),aj=(la-lb)^(p[j]-lb);
            if((ai>=0)^(aj>=0)){
                v1.push_back(pdd((1.0*p[j].x*ai-1.0*p[i].x*aj)/(ai-aj),(1.0*p[j].y*ai-1.0*p[i].y*aj)/(ai-aj)));
            }
            if((ai<=0)^(aj<=0)){
                v2.push_back(pdd((1.0*p[j].x*ai-1.0*p[i].x*aj)/(ai-aj),(1.0*p[j].y*ai-1.0*p[i].y*aj)/(ai-aj)));
            }
            if(ai==0&&aj==0){
                ans+=(p[j]-p[i]).len();
            }
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        assert(v1.size()%2==0);
        assert(v2.size()%2==0);
        for(int j=0;j<v1.size();j+=2){
            ans+=sqrt(pow(v1[j+1].X-v1[j].X,2)+pow(v1[j+1].Y-v1[j].Y,2));
        }
        for(int j=0;j<v2.size();j+=2){
            ans+=sqrt(pow(v2[j+1].X-v2[j].X,2)+pow(v2[j+1].Y-v2[j].Y,2));
        }
        printf("%.12f\n",ans/200);
    }
    return 0;
}
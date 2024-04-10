#include<cstdio>
#include<vector>
#define eps 1e-7
using namespace std;
struct point{
    double x;
    double y;
    point(){}
    point(double _x,double _y):x(_x),y(_y){}
    point operator-(point r)const{return point(x-r.x,y-r.y);}
    point operator+(point r)const{return point(x+r.x,y+r.y);}
    point operator*(double c)const{return point(x*c,y*c);}
    point operator/(double c)const{return point(x/c,y/c);}
    double operator*(point r)const{return x*r.x+y*r.y;}
    double operator^(point r)const{return x*r.y-y*r.x;}
    bool operator==(point r)const{return x-r.x<eps&&r.x-x<eps&&y-r.y<eps&&r.y-y<eps;}
    bool operator!=(point r)const{return !(operator==(r));}
};
double tri(point a,point b,point c){
    return (b-a)^(c-a);
}
bool up(point a,point b,point c){
    return tri(a,b,c)>-eps;
}
point intersect(point a1,point a2,point b1,point b2){
    double t1=tri(b1,b2,a1);
    double t2=-tri(b1,b2,a2);
    return (a1*t2+a2*t1)/(t1+t2);
}
int main(){
    vector<point> skyline[500],temp;
    int a[500],i,j,l,n,k;
    bool pre,now;
    double ans[500]={0};
    scanf("%d%d",&n,&k);
    for(i=0;i<k;i++){
        skyline[i].push_back(point(i,0));
        skyline[i].push_back(point(i+1,0));
    }
    for(i=0;i<n;i++){
        for(j=0;j<=k;j++) scanf("%d",&a[j]);
        for(j=0;j<k;j++){
            point first(j,a[j]),last(j+1,a[j+1]),inter;
            vector<point> cal;
            temp.clear();
            if(skyline[j][0].y>a[j]-eps){
                temp.push_back(skyline[j][0]);
                pre=true;
            }
            else{
                temp.push_back(first);
                cal.push_back(first);
                cal.push_back(skyline[j][0]);
                pre=false;
            }
            for(l=1;l<skyline[j].size();l++){
                now=up(first,last,skyline[j][l]);
                if(now^pre) inter=intersect(first,last,skyline[j][l-1],skyline[j][l]);
                if(pre&&!now){
                    cal.push_back(inter);
                    cal.push_back(skyline[j][l]);
                    temp.push_back(inter);
                }
                else if(!pre&&now){
                    if(cal.size()>=2){
                        ans[i]+=0.5*tri(cal[0],cal.back(),inter);
                    }
                    cal.clear();
                    temp.push_back(inter);
                    temp.push_back(skyline[j][l]);
                }
                else if(!pre&&!now){
                    cal.push_back(skyline[j][l]);
                    if(cal.size()>=3){
                        ans[i]+=0.5*tri(cal[0],cal[cal.size()-2],cal[cal.size()-1]);
                    }
                }
                else{
                    temp.push_back(skyline[j][l]);
                }
                pre=now;
            }
            if(!pre){
                temp.push_back(last);
                if(cal.size()>=2) ans[i]+=0.5*tri(cal[0],cal.back(),last);
            }
            skyline[j].clear();
            for(l=0;l<temp.size();l++){
                if(skyline[j].empty()) skyline[j].push_back(temp[l]);
                else if(temp[l]!=skyline[j].back()) skyline[j].push_back(temp[l]);
            }
        }
    }
    for(i=0;i<n;i++) printf("%.6f\n",ans[i]);
    return 0;
}
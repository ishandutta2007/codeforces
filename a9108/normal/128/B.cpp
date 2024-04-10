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
#include <set>
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
set<pair<char,int> > a;
string s;
int k,n;

string getans(int k){
    string st="";
    for (;;){
        //printf("%d %d %s\n",a.size(),k,(*a.begin()).first.c_str());
        char ss=(*a.begin()).first;
        long long tot=0;
        vector<pair<char,int> > t;
        t.clear();
        for (;!a.empty();){
            if ((*a.begin()).first!=ss) break;
            t.PB(*a.begin());
            tot+=n-t[t.size()-1].second-st.size()-1;
            a.erase(a.begin());
        }
        if (k<=t.size()) return st+ss;
        k-=t.size();
        if (k>tot) k-=tot;
        else {
            a.clear();
            st+=ss;
            for (int i=0;i<t.size();i++){
                if (t[i].second+st.size()<n){
                    a.insert(MP(s[t[i].second+st.size()],t[i].second));
                }
            }
        }
    }
}

int main(){
    cin>>s>>k;
    n=s.size();
    long long tot=n*(long long)(n+1)/2;
    if (k>tot) {
        printf("No such line.\n");
        return 0;
    }
    a.clear();
    for (int i=0;i<n;i++) a.insert(MP(s[i],i));
    printf("%s\n",getans(k).c_str());
}
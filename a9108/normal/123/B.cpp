#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <queue>
#include <vector>
#include <ctime>
#include <map>

using namespace std;
#define PB push_back
#define MP make_pair
#define eps 1e-8

long long a,b,x1,x2,y1,y2;

long long f(long long a,long long b){
    if (a>=0) return a/b;
    return -(-a/b)-1;
}

long long getans1(){
    long long l=x1+y1,r=x2+y2;
    if (l>r) swap(l,r);
    return f(r,a+a)-f(l,a+a);
}
long long getans2(){
    long long l=x1-y1,r=x2-y2;
    if (l>r) swap(l,r);
    return f(r,b+b)-f(l,b+b);
}
int main(){
    cin>>a>>b>>x1>>y1>>x2>>y2;
    //cout<<getans1()<<' '<<getans2()<<endl;
    cout<<max(getans1(),getans2())<<endl;
}
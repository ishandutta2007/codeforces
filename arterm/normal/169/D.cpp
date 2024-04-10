#include <iostream>
#include <algorithm>


#define N 100100
#define f first
#define s second
#define INF 100100

using namespace std;

struct lemm{
    long m,v,id;
};

long n,k,h;
lemm l[N];

bool cmp(lemm x, lemm y){
    if (x.m<y.m)
    return 1;
    if (x.m>y.m)
    return 0;
    if (x.v<y.v)
    return 1;
    return 0;
}

void read(void){
    cin>>n>>k>>h;
    for (long i=0; i<n; ++i)
    cin>>l[i].m;
    for (long i=0; i<n; ++i){
        cin>>l[i].v;
        l[i].id=i+1;
    }
    sort(l,l+n,cmp);
    //for (long i=0; i<n; ++i)
    //cout<<l[i].m<<" "<<l[i].v<<" "<<l[i].id<<"\n";
}

bool try_(double t){
    long j=1;
    for (long i=0; i<n && j<=k; ++i)
    if (l[i].v*t>=j)
    ++j;
    return j>k;
}

void writeans(double t){
    long j=1;
    for (long i=0; i<n && j<=k; ++i)
    if (l[i].v*t>=j){
        cout<<l[i].id<<" ";
        ++j;
    }
}

void bs(void){
    double rb=INF, lb=0,m;
    for (long i=0; i<100; ++i){
        m=(lb+rb)/2;
        try_(m) ? rb=m:lb=m;
    }
    writeans(rb);
}



int main()
{
    read();
    bs();
    return 0;
}
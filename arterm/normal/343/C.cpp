#include <iostream>
#include <algorithm>

#define M 100100
#define long long long

using namespace std;

int n,m;
long h[M],p[M];

void read(){
    cin>>n>>m;
    for (int i=0; i<n; ++i)
        cin>>h[i];
    for (int j=0; j<m; ++j)
        cin>>p[j];
}

bool possibleToGo(long time, long head, long left, long right){
    if (right<=head)
        return head-left<=time;
    if (head<=left)
        return right-head<=time;
    long whole=right-left;
    return min((head-left),(right-head))+whole<=time;
}

bool isPossible(long time){
    int right=0;
    for (int i=0; i<n; ++i){
        int old=right;
        while (right<m && possibleToGo(time,h[i],p[old],p[right]))
            right++;
    }
    return right==m;
}

void binSearch(){
    long l=0,r=1ll*1000*1000*1000*1000,m;
    while (l<r){
        m=(l+r)/2;
        if (isPossible(m))
            r=m;
        else
            l=m+1;
    }
    cout<<l<<"\n";
}


int main(){
    read();
    binSearch();
    return 0;
}
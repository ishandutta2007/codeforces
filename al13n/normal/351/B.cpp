#include<iostream>
using namespace std;
#define forn(i,n) for(int i=0;i<(n);++i)

int src[3100];
int n;

int main()
{
    cin>>n;
    forn(i,n){
        cin>>src[i];
    }
    int r=0;
    forn(i,n){
    forn(j,i){
    if(src[j]>src[i])
        ++r;
    }
    }
    cout<<r/2*4+r%2;

    return 0;
}
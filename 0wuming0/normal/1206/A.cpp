#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"math.h"
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
int main()
{
    int n,m;
    int a[305],b[305];
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    cin>>m;
    for(int i=0;i<m;i++)cin>>b[i];
    sort(a,a+n);
    sort(b,b+m);
    cout<<a[n-1]<<' '<<b[m-1]<<endl;

    return 0;
}
/*

*/
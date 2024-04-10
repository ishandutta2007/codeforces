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
    int _2[40]={1};
    for(int i=1;i<30;i++)_2[i]=2*_2[i-1];
    int l,r,n;
    cin>>n>>l>>r;
    cout<<_2[l]-1+(n-l)*1<<' '<<_2[r]-1+(n-r)*_2[r-1]<<endl;
    return 0;
}
/*
1000 20 20
1000 19 19
*/
#include"bits/stdc++.h"
using namespace std;
int main()
{
    long long A,B,C;
    cin>>A>>B>>C;
    long long t=sqrt(A*B*C+1);
    cout<<4*(t/A+t/B+t/C)<<endl;
    return 0;
}
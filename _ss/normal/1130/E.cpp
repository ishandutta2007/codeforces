#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
const ll maxn=1e5+1;
int k;
int main()
{
    cin>>k;
    int h=min(int(sqrt(k)),1500);
    int a=(k+h-1)/h,t=h*a-k;
    if (t==0)
    {
        h++;
        t=a;
    }
    int x=a+t;
    cout<<h+1<<endl;
    for (int i=1;i<=h-1;i++) cout<<0<<" ";
    cout<<-t<<" "<<x;
    return 0;
}
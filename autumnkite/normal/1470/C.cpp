#include <bits/stdc++.h>
using namespace std;
mt19937 R(time(0));
int n,k,x,v;
void Q(int t){x=t;cout<<"? "<<x+1<<endl;cin>>v;}
int main(){cin>>n>>k;v=k;while(v==k)Q(R()%n);while(v!=k)Q((x+(v<k?1:n-1))%n);cout<<"! "<<x+1<<endl;}
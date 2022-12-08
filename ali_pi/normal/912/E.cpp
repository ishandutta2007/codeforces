#include<bits/stdc++.h>

#define ll long long
#define ld long double
using namespace std;

ll p1[10],p2[15];
vector<ll> v1,v2;
ll n1,n2;

void solv1(ll x,int q){
if(q==n1){
    v1.push_back(x);return;
}
while(1){
solv1(x,q+1);
if(x>1e18/p1[q])break;
x*=p1[q];
}
}
void solv2(ll x ,int q){
if(q==n2){
    v2.push_back(x);return;
}
while(1){
solv2(x,q+1);
if(x>1e18/p2[q])break;
x*=p2[q];
}
}
int main(){
int n;
cin>>n;
for(int i=0;i<n;i++){
    if(i>5)cin>>p2[i-6];
    else cin>>p1[i];
}
 n1=min(6,n);
 n2=max(n-n1,0ll);
solv1(1,0);
solv2(1,0);
ll k ;
cin>>k;
sort(v1.begin(),v1.end());
sort(v2.begin(),v2.end());
ll st=0,nd=1e18;
while(st+1<nd){
    ll mid=(st+nd)/2;
    ll sum=0;
    for(auto c:v1)sum+=upper_bound(v2.begin(),v2.end(),mid/c)-v2.begin();
    if(sum>=k)nd=mid;
    else st=mid;
}
cout<<st+1<<endl;
}
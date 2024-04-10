#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second

typedef long long ll;


int mod = 1000000000+7;
const int N=1000011;

int n;
int main(){
    cin>>n;
    ll c[n],t[n];
    for(int i=0;i<n;i++){
        scanf("%lld",&c[i]);
    }
    for(int i=0;i<n;i++)
        scanf("%lld",&t[i]);
    vector<ll>v1,v2;
    for(int i=0;i<n-1;i++){
        v1.push_back(c[i+1]-c[i]);
        v2.push_back(t[i+1]-t[i]);
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    //cout<<S1<<' '<<S2<<endl;
    if(v1!=v2||c[0]!=t[0]||c[n-1]!=t[n-1]) puts("No");
    else puts("Yes");
    
    return 0;
}
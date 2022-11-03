#include<iomanip>
#include<limits>
#include<thread>
#include<utility>
#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<stack>
#include<queue>
#include<cmath>
#include<numeric>
#include<cassert>
#include<random>
#include<chrono>
#include<unordered_map>
#include<fstream>
#include<list>
#include<functional>
#include<bitset>
#include<complex>
#include<tuple>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pi;
typedef pair<double,double> pd;
typedef pair<double,ll> pdl;
#define F first
#define S second
const ll E=1e18+7;
const ll MOD=1000000007;




int main(){
    ll n;
    cin>>n;
    vector<ll> b(n/2);
    for(auto &i:b){cin>>i;}
    vector<ll> a(n,0);
    a.back()=b[0];
    for(int i=1;i<n/2;i++){
        a[i]=max(a[i-1],b[i]-a[n-i]);
        a[n-i-1]=b[i]-a[i];
    }
    for(int i=0;i<n;i++){
        if(i+1!=n){
            cout<<a[i]<<" ";
        }
        else{
            cout<<a[i];
        }
    }
    cout<<'\n';
    
    
    return 0;
}
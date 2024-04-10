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
    while(n--){
        string s;
        cin>>s;
        bool P=true;
        bool same=true;
        for(int i=0;i<s.size();i++){
            if(s[i]!=s[0]){same=false;}
            if(s[i]!=s[s.size()-1-i]){P=false;}
        }
        if(!P){cout<<s<<'\n';}
        else if(same){cout<<-1<<'\n';}
        else{
            for(int i=1;i<s.size();i++){
                if(s[i]!=s[i-1]){swap(s[i],s[i-1]);}
            }
            cout<<s<<'\n';
        }
    }
    
    
    return 0;
}
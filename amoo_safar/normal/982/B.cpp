#include<iostream>
#include<map>
#include<stack>
#include<algorithm>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef unsigned int ui;
const ll MAXN = 200000;
ll w[MAXN];
map<ll,long> nums;
stack<long> s;
int main(){
    ll n,t=0;
    char c;
    cin >> n ;
    for(long i =0;i<n;i++){
        cin >> w[i];
        nums.insert(pair<ll,long>(w[i],i+1));
    }
    sort(w,w+n);
    //for(long i = 0;i<n;i++) cout << w[i] << " ";
    //cout << endl;
    for(long i = 0;i<2*n;i++){
        cin >> c;
        if(c=='1'){
            cout << s.top() << " ";
            s.pop();
        } else {
            cout << nums.find(w[t])->second<< " ";

            s.push(nums.find(w[t])->second);
            t++;
        }
    }
    return 0;
}
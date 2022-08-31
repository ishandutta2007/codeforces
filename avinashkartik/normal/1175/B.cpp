#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
ll INF = 1e18;
const int N = 3e5+3;

ll a[N],vis[N],ans;
ll n,sum,t,flag;
string s;
stack <ll> st;
ll m = ll(pow(2,32));

int main(){
    cin>>t;
    sum = 1;
    while(t--){
        cin>>s;
        if(s == "for"){
            cin>>n;
            if(st.size()) 
                sum = st.top()*n;
            else
                sum = n; 
            //cout<<sum<<endl;
            st.push(min(sum,m+1));
        }
        else if(s == "end") st.pop();
        else{
            if(st.size())
                ans += st.top();
            else
                ans++;
        }
        //cout<<"Ans : "<<ans<<endl;
        if(ans >= m){cout<<"OVERFLOW!!!"<<endl; exit(0);}
    }
    if(ans >= m) cout<<"OVERFLOW!!!"<<endl;
    else cout<<ans<<endl;
}
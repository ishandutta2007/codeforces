#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define all(x) x.begin(),x.end()

using namespace std;
typedef long long ll;

bool good(ll x) {
    ll c = sqrt(x);
    while (c * c < x) c++;
    while (c * c > x) c--;
    return (c * c == x);
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);    

    int t = 1;

    #ifdef Local
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);                        
        //cin >> t;
    #endif       

    cin >> t;
    
    while(t--) {
       int n;
       cin >> n;
       string s;
       cin >> s;
       ll su = 0, a = 0, c = 0;
       string st;       
       ll mn = 0;
       for (auto i : s) {
           if (i == '(') {
               su++;
           }else su--;
           mn = min(mn, su);
           st += i;
           c++;
           if (su == 0 && mn >= 0) {
               a++;
               c = 0;
               su = 0;
               st.clear();
               mn = 0;
           }
           if (st.size() == 2){
               if (st == "((" || st == "))") {
                   a++;
                   c = 0;
                   su = 0;
                   st.clear();
                   mn = 0;
               } 
           } else if (st.size() > 2 && i == ')') {
               a++;
               c = 0;
               su = 0;
               st.clear();
               mn = 0;
           }           
       }
       cout << a << " " << c << "\n";
    }
    
    return 0;
}
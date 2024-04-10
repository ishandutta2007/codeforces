//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
 
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) name!=""?freopen(name".in","r",stdin),freopen(name".out","w",stdout):0
#define all(a) a.begin(),a.end()
#define len(a) (int)(a.size())
#define elif else if
#define mp make_pair
#define pb push_back
#define fir first
#define sec second
 
using namespace std;
#define int long long
 
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;
 
const int arr=2e5+10;
const int ar=2e3+10;
const ld pi=acos(-1);
const ld eps=1e-10;
const ll md=1e9+7;
const ll inf=1e18+10;
 
///---program start---///

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif
    
    fast;
    
    int n;
    cin>>n;
    vector<pii> vec(n);
    for (int i=0;i<n;i++){
        cin>>vec[i].fir;
    }
    for (int i=0;i<n;i++){
        cin>>vec[i].sec;
    }
    sort(all(vec));
    multiset<int> cur_s;
    int sum_cur=0;
    int last_pos=-1;
    int ans=0;
    for (int i=0;i<len(vec)||!cur_s.empty();){
        if (!cur_s.empty()&&(i==len(vec)||vec[i].fir!=last_pos)){
            sum_cur-=*(--cur_s.end());
            cur_s.erase((--cur_s.end()));
            ans+=sum_cur;
            last_pos++;
            continue;
        }
        multiset<int> ms;
        int sum_ms=0;
        
        int j=i-1;
        while (j+1<len(vec)&&vec[j+1].fir==vec[i].fir){
            ms.insert(vec[j+1].sec);
            sum_ms+=vec[j+1].sec;
            j++;
        }
        
        if (len(cur_s)<len(ms)){
            cur_s.swap(ms);
            swap(sum_cur,sum_ms);
        }
        for (auto k:ms){
            cur_s.insert(k);
        }
        sum_cur+=sum_ms;
        
        // cout<<i<<" "<<vec[i].fir<<" "<<vec[i].sec<<"\n";
        // cout<<"sum :: "<<sum_cur<<"\n";
        
        if (!cur_s.empty()){
            sum_cur-=*(--cur_s.end());
            cur_s.erase((--cur_s.end()));
            ans+=sum_cur;
            last_pos=vec[i].fir+1;
        }
        // cout<<"sum_after :: "<<sum_cur<<"\n";
        
        // cout<<"ans :: "<<ans<<"\n";
        
        i=j+1;
    }
    
    cout<<ans<<"\n";
}
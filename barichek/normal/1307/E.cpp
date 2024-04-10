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
///#define int long long
 
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

#define ar (int)(5000+10)
 
void inc(int& a,int b)
{
    a+=b;
    if (a>=md){
        a-=md;
    }
}
 
int mult(int a,int b)
{
    return 1ll*a*b%md;
}
 
int mult_unsafe(int a,int b)
{
    return a*b;
}
 
void upd(pii& a,pii b)
{
    if (a.fir==b.fir){
        inc(a.sec,b.sec);
    }
    else if (a.fir<b.fir){
        a=b;
    }
}
 
vi vh[ar];
 
int cnt[ar];
 
vector<pii> H[ar];
 
main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif
    
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        int s;
        cin>>s;
        vh[s].pb(i);
    }
    for (int i=1;i<=m;i++){
        int f,h;
        cin>>f>>h;
        if (len(vh[f])>=h){
            H[f].pb(mp(vh[f][h-1],n-vh[f][len(vh[f])-h]+1));
        }
    }
    
    pii ans=mp(-1, 0);
    
    for (int max_left=0;max_left<=n;max_left++){
        // cout<<"max_left :: "<<max_left<<"\n";
        
        int max_right=n-max_left;
        pii cur_ans=mp(0, 1);
        bool find_answer=(max_left==0);
        for (int i=1;i<=n;i++){
            // cout<<"i :: "<<i<<"\n";
            int cnt_left=0;
            int cnt_right=0;
            int cnt_both=0;
            bool find_here = 0;
            for (auto q:H[i]){
                if (q.fir == max_left){
                    find_answer = 1;
                    find_here = 1;
                    continue;
                }
                
                if (q.fir<=max_left&&q.sec<=max_right){
                    cnt_both++;
                }
                else if (q.fir<=max_left){
                    cnt_left++;
                }
                else if (q.sec<=max_right){
                    cnt_right++;
                }
            }
            
            // cout<<"cnt :: \n";
            // cout<<"cnt_both :: "<<cnt_both<<"\n";
            // cout<<"cnt_left :: "<<cnt_left<<"\n";
            // cout<<"cnt_right :: "<<cnt_right<<"\n";
            
            int wanted = 0;
            if ((cnt_both>=2) || (cnt_both&&(cnt_left||find_here)) || (cnt_both&&cnt_right) || ((cnt_left||find_here)&&cnt_right) ){
                wanted=2;
            }
            elif (cnt_both || find_here || cnt_left || cnt_right){
                wanted = 1;
            }
            cur_ans.fir+=wanted;
            int sum=0;
            for (int k1=0;k1<2;k1++){ /// both to left
                for (int k2=0;k1+k2<2;k2++){ /// left
                    for (int k3=0;k3<2;k3++){ /// both to right
                        for (int k4=0;k3+k4<2;k4++){ /// right
                            if (k1+k2 && find_here) {
                                continue;
                            }
                            if (k1+k3>cnt_both){
                                continue;
                            }
                            int geted = k1+k2+k3+k4+find_here;
                            
                            if (geted!=wanted){
                                continue;
                            }
                            
                            ll ways=1;
                            if (k1 && k3){
                                ways=1ll*ways*cnt_both;
                                ways=1ll*ways*(cnt_both-1);
                            }
                            else if (k1||k3){
                                ways=1ll*ways*cnt_both;
                            }
                            
                            if (k2){
                                ways=1ll*ways*cnt_left;
                            }
                            if (k4){
                                ways=1ll*ways*cnt_right;
                            }
                            inc(sum,(ways>=md?ways%md:ways));
                        }
                    }
                }
            }
            // cout<<"sum :: "<<sum<<"\n";
            cur_ans.sec=mult(cur_ans.sec,sum);
        }
        
        // cout<<"find_answer :: "<<find_answer<<"\n";
        // cout<<"cur_ans :: "<<cur_ans.fir<<" "<<cur_ans.sec<<"\n";
        
        if (find_answer&&cur_ans.sec){
            upd(ans,cur_ans);
        }
    }
    
    cout<<ans.fir<<" "<<ans.sec<<"\n";
}
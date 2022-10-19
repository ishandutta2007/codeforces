#include<bits/stdc++.h>

#define st first
#define nd second
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a, b)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

using namespace std;

///~~~~~~~~~~~~~~~~~~~~~~~~~~

void debug(){cerr<<"\n";}
template <typename H, typename... T>
void debug(H h, T... t) {cerr<<h; if (sizeof...(t)) cerr << ", "; debug(t...);}
#define deb(x...) cerr<<#x<<" = ";debug(x);

///~~~~~~~~~~~~~~~~~~~~~~~~~

typedef long long ll;
//typedef long double ld;
typedef vector<int> vi;
typedef vector<pair<int, int> > vii;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N=1e6+5, INF=1e9, mod=1e9+7;
int A[N], B[N];int n;
int p, q, f, s;
bool check(int k){
    int rn=0, ln=INF, rb=0, lb=INF, rd=-INF, ld=INF;
    for(int i=0; i<n; i++){
        ln=min(ln, A[i]+k);
        rn=max(rn, A[i]-k);
        lb=min(lb, B[i]+k);
        rb=max(rb, B[i]-k);
        rd=max(rd, A[i]-B[i]-k);
        ld=min(ld, A[i]-B[i]+k);
    }
    //cout<<k<<"\n";
    //cout<<rn<<" "<<ln<<"\n"<<rb<<" "<<lb<<"\n"<<rd<<" "<<ld<<"\n\n";
    if(rd>ld || rn>ln || rb>lb)return 0;
    if(ln-rb<rd || rn-lb>ld)return 0;

    p=rn;
    q=rb;
    if(p-q>ld)q+=p-q-ld;
    else if(p-q<rd) p+=rd+q-p;
    //cout<<p<<" "<<q<<"\n\n";
    if(p==q && q==0){
        if(p<ln && p-q<ld)p++;
        else if(q<lb && p-q>rd)q++;
        if(p<ln && q<lb){p++; q++;}
        else return 0;
    }
    //cout<<p<<" "<<q<<"\n\n";
    f=p;
    s=q;
    //cout<<k<<" "<<
    return 1;
}
int main(){

    cin>>n;

    for(int i=0; i<n; i++){
        string t;
        cin>>t;
        //int a=0, b=0;
        for(int j=0; j<t.size(); j++){
            if(t[j]=='N')A[i]++;
            else B[i]++;
        }

        //cout<<a<<" "<<b<<"\n";
    }
    int l=0, r=N;
    while(l<r){
        int m=(l+r)/2;
        if(check(m))r=m;
        else l=m+1;
    }
    cout<<l<<"\n";
    //cout<<f<<" "<<s<<"\n";
    for(int i=0; i<f; i++)cout<<"N";
    for(int i=0; i<s; i++)cout<<"B";
}
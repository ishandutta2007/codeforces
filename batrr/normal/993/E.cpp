// Tima the best
#include <bits/stdc++.h>

#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define IOS ios_base::sync_with_stdio(0);
using namespace std;                    
typedef complex < double > base ;
const ll maxn=2e5+123,inf=1e18,mod=1e9+7;
const double PI=acos(-1.0);
int n,x,a[maxn];
ll pre[maxn],suf[maxn],ans[maxn];

void FFT( vector< base >    &a, bool invert){
    int n=a.size();
    if( n==1 )
        return ;
    
    vector< base > a0(n/2),a1(n/2);
    
    for(int i=0;i<n;i++)
        if(i&1)         
            a1[i/2]=a[i];
        else
            a0[i/2]=a[i];
                
    FFT(a0,invert);
    FFT(a1,invert);
    
    double ang = (2*PI)/n;
    if(invert)
        ang*=-1;
    base nroot = base(cos(ang), sin(ang));
    base w = base(1.0);
    
    for (int i=0; i<n/2; ++i) {
        a[i] = a0[i] + w*a1[i];
        a[i+n/2] = a0[i] - w*a1[i];
        if(invert)
            a[i]/=2, a[i+n/2]/=2;
        w*=nroot;
    }

}
void mult(vector<ll> &a,vector<ll> &b,vector<ll> &res){
    
    vector< base >fa(a.begin(),a.end());
    vector< base >fb(b.begin(),b.end());
    int n=1;
    while( n < a.size()+b.size()-1 )
        n*=2;          
    fa.resize(n);
    fb.resize(n);
    res.resize(n);
    FFT(fa,0);
    FFT(fb,0);
    
    for(int i=0;i<n;i++)
        fa[i]*=fb[i];
    
    FFT(fa,1);
    
    for(int i=0;i<n;i++)
        res[i]=(ll)( fa[i].real() +0.5 );
    
}
int main(){
    #ifdef LOCAL
        freopen ("test.in", "r", stdin);
    #endif                                     
    scanf("%d%d",&n,&x);
    
    
    for(int i=1;i<=n;i++){
        scanf("%d ",&a[i]);
        //cout<<a[i]<<" "<<x<<endl;
        if(a[i]<x)
            a[i]=1;
        else
            a[i]=0;              
        //cout<<a[i]<<" ";
    }                        
    for(int i=1;i<=n;i++)
        pre[i]=pre[i-1]+a[i];
    for(int i=n;i>=1;i--)
        suf[i]=suf[i+1]+a[i];
    
    vector<ll> pol1( n+1, 0),pol2(n+1,0),res;
    for(int i=1;i<=n;i++){
        pol1[pre[i]]++;
        pol2[suf[i]]++;
    }
    mult(pol1,pol2,res);              
    for(int i=0;i<res.size();i++)
        if( pre[n]>i && i!=0)
            ans[pre[n]-i]+=res[i];   
            
    for(int i=1;i<=n;i++)
        if(pre[i]!=0 && pre[i]!=pre[n])
            ans[pre[i]]++;
    for(int i=1;i<=n;i++)
        if(suf[i]!=0 && suf[i]!=suf[1])
            ans[suf[i]]++;
    
    for(ll i=1,j=1;i<=n;){
        while(j<=n && a[i]==a[j])
            j++;    
        if(a[i]==0) 
            ans[0]+=(j-i)*(j-i+1)/2;
        i=j;
    }
    if(pre[n]>0){
        ll l=0,r=n;
        while(a[l]==0)
            l++;
        while(a[r]==0)
            r--;
        ans[pre[n]]+=l*(n-r+1);
    }    

    for(int i=0;i<=n;i++)   
        printf("%lld ",ans[i]);
}
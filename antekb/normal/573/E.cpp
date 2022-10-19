#include<bits/stdc++.h>
#define st first
#define nd second
using namespace std;
const int N=1005;
typedef long double ld;
ld INF=1e18;
ld sect(int A1, long long B1, int A2, long long B2){
    if(A1==A2){if(B1<=B2) return -INF; else return INF;}
    ld x=B1-B2;
    x/=(A2-A1);
    return x;
}
struct kub{
    int siz, X=0, wsk;
    long long B0=0;
    vector<int> A, kol;
    vector<long long> B;
    vector<pair<int, ld> > hull;
    vector<bool> uzy;
    kub(int _siz=0){siz=_siz;}
    void init(){
        //cout<<"a";
        wsk=0;
        for(int i:kol){
            //cout<<i<<" ";
            if(uzy[i])continue;
            int czy=1;
            ld t=-INF;
            while(hull.size()){
                int j=hull.back().st;
                t=sect(A[j], B[j], A[i], B[i]);
                if(t==INF){czy=0;break;}
                if(t<hull.back().nd)hull.pop_back();
                else break;
            }
            if(czy)hull.push_back({i, t});
        }
    }
    long long get(){
        if(hull.empty())return -INF;
        while(hull[wsk].nd<X && wsk<hull.size())wsk++;
        wsk--;
        int k=hull[wsk].st;
        //cout<<"\n"<<k<<" "<<X<<" "<<A[k]<<" "<<B[k]<<" "<<B0<<"\n";
        return A[k]*(long long)X+B[k]+B0;
    }
    int update(){
        int k=hull[wsk].st;
        uzy[k]=1;
        for(int i=0; i<k; i++){
            B[i]+=A[k];
        }
        for(int i=k+1; i<siz; i++)B[i]+=A[i];
        hull.clear();
        init();
        return A[k];
    }
};
vector<kub> H;
int i;
int main(){
    int n;
    cin>>n;
    vector<int> V(n);
    for(i=0; i<n; i++)cin>>V[i];
    for(i=0; i<=n/N; i++){
        H.push_back(kub());
        H[i].X=1;
        for(int j=i*N; j<n && j<(i+1)*N; j++){
            H[i].siz++;
            H[i].A.push_back(V[j]);
            H[i].kol.push_back(j-i*N);
        }
        H[i].uzy.resize(H[i].siz);
        H[i].B.resize(H[i].siz);
        sort(H[i].kol.begin(), H[i].kol.end(), [](int a, int b){return H[i].A[a]<H[i].A[b];});
        H[i].init();
    }
    //cout<<"a";
    //cout<<INF;
    long long ans=0;
    for(i=0; i<n; i++){
        long long maks=-INF;
        int id=-1;
        for(int j=0; j<H.size(); j++){
            long long t=H[j].get();
            if(t>maks){
                id=j;
                maks=t;
            }
        }
        if(maks<0){
            cout<<ans;
            return 0;
        }
        ans+=maks;
        //cout<<ans<<" ";
        //cout<<id<<"\n";
        int t=H[id].update();
        for(int j=0; j<id; j++)H[j].B0+=t;
        for(int j=id+1; j<H.size(); j++)H[j].X++;
    }
    cout<<ans;
}
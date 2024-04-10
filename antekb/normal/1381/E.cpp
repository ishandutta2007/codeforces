#include<bits/stdc++.h>
#define st first
#define nd second
using namespace std;
const int N=1e5+5;
typedef long double ld;
struct quad{
    ld A, B, C;
    quad(ld _A=0, ld _B=0, ld _C=0){A=_A; B=_B; C=_C;}
    ld eval(ld x){
        return x*A*x+B*x+C;
    }
    void operator+=(quad Q){
        A+=Q.A;
        B+=Q.B;
        C+=Q.C;
    }
    quad operator-(quad Q){
        return quad(A-Q.A, B-Q.B, C-Q.C);
    }
    quad operator*(ld t){
        return quad(A*t, B*t, C*t);
    }
};
struct line{
    ld x1, x2, H;
    int t;
    line(ld _x1, ld _x2, ld _H, int _t){x1=min(_x1, _x2); x2=max(_x1, _x2); H=_H;t=_t;}
    quad pol1(){
        if(x1==x2)return quad();
        return quad(1, -2*x1, x1*x1)*(H/(2*(x2-x1)))*t;
    }
    quad pol2(){
        return quad(0, 2, -x1-x2)*(H/2)*t;
    }
};
vector<pair<int, int> > pts;
ld proj(int k, int l, ld Y){
    if(Y==pts[k].nd)return pts[k].st;
    if(Y==pts[l].nd)return pts[l].st;
    if(pts[k].nd==pts[l].nd)return pts[k].nd;
    return pts[l].st+(pts[k].st-pts[l].st)*(Y-pts[l].nd)/(ld)(pts[k].nd-pts[l].nd);
}
ld res[N];
int main(){
    int n, q;
    cin>>n>>q;
    pts.resize(n);
    int miny=1e9, id;
    set<int> S;
    for(int i=0; i<n; i++){
        cin>>pts[i].st>>pts[i].nd;
        S.insert(pts[i].nd);
        if(pts[i].nd<miny){
            miny=pts[i].nd;
            id=i;
        }
    }
    int l1=id, r1=id, l2=(id+n-1)%n, r2=(id+1)%n;
    vector<line> V;
    ld ans=0;
    int prev=miny;
    S.erase(S.begin());
    for(auto it : S){
        if((it)>pts[l2].nd){
            l1=l2;
            l2=(l2+n-1)%n;
        }
        if((it)>pts[r2].nd){
            r1=r2;
            r2=(r2+1)%n;
        }
        ld R1=proj(r1, r2, prev), R2=proj(r1, r2, it), L1=proj(l1, l2, prev), L2=proj(l1, l2, it), h=it-prev;
        //cout<<fixed<<setprecision(5)<<it<<" "<<prev<<"\n"<<R1<<" "<<R2<<" "<<L1<<" "<<L2<<"\n";
        V.push_back(line(R1, R2, h, -1));
        V.push_back(line((R1+L1)/2, (R2+L2)/2, h, 2));
        //if(R1+L1==2)cout<<"a";
        V.push_back(line(L1, L2, h, -1));
        ans+=abs(h*(L1-R1+L2-R2)/2);
        //cout<<h/2*(L1-R1+L2-R2)<<"\n";
        prev=it;
    }
    /*cout<<"\n\n";
    for(auto i:V){
        cout<<i.x1<<" "<<i.x2<<" "<<i.H<<" "<<i.t<<"\n";
    }
    cout<<ans;
    cout<<"\n\n";*/
    vector<pair<ld, pair<int, quad>>> V2;
    for(int i=0; i<q; i++){
        int k;
        cin>>k;
        V2.push_back({k, {i, quad()}});
    }
    for(line i:V){
        //if(i.x1!=i.x2){
            quad f=i.pol1();
            V2.push_back({i.x1, {-1, f}});
            //V2.push_back({i.x2, {-1, }});
            /*if(i.x1==i.x2){cout<<f.A<<f.B<<f.C<<" "<<(f*(-1)).A<<(f*(-1)).B<<(f*(-1)).C<<"\n";
            cout<<i.x1<<" "<<i.x2<<" "<<i.H<<" "<<i.t<<"\n";
            }*/

        V2.push_back({i.x2, {-1, i.pol2()-f}});
    }
    sort(V2.begin(), V2.end(), [](pair<ld, pair<int, quad>> a, pair<ld, pair<int, quad>> b){return a.st<b.st;});
    quad fun;
    //cout<<"\n\n";
    for(auto i:V2){
        /*if(i.st<=0){cout<<fixed<<setprecision(5)<<fun.A<<" "<<fun.B<<" "<<fun.C<<"\n";
            cout<<fixed<<setprecision(5)<<i.nd.nd.A<<" "<<i.nd.nd.B<<" "<<i.nd.nd.C<<"\n\n";
        }
        cout<<i.st<<"\n";*/
        if(i.nd.st==-1)fun+=i.nd.nd;
        else{ res[i.nd.st]=ans+fun.eval(i.st);}
    }
    for(int i=0; i<q; i++){
        cout<<fixed<<setprecision(10)<<res[i]<<"\n";
    }
}
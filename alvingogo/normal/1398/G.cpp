#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

typedef complex<double> cd;
struct FFT{
    const double pi=acos(-1);
    int bd,lgbd;
    vector<int> rvb;
    vector<cd> w;
    void rev(){
        rvb.resize(bd);
        int hbt=-1;
        for(int i=1;i<bd;i++){
            if(!(i&(i-1))){
                hbt++;
            }
            rvb[i]=rvb[i^(1<<(hbt))]|(1<<(lgbd-hbt-1));
        }
    }
    void calc(){
        w.resize(bd+1);
        w[0]=1;
        for(int i=1;i<=bd;i++){
            w[i]=cd(cos(2*pi/bd*i),sin(2*pi/bd*i));
        }
    }
    void dft(vector<cd> &a,bool flag){
        for(int i=0;i<bd;i++){
            if(i<rvb[i]){
                swap(a[i],a[rvb[i]]);
            }
        }
        cd e,f;
        for(int l=1;l<bd;l<<=1){
            for(int g=0;g<bd;g+=2*l){
                for(int i=0;i<l;i++){
                    e=a[g+i];
                    if(flag){
                        f=a[g+i+l]*conj(w[bd/l/2*i]);
                    }
                    else{
                        f=a[g+i+l]*w[bd/l/2*i];
                    }
                    a[g+i]=e+f;
                    a[g+i+l]=e-f;
                }
            }
        }
        if(flag){
            for(int i=0;i<bd;i++){
                a[i]/=bd;
            }
        }
    }
    void mul(vector<int> &a,vector<int> &b,vector<int> &c){
        lgbd=0;
        while((1<<lgbd)<a.size() || (1<<lgbd)<b.size()){
            lgbd++;
        }
        lgbd++;
        bd=(1<<lgbd);
        rev();
        calc();
        vector<cd> tmpa(bd),tmpb(bd);
        for(int i=0;i<a.size();i++){
            tmpa[i]=cd(a[i],0);
        }
        for(int i=0;i<b.size();i++){
            tmpb[i]=cd(b[i],0);
        }
        for(int i=a.size();i<bd;i++){
            tmpa[i]=cd(0,0);
        }
        for(int i=b.size();i<bd;i++){
            tmpb[i]=cd(0,0);
        }
        dft(tmpa,0);
        dft(tmpb,0);
        for(int i=0;i<bd;i++){
            tmpa[i]*=tmpb[i];
        }
        dft(tmpa,1);
        c.resize(bd);
        for(int i=0;i<bd;i++){
            c[i]=(int)(tmpa[i].real()+0.5);
        }
    }
};

int main(){
    AquA;
    int n,x,y;
    cin >> n >> x >> y;
    vector<int> a(x+1),b(x+1);
    for(int i=0;i<n+1;i++){
        int c;
        cin >> c;
        a[c]++;
        b[x-c]++;
    }
    FFT fft;
    vector<int> c;
    fft.mul(a,b,c);
    vector<int> ab(1e6+7);
    for(int i=x+1;i<c.size();i++){
        if(c[i]){
            ab[2*(i-x+y)]=2*(i-x+y);
        }
    }
    for(int i=2;i<ab.size();i+=2){
        if(ab[i]){
            for(int j=i;j<ab.size();j+=i){
                ab[j]=max(ab[i],ab[j]);
            }
        }
    }
    int q;
    cin >> q;
    for(int i=0;i<q;i++){
        int z;
        cin >> z;
        if(ab[z]){
            cout << ab[z] << " ";
        }
        else{
            cout << -1 << " ";
        }
    }
    cout << "\n";
    return 0;
}